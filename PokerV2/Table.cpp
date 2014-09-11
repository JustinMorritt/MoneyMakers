#include "Table.h"

Table::~Table()
{
	cout << "Table destructor called\n";
};


void DrawTable::Play()
{
	cout << "\nDraw Table Played\n";
};

DrawTable::~DrawTable()
{
	cout << "DrawTable destructor called\n";
};


void StudTable::Play()
{
	cout << "\nStud Table Played\n";
};

StudTable::~StudTable()
{
	cout << "StudTable destructor called\n";
}

void OmahaTable::Play()
{
	cout << "\nOmaha Table Played\n";
};

OmahaTable::~OmahaTable()
{
	cout << "OmahaTable destructor called\n";
}


void TexasTable::Play()
{
	cout << "\nTexas Table Played\n";
};

TexasTable::~TexasTable()
{
	cout << "TexasTable destructor called\n";
}