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
	virtual void ShowBestHand(const CUE& c);
	virtual void AddToHand(const Card*) = 0;
	virtual vector<CUE> BuildCUEs() = 0;
	virtual CUE& GetBestCUE() = 0;
	virtual void ShowCards() = 0;
	virtual void GetComCards(vector<const Card*> cards) = 0;
	virtual void GetHandName() = 0;
	virtual void Show(vector<const Card*>& cards) const;
	virtual ~Player(){};

};


class DrawPlayer : public Player
{
public:
	DrawPlayer(){};
	virtual void AddToHand(const Card*);
	virtual vector<CUE> BuildCUEs();
	virtual CUE& GetBestCUE();  
	virtual string GetCUEName(const CUE& c);
	virtual void ShowBestCue(const CUE& c);
	virtual void GetHandName();
	virtual void ShowCards();
	virtual ~DrawPlayer(){};
	virtual void GetComCards(vector<const Card*> cards);
private:
	vector<const Card*> m_Hand;
	vector<CUE> m_Cues;
	CUE _bestCUE;
	string m_HandName;
	int _evaluator;
};


class StudPlayer : public Player
{
public:
	StudPlayer(){};
	virtual void AddToHand(const Card*);
	virtual vector<CUE> BuildCUEs();
	virtual CUE& GetBestCUE();
	virtual void GetHandName();
	virtual void ShowBestCue(const CUE& c);
	virtual string GetCUEName(const CUE& c);
	virtual void ShowCards();
	virtual ~StudPlayer(){};
	virtual void GetComCards(vector<const Card*> cards);
private:
	vector<const Card*> m_Hand;
	CUE _bestCUE;
	vector<CUE> m_Cues;
	string m_HandName;
	int _evaluator;
};

class OmahaPlayer : public Player
{
public:
	OmahaPlayer(){};
	virtual void AddToHand(const Card*);
	virtual vector<CUE> BuildCUEs();
	virtual string GetCUEName(const CUE& c);
	virtual CUE& GetBestCUE();
	virtual void ShowBestCue(const CUE& c);

	virtual void GetComCards(vector<const Card*> cards);

	virtual void ShowCards();
	virtual void GetHandName();
	virtual ~OmahaPlayer(){};
private:
	vector<const Card*> m_CommunityCards;
	vector<const Card*> m_Hand;
	CUE _bestCUE;
	string m_HandName;
	vector<CUE> m_Cues;
	int _evaluator;
};

class TexasPlayer : public Player
{
public:
	TexasPlayer(){};
	virtual void AddToHand(const Card*); 
	virtual vector<CUE> BuildCUEs();
	virtual CUE& GetBestCUE();
	virtual string GetCUEName(const CUE& c);
	virtual void ShowBestCue(const CUE& c);

	virtual void GetComCards(vector<const Card*> cards);

	virtual void ShowCards();
	virtual void GetHandName();
	virtual ~TexasPlayer(){};
private:
	vector<const Card*> m_CommunityCards;
	vector<const Card*> m_Hand;
	vector<CUE> m_Cues;
	CUE _bestCUE;
	string m_HandName;
	int _evaluator;
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