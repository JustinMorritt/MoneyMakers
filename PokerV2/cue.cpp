#include "cue.h"
#include <algorithm>

CUE::CUE(vector<const Card*> cards) 
{
	try{
		if (cards.size() == 5)
		{
			cout << "\nBEFORE SORT : ";
			for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
			{
				const Card* p = *c_it;
				cout << " " << p->ToString() << " ";
			}
			
			sort(cards.begin(), cards.end(), HigherCard());
			cout << "\nAFTER SORT  : ";
			for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
			{
				const Card* p = *c_it;
				cout << " " << p->ToString() << " ";
			}
			
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


