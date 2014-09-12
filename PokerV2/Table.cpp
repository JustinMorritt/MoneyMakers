#include "Table.h"
#include "Dealer.h"

//CONSTRUCTORS
TexasTable::TexasTable()
{
	cout << "\nCreating Texas Hold'em Dealer and Texas Hold'em players";
};

OmahaTable::OmahaTable()
{
	cout << "\nCreating Ohmaha High Dealer and Ohmaha High players\n";
};

DrawTable::DrawTable()
{
	cout << "\nCreating 5 Card Draw Dealer and 5 card draw players\n";
};

StudTable::StudTable()
{
	cout << "\nCreating a 7 Card Stud Dealer & 7 Card Stud Players\n";
};



void TexasTable::Play()
{
	cout << "\nTexas Table Played\n";
};

void DrawTable::Play()
{
	cout << "\nDraw Table Played\n";
};

void StudTable::Play()
{
	cout << "\nStud Table Played\n";
};

void OmahaTable::Play()
{
	cout << "\nOmaha Table Played\n";
};





//DESTRUCTORS
Table::~Table()
{
	cout << "Table destructor called\n";
};

DrawTable::~DrawTable()
{
	cout << "DrawTable destructor called\n";
};

StudTable::~StudTable()
{
	cout << "StudTable destructor called\n";
}

OmahaTable::~OmahaTable()
{
	cout << "OmahaTable destructor called\n";
}

TexasTable::~TexasTable()
{
	cout << "TexasTable destructor called\n";
}