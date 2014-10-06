#include <vector>
#include "Dealer.h"
#include "deal.h"
#include "card.h"

//CONSTRUCTORS
TexasDealer::TexasDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	//cout << "Made Texas Hold'em Dealer \n";
};

OmahaDealer::OmahaDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	//cout << "Made Ohmaha High Dealer\n";
};

DrawDealer::DrawDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	//cout << "Made 5 Card Draw Dealer \n";
};

StudDealer::StudDealer(int players)
{
	m_DealerCards = new Deal;
	_players = players;
	//cout << "Made a 7 Card Stud Dealer \n";
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
	//cout << "Dealt a card.\n";
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
	
	//cout << "Dealer destructor called\n";
};

DrawDealer::~DrawDealer()
{
	delete m_DealerCards;
	//cout << "DrawDealer destructor called\n";
};

StudDealer::~StudDealer()
{
	delete m_DealerCards;
	//cout << "StudDealer destructor called\n";
}

OmahaDealer::~OmahaDealer()
{
	delete m_DealerCards;
	//cout << "OmahaDealer destructor called\n";
}

TexasDealer::~TexasDealer()
{
	delete m_DealerCards;
	//cout << "TexasDealer destructor called\n";
}

//BURN CARD
const Card* TexasDealer::burn()
{
	const Card* ret = m_DealerCards->OneCard();
	return ret;
};

const Card* DrawDealer::burn()
{
	const Card* ret = m_DealerCards->OneCard();
	return ret;
};

const Card* StudDealer::burn()
{
	const Card* ret = m_DealerCards->OneCard();
	return ret;
};

const Card* OmahaDealer::burn()
{
	const Card* ret = m_DealerCards->OneCard();
	return ret;
};