#include "Table.h"
#include "vector"
#include "Dealer.h"
//CONSTRUCTORS
TexasTable::TexasTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	//CREATE TEXAS DEALER
	Dealer* d = new TexasDealer(_players);
	
	//CREATE PLAYERS
	for (int i = 1; i <= _players; i++)
	{
		Player* p = new TexasPlayer;
		m_players.push_back(p);
		//std::cout << "player: " << i << " created\n";
	}

	//DEAL CARDS TO PLAYER VECTORS
	cout << "Dealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(d->deal()); //DEAL 1 card a person ( the correct way)
		}
	}

	//PLAYERS SHOW THIER CARDS
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "Player " << player << " Hand : ";
		(*p_it)->ShowCards();
		player++;
		cout << endl;
	}
	delete d; //DELETE DEALER WHEN DONE WITH HIM 
};

OmahaTable::OmahaTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating Ohmaha High Dealer and, " << _players << "  Ohmaha High players\n";
	Dealer* d = new OmahaDealer(_players);
	for (int i = 1; i <= _players; i++)
	{
		Player* p = new OmahaPlayer;
		m_players.push_back(p);
		//std::cout << "player: " << i << " created\n";
	}

	//DEAL CARDS TO PLAYER VECTORS
	cout << "Dealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(d->deal()); //DEAL 1 card a person ( the correct way)
		}
	}

	//PLAYERS SHOW THIER CARDS
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "Player " << player << " Hand : ";
		(*p_it)->ShowCards();
		player++;
		cout << endl;
	}
	delete d; //DELETE DEALER WHEN DONE WITH HIM 
};

DrawTable::DrawTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating 5 Card Draw Dealer and, " << _players << "  5 card draw players\n";
	Dealer* d = new DrawDealer(_players);
	for (int i = 1; i <= _players; i++)
	{
		Player* p = new DrawPlayer;
		m_players.push_back(p);
		//std::cout << "player: " << i << " created\n";
	}

	//DEAL CARDS TO PLAYER VECTORS
	cout << "Dealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(d->deal()); //DEAL 1 card a person ( the correct way)
		}
	}

	//PLAYERS SHOW THIER CARDS
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "Player " << player << " Hand : ";
		(*p_it)->ShowCards();
		player++;
		cout << endl;
	}
	delete d; //DELETE DEALER WHEN DONE WITH HIM 
};

StudTable::StudTable(int players, int gametype)
{
	_gameType = gametype;
	_players = players;
	cout << "\nCreating a 7 Card Stud Dealer and, " << _players << "  Seven Card Stud Players\n";
	Dealer* d = new StudDealer(_players);
	for (int i = 1; i <= _players; i++)
	{
		Player* p = new StudPlayer;
		m_players.push_back(p);
		//std::cout << "player: " << i << " created\n";
	}

	//DEAL CARDS TO PLAYER VECTORS
	cout << "Dealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(d->deal()); //DEAL 1 card a person ( the correct way)
		}
	}

	//PLAYERS SHOW THIER CARDS
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "Player " << player << " Hand : ";
		(*p_it)->ShowCards();
		player++;
		cout << endl;
	}
	delete d; //DELETE DEALER WHEN DONE WITH HIM 
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
DrawTable::~DrawTable()
{
	//cout << "DrawTable destructor called\n";
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		std::cout << "player: " << player << " Killed\n";
		player++;
	}
};

StudTable::~StudTable()
{
	//cout << "StudTable destructor called\n";
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		std::cout << "player: " << player << " Killed\n";
		player++;
	}
}

OmahaTable::~OmahaTable()
{
	//cout << "OmahaTable destructor called\n";
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		std::cout << "player: " << player << " Killed\n";
		player++;
	}
}

TexasTable::~TexasTable()
{
	//cout << "TexasTable destructor called\n";
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		std::cout << "player: " << player << " Killed\n";
		player++;
	}
}