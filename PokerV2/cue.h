#if !defined(CUE_H__)
#define CUE_H__
#include <iostream>
#include <vector>
#include "card.h"
//#include "Player.h"



using namespace std;

class CUE: public vector<const Card*>
{
public:
	enum HandType
	{
		_HIGHCARD, _ONEPAIR, _TWOPAIR, _THREEKIND, _WHEELSTRAIGHT, _STRAIGHT, _FLUSH, _FULLHOUSE, _FOURKIND, _STRFLUSH
	};

	const static string HAND_TYPE[];
	CUE(vector<const Card*> cards);
	~CUE();
};
























#endif

