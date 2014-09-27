#if !defined(PLAYER_H__)
#define PLAYER_H__
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include "card.h"
#include "cue.h"

using namespace std;

class Player
{
public:
	vector<const Card*> Sort(vector<const Card*> cards);

	virtual string GetCUEName(const CUE& c);
	virtual void ShowBestHand(vector<const Card*>& c);
	virtual void AddToHand(const Card*) = 0;
	virtual const CUE& GetBestCUE()= 0;
	virtual void ShowCards() = 0;
	virtual void GetHandName() = 0;
	virtual void Show(vector<const Card*>& cards) const;
	virtual ~Player(){};

};


class DrawPlayer : public Player
{
public:
	DrawPlayer(){};
	virtual void AddToHand(const Card*);
	virtual const CUE& GetBestCUE();  //  ----v
// THIS will have to create all the cues and run through assigning the best cue to m_Hand..not so hard for this type of player but the rest it will be.
	virtual string GetCUEName(const CUE& c);
	virtual void ShowBestHand(vector<const Card*>& c);
	virtual void GetHandName();
	virtual void ShowCards();
	virtual ~DrawPlayer(){};
private:
	vector<CUE> m_Cues;
	vector<const Card*> m_Hand;
	string m_HandName;
};


class StudPlayer : public Player
{
public:
	StudPlayer(){};
	virtual void AddToHand(const Card*);
	virtual const CUE& GetBestCUE();
	virtual void GetHandName();
	virtual string GetCUEName(const CUE& c);
	virtual void ShowCards();
	virtual ~StudPlayer(){};
private:
	vector<const Card*> m_Hand;
	vector<CUE> m_Cues;
	string m_HandName;
};

class OmahaPlayer : public Player
{
public:
	OmahaPlayer(){};
	virtual void AddToHand(const Card*);
	virtual string GetCUEName(const CUE& c);
	virtual const CUE& GetBestCUE();
	virtual void ShowCards();
	virtual void GetHandName();
	virtual ~OmahaPlayer(){};
private:
	vector<const Card*> m_Hand;
	string m_HandName;
	vector<CUE> m_Cues;
};

class TexasPlayer : public Player
{
public:
	TexasPlayer(){};
	virtual void AddToHand(const Card*);
	virtual const CUE& GetBestCUE();
	virtual string GetCUEName(const CUE& c);
	virtual void ShowCards();
	virtual void GetHandName();
	virtual ~TexasPlayer(){};
private:
	vector<const Card*> m_Hand;
	vector<CUE> m_Cues;
	string m_HandName;
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