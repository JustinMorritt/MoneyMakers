#if !defined(DEALER_H__)
#define DEALER_H__
#include <vector>
#include <iostream>
#include "card.h"



using namespace std;

class Dealer
{
public:

	virtual void deal() = 0;
	virtual ~Dealer();
};

class DrawDealer : public Dealer
{
public:
	DrawDealer(int players);
	virtual void deal();
	virtual ~DrawDealer();
private:
	int _players;
	vector<const Card*> m_cards;
};

class StudDealer : public Dealer
{
public:

	StudDealer(int players);
	virtual void deal();
	virtual ~StudDealer();
private:
	int _players;
	vector<const Card*> m_cards;
};

class OmahaDealer : public Dealer
{
public:
	OmahaDealer(int players);
	virtual void deal();
	virtual ~OmahaDealer();
private:
	int _players;
	vector<const Card*> m_cards;
};

class TexasDealer : public Dealer
{
public:
	TexasDealer(int players);
	virtual void deal();
	virtual ~TexasDealer();
private:
	int _players;
	vector<const Card*> m_cards;
};




#endif