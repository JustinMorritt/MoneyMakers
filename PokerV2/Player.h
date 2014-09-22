#if !defined(PLAYER_H__)
#define PLAYER_H__
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Player
{
public:
	vector<const Card*> Sort(vector<const Card*> cards);

	virtual void AddToHand(const Card*) = 0;
	virtual void SortHand() = 0;
	virtual void ShowCards() = 0;
	virtual void Show(vector<const Card*>& cards) const;
	virtual ~Player(){};
};


class DrawPlayer : public Player
{
public:
	DrawPlayer(){};
	virtual void AddToHand(const Card*);
	void GetBestHand();
	virtual void SortHand();
	virtual void ShowCards();
	virtual ~DrawPlayer(){};
private:
	vector<const Card*> m_Hand;
	string m_HandName;

};


class StudPlayer : public Player
{
public:
	StudPlayer(){};
	virtual void AddToHand(const Card*);
	void GetBestHand();
	virtual void SortHand();
	virtual void ShowCards();
	virtual ~StudPlayer(){};
private:
	vector<const Card*> m_Hand;
	string m_HandName;
};

class OmahaPlayer : public Player
{
public:
	OmahaPlayer(){};
	virtual void AddToHand(const Card*);
	void GetBestHand();
	virtual void ShowCards();
	virtual void SortHand();
	virtual ~OmahaPlayer(){};
private:
	vector<const Card*> m_Hand;
	string m_HandName;

};

class TexasPlayer : public Player
{
public:
	TexasPlayer(){};
	virtual void AddToHand(const Card*);
	void GetBestHand();
	virtual void ShowCards();
	virtual void SortHand();
	virtual ~TexasPlayer(){};
private:
	vector<const Card*> m_Hand;
	string m_HandName;

};




#endif