#include "cue.h"
#include <algorithm>



//const string CUE::HAND_TYPE[] =
//{
//	"High Card", "One Pair", "Two Pair", "Three-a-kind", "Wheel Straight", "Straight", "Flush", "Full House", "Four-o-Kind", "Straight Flush"
//};

CUE::CUE(vector<const Card*> cards) 
{
	try{
		if (cards.size() == 5)
		{
			cout << "\nBEFORE SORT: ";
			for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
			{
				const Card* p = *c_it;
				cout << " " << p->ToString() << " ";
			}
			
			sort(cards.begin(), cards.end(), HigherCard());
			cout << "  AFTER SORT: ";
			for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
			{
				const Card* p = *c_it;
				cout << " " << p->ToString() << " ";
			}
			cout << " \n";
			
		}
		else
			throw CUEException("NOT 5 CARDS IN CUE");
	}
	catch (CUEException ex)
	{
		cout << ex.what() << endl;
	}
}


CUE::~CUE()
{
}


