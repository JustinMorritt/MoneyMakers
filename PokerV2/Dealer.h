#if !defined(DEALER_H__)
#define DEALER_H__
#include <vector>
#include <iostream>
#include "card.h"
#include "deal.h"



using namespace std;

class Dealer
{
public:

	virtual const Card* deal() = 0;
	virtual const Card* burn() = 0;
	virtual ~Dealer();
};

class DrawDealer : public Dealer
{
public:
	DrawDealer(int players);
	virtual const Card* deal();
	virtual const Card* burn();
	virtual ~DrawDealer();
private:
	int _players;
	Deal* m_DealerCards;
};

class StudDealer : public Dealer
{
public:

	StudDealer(int players);
	virtual const Card* deal();
	virtual const Card* burn();
	virtual ~StudDealer();
private:
	int _players;
	Deal* m_DealerCards;
};

class OmahaDealer : public Dealer
{
public:
	OmahaDealer(int players);
	virtual const Card* deal();
	virtual const Card* burn();
	virtual ~OmahaDealer();
private:
	int _players;
	Deal* m_DealerCards;
};

class TexasDealer : public Dealer
{
public:
	TexasDealer(int players);
	virtual const Card* deal();
	virtual const Card* burn();
	virtual ~TexasDealer();
private:
	int _players;
	Deal* m_DealerCards;
};




#endif