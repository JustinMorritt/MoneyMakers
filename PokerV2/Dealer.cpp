#include <vector>
#include "Dealer.h"
#include "deal.h"
#include "card.h"
#include "Table.h"

//CONSTRUCTORS
TexasDealer::TexasDealer(int players)
{
	const int MAXCARDS = 2;
	_players = players;
	cout << "Made Texas Hold'em Dealer \n";
};

OmahaDealer::OmahaDealer(int players)
{
	_players = players;
	cout << "Made Ohmaha High Dealer\n";
};

DrawDealer::DrawDealer(int players)
{
	
	_players = players;
	cout << "Made 5 Card Draw Dealer \n";
};

StudDealer::StudDealer(int players)
{
	_players = players;
	cout << "Made a 7 Card Stud Dealer \n";
};



void TexasDealer::deal()
{
	
	cout << "Dealt cards to: " << _players << " players.\n";

};

void DrawDealer::deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";
};

void StudDealer::deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";
};

void OmahaDealer::deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";
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