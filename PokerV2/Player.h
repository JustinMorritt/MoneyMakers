#if !defined(PLAYER_H__)
#define PLAYER_H__
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class Player
{
public:

	virtual void ShowCards() = 0;
	virtual ~Player();

};


class DrawPlayer : public Player
{
public:
	DrawPlayer();
	virtual void ShowCards();
	virtual ~DrawPlayer();
private:
	vector<const Card*> m_cards;
};


class StudPlayer : public Player
{
public:

	StudPlayer();
	virtual void ShowCards();
	virtual ~StudPlayer();
private:
	vector<const Card*> m_cards;
};

class OmahaPlayer : public Player
{
public:
	OmahaPlayer();
	virtual void ShowCards();
	virtual ~OmahaPlayer();
private:
	vector<const Card*> m_cards;
};

class TexasPlayer : public Player
{
public:
	TexasPlayer(){};
	virtual void ShowCards(){
		std::cout << "played ..." << std::endl;
	};
	virtual ~TexasPlayer(){};
private:
	vector<const Card*> m_cards;
};




#endif