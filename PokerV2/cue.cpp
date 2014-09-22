#include "cue.h"
#include <algorithm>

CUE::CUE(vector<const Card*> cards)
{
	try{
		if (cards.size() == 5)
		{
			sort(cards.begin(), cards.end(), HigherCard());
			m_CUECards = cards;
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


