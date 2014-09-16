#if !defined(PLAYER_H__)
#define PLAYER_H__
#include <vector>
#include "card.h"

using namespace std;

class Player
{
public:

	virtual void play() = 0;
	virtual ~Player();
};


class DrawPlayer : public Player
{
public:
	DrawPlayer();
	virtual void deal();
	virtual ~DrawPlayer();
private:
	vector<const Card*> m_cards;
};


class StudPlayer : public Player
{
public:

	StudPlayer();
	virtual void play();
	virtual ~StudPlayer();
private:
	vector<const Card*> m_cards;
};

class OmahaPlayer : public Player
{
public:
	OmahaPlayer();
	virtual void deal();
	virtual ~OmahaPlayer();
private:
	vector<const Card*> m_cards;
};

class TexasPlayer : public Player
{
public:
	TexasPlayer();
	virtual void deal();
	virtual ~TexasPlayer();
private:
	vector<const Card*> m_cards;
};




#endif