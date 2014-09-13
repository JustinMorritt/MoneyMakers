#include "Dealer.h"

//CONSTRUCTORS
TexasDealer::TexasDealer(int players)
{
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



void TexasDealer::Deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";

};

void DrawDealer::Deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";
};

void StudDealer::Deal()
{
	cout << "Dealt cards to: " << _players << " players.\n";
};

void OmahaDealer::Deal()
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