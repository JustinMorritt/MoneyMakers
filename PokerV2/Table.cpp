#include "Table.h"
#include "Dealer.h"

//CONSTRUCTORS
TexasTable::TexasTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating Texas Hold'em Dealer and, " << _players << " Texas Hold'em players\n";
	//CREATE TEXAS DEALER
	Dealer* d = new TexasDealer(_players);
	d->Deal(); //MAKE NEW DEALER DEAL
	delete d;
};

OmahaTable::OmahaTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating Ohmaha High Dealer and, " << _players << "  Ohmaha High players\n";
	Dealer* d = new OmahaDealer(_players);
	d->Deal(); //MAKE NEW DEALER DEAL
	delete d;
};

DrawTable::DrawTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating 5 Card Draw Dealer and, " << _players << "  5 card draw players\n";
	Dealer* d = new DrawDealer(_players);
	d->Deal(); //MAKE NEW DEALER DEAL
	delete d;
};

StudTable::StudTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating a 7 Card Stud Dealer and, " << _players << "  Seven Card Stud Players\n";
	Dealer* d = new StudDealer(_players);
	d->Deal(); //MAKE NEW DEALER DEAL
	delete d;
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