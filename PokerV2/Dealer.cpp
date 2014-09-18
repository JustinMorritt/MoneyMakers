#include <vector>
#include "Dealer.h"
#include "deal.h"
#include "card.h"
#include "Table.h"

//CONSTRUCTORS
TexasDealer::TexasDealer(int players)
{
	const int MAXCARDS = 2;
	m_DealerCards = new Deal;
	_players = players;
	cout << "Made Texas Hold'em Dealer \n";
};

OmahaDealer::OmahaDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	cout << "Made Ohmaha High Dealer\n";
};

DrawDealer::DrawDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	cout << "Made 5 Card Draw Dealer \n";
};

StudDealer::StudDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	cout << "Made a 7 Card Stud Dealer \n";
};




const Card* TexasDealer::deal()
{
	const Card* ret = m_DealerCards->OneCard();
	//cout << "Dealt a card.\n";
	return ret;
};

const Card* DrawDealer::deal()
{
	const Card* ret = m_DealerCards->OneCard();
	cout << "Dealt a card.\n";
	return ret;
};

const Card* StudDealer::deal()
{
	const Card* ret = m_DealerCards->OneCard();
	//cout << "Dealt a card.\n";
	return ret;
};

const Card* OmahaDealer::deal()
{
	const Card* ret = m_DealerCards->OneCard();
	//cout << "Dealt a card.\n";
	return ret;
};





//DESTRUCTORS
Dealer::~Dealer()
{
	cout << "Dealer destructor called\n";
};

DrawDealer::~DrawDealer()
{
	cout << "DrawDealer destructor called\n";
};

StudDealer::~StudDealer()
{
	cout << "StudDealer destructor called\n";
}

OmahaDealer::~OmahaDealer()
{
	cout << "OmahaDealer destructor called\n";
}

TexasDealer::~TexasDealer()
{
	cout << "TexasDealer destructor called\n";
}