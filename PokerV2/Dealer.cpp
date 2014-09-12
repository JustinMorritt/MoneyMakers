#include "Dealer.h"

//CONSTRUCTORS
TexasDealer::TexasDealer()
{
	cout << "Made Texas Hold'em Dealer \n";
};

OmahaDealer::OmahaDealer()
{
	cout << "Made Ohmaha High Dealer\n";
};

DrawDealer::DrawDealer()
{
	cout << "Made 5 Card Draw Dealer \n";
};

StudDealer::StudDealer()
{
	cout << "Made a 7 Card Stud Dealer \n";
};



void TexasDealer::Deal()
{
	cout << "\nTexas Table Played\n";
};

void DrawDealer::Deal()
{
	cout << "\nDraw Table Played\n";
};

void StudDealer::Deal()
{
	cout << "\nStud Table Played\n";
};

void OmahaDealer::Deal()
{
	cout << "\nOmaha Table Played\n";
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