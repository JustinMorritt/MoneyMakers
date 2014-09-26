#if !defined(CUE_H__)
#define CUE_H__
#include <iostream>
#include <vector>
#include "card.h"



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



class HigherCard
{
public:
	bool operator()(const Card* c1, const Card* c2) const
	{
		return c1->GetPip() < c2->GetPip();
	}
};








class CUEException : public logic_error
{
public:
	CUEException(const char* r) : std::logic_error(r){};
};


//USE THE STUFF BELOW IF YOU ARE GOING TO THROW IN A CUSTOM EXCEPTION SOMEWHERE
//REMEMBER TO USE throw PlayerException("\n  ERROR MESSAGE IN HERE  \n");

/*
try{

}
catch (PlayerException ex)
{
cout << ex.what() << endl;
}*/















#endif

