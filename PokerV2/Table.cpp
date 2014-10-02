#include <iostream>
#include <vector>
#include "Table.h"
#include "vector"
#include "Dealer.h"
#include "Evaluator.h"
#include "cue.h"
using namespace std;


//CONSTRUCTORS
TexasTable::TexasTable(int players, int gametype) :
Table(players),
m_dealer(new TexasDealer(players))	//CREATE NEW DEALER				
{
	//CREATE PLAYERS
	AddPlayers();

	//DEAL CARDS TO PLAYER VECTORS
	DealToPlayers(); 
	
	//THE FLOP
	Flop();
	cout << "\n";
	//PLAYERS SHOW THIER CARDS
	PlayersShowCards();
};
OmahaTable::OmahaTable(int players, int gametype) :
Table(players),
m_dealer(new OmahaDealer(players))		//CREATE NEW DEALER
{
	//ADD PLAYERS TO PLAYER VECTOR
	AddPlayers();

	//DEAL CARDS TO PLAYER VECTORS
	DealToPlayers();

	//THE FLOP
	Flop();
	cout << "\n";
	//PLAYERS SHOW THIER CARDS
	PlayersShowCards();
};
DrawTable::DrawTable(int players, int gametype):
Table(players),
m_dealer(new DrawDealer(players))		//CREATE NEW DEALER			
{
	//ADD PLAYERS TO PLAYER VECTOR
	AddPlayers();

	//DEAL CARDS TO PLAYER VECTORS
	DealToPlayers();

	//EVALUATE BEST HANDS 

	//PLAYERS SHOW THIER CARDS
	PlayersShowCards();

};
StudTable::StudTable(int players, int gametype):
Table(players),
m_dealer(new StudDealer(players))	//CREATE NEW DEALER
{
	//ADD PLAYERS TO PLAYER VECTOR
	AddPlayers();

	//DEAL CARDS TO PLAYER VECTORS
	DealToPlayers();

	//PLAYERS SHOW THIER CARDS
	PlayersShowCards();
};

//ADD PLAYERS
void TexasTable::AddPlayers()
{
	try{
		for (unsigned i = 0; i < _players; i++)
		{
			Player* p = new TexasPlayer;
			m_players.push_back(p);
			if (m_players.size() > _players || _players < 2)
			{
				throw PlayerException("\n<error> --wrong amount of players!\n");
			}
			//std::cout << "player: " << i << " created\n";
		}
	}
	catch (PlayerException ex)
	{
		cout << ex.what() << endl;
	}
};
void DrawTable::AddPlayers()
{
	try{
		for (unsigned i = 0; i < _players; i++)
		{
			Player* p = new DrawPlayer;
			m_players.push_back(p);
			if (m_players.size() > _players || _players < 2)
			{
				throw PlayerException("\n<error> --wrong amount of players!\n");
			}
			//std::cout << "player: " << i << " created\n";
		}
	}
	catch (PlayerException ex)
	{
		cout << ex.what() << endl;
	}
};
void StudTable::AddPlayers()
{
	try{
		for (unsigned i = 0; i < _players; i++)
		{
			Player* p = new StudPlayer;
			m_players.push_back(p);
			if (m_players.size() > _players || _players < 2)
			{
				throw PlayerException("\n<error> --wrong amount of players!\n");
			}
			//std::cout << "player: " << i << " created\n";
		}
	}
	catch (PlayerException ex)
	{
		cout << ex.what() << endl;
	}
};
void OmahaTable::AddPlayers()
{
	try{
		for (unsigned i = 0; i < _players; i++)
		{
			Player* p = new OmahaPlayer;
			m_players.push_back(p);
			if (m_players.size() > _players || _players < 2)
			{
				throw PlayerException("\n<error> --wrong amount of players!\n");
			}
			//std::cout << "player: " << i << " created\n";
		}
	}
	catch (PlayerException ex)
	{
		cout << ex.what() << endl;
	}
};

//DEAL CARDS TO PLAYERS
void TexasTable::DealToPlayers()
{
	std::cout << "\nDealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(m_dealer->deal()); //DEAL 1 card a person ( the correct way)
		}
	}
};
void DrawTable::DealToPlayers()
{
	std::cout << "\nDealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(m_dealer->deal()); 
		}
	}
};
void StudTable::DealToPlayers()
{
	std::cout << "\nDealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(m_dealer->deal()); 
		}
	}
};
void OmahaTable::DealToPlayers()
{
	std::cout << "\nDealing Hands...\n" << endl;
	for (int i = 0; i < _maxCards; i++)
	{
		for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
		{
			(*p_it)->AddToHand(m_dealer->deal());
		}
	}
};

//THE FLOP
void TexasTable::Flop()
{
	//BURN ONE CARD
	m_burnPile.push_back(m_dealer->burn());
	//FLOP OF 3 CARDS
	m_communityCards.push_back(m_dealer->deal());
	m_communityCards.push_back(m_dealer->deal());
	m_communityCards.push_back(m_dealer->deal());
	//BURN ONE MORE
	m_burnPile.push_back(m_dealer->burn());
	//TURN
	m_communityCards.push_back(m_dealer->deal());
	//BURN 
	m_burnPile.push_back(m_dealer->burn());
	//RIVER
	m_communityCards.push_back(m_dealer->deal());
	//DISPLAY COMMUNTITY CARDS
	int c_card = 1;
	std::cout << "\n**********_____The Flop :";
	for (vector<const Card*>::iterator c_it = m_communityCards.begin(); c_it != m_communityCards.end(); ++c_it)
	{
		const Card* p = *c_it;
		if (c_card <= 3)
		{
			std::cout << " " << p->ToString() << "";
			++c_card;
		}
		else if (c_card == 4)
		{
			//cout << "   Turn :";
			cout << " " << p->ToString() << "";
			++c_card;
		}
		else
		{
			//cout << "   River :";
			cout << " " << p->ToString() << "_____************* \n";
			++c_card;
		}
	}
};
void OmahaTable::Flop()
{
	//BURN ONE CARD
	m_burnPile.push_back(m_dealer->burn());
	//FLOP OF 3 CARDS
	m_communityCards.push_back(m_dealer->deal());
	m_communityCards.push_back(m_dealer->deal());
	m_communityCards.push_back(m_dealer->deal());
	//BURN ONE MORE
	m_burnPile.push_back(m_dealer->burn());
	//TURN
	m_communityCards.push_back(m_dealer->deal());
	//BURN 
	m_burnPile.push_back(m_dealer->burn());
	//RIVER
	m_communityCards.push_back(m_dealer->deal());
	//DISPLAY COMMUNTITY CARDS
	int c_card = 1;
	std::cout << "\n**********_____The Flop :";
	for (vector<const Card*>::iterator c_it = m_communityCards.begin(); c_it != m_communityCards.end(); ++c_it)
	{
		const Card* p = *c_it;
		if (c_card <= 3)
		{
			std::cout << " " << p->ToString() << "";
			++c_card;
		}
		else if (c_card == 4)
		{
			//cout << "   Turn :";
			cout << " " << p->ToString() << "";
			++c_card;
		}
		else
		{
			//cout << "   River :";
			cout << " " << p->ToString() << "_____************* \n";
			++c_card;
		}
	}
};

//PLAYER SHOW HAND
void DrawTable::PlayersShowCards() 
{
	//GET WINNER
	Evaluator E;
	vector<Player*>::iterator p_it = m_players.begin();
	CUE bestCue = (*p_it)->GetBestCUE();
	
	for (p_it = m_players.begin() +1; p_it != m_players.end(); p_it++)
	{
		CUE& comparedCUE = (*p_it)->GetBestCUE();
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}

	int player = 1;
	for (p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "\n_________________________Player " << player << "___________________________\n";
		//BUILD CUES
		CUE& diffCue = (*p_it)->GetBestCUE();
		cout << "Dealt: ";
		(*p_it)->ShowCards();
		cout << "\n";
		(*p_it)->ShowBestHand(diffCue);
		cout << "---------->";
		(*p_it)->GetHandName();
		
		if (E.CompareCues(bestCue, diffCue) == 0)
		{
			cout << " <------WINNER-";
		}
		player++;
		cout << endl;
	}
}
void StudTable::PlayersShowCards() 
{
	//GET WINNER
	Evaluator E;
	vector<Player*>::iterator p_it = m_players.begin();
	CUE bestCue = (*p_it)->GetBestCUE();

	for (p_it = m_players.begin() + 1; p_it != m_players.end(); p_it++)
	{
		CUE& comparedCUE = (*p_it)->GetBestCUE();
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}

	int player = 1;
	for (p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "\n_________________________Player " << player << "___________________________\n";
		//BUILD CUES
		CUE& diffCue = (*p_it)->GetBestCUE();
		cout << "Dealt: ";
		(*p_it)->ShowCards();
		cout << "\n";
		(*p_it)->ShowBestHand(diffCue);
		cout << "---------->";
		(*p_it)->GetHandName();

		if (E.CompareCues(bestCue, diffCue) == 0)
		{
			cout << " <---WINNER!";
		}
		player++;
		cout << endl;
	}
}
void OmahaTable::PlayersShowCards() 
{
	//GET WINNER
	Evaluator E;
	vector<Player*>::iterator p_it = m_players.begin();
	(*p_it)->GetComCards(m_communityCards);
	CUE bestCue = (*p_it)->GetBestCUE();

	for (p_it = m_players.begin() + 1; p_it != m_players.end(); p_it++)
	{
		(*p_it)->GetComCards(m_communityCards);
		CUE& comparedCUE = (*p_it)->GetBestCUE();
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}

	int player = 1;
	for (p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "\n_________________________Player " << player << "___________________________\n";
		//BUILD CUES
		CUE& diffCue = (*p_it)->GetBestCUE();
		cout << "Dealt: ";
		(*p_it)->ShowCards();
		cout << "\n";
		(*p_it)->ShowBestHand(diffCue);
		cout << "---------->";
		(*p_it)->GetHandName();

		if (E.CompareCues(bestCue, diffCue) == 0)
		{
			cout << " <---WINNER!";
		}
		player++;
		cout << endl;
	}
}
void TexasTable::PlayersShowCards() 
{
	//GET WINNER
	Evaluator E;
	vector<Player*>::iterator p_it = m_players.begin();
	(*p_it)->GetComCards(m_communityCards);
	CUE bestCue = (*p_it)->GetBestCUE();


	for (p_it = m_players.begin() + 1; p_it != m_players.end(); p_it++)
	{
		(*p_it)->GetComCards(m_communityCards);
		CUE& comparedCUE = (*p_it)->GetBestCUE();
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}

	int player = 1;
	for (p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		cout << "\n_________________________Player " << player << "___________________________\n";
		//BUILD CUES
		CUE& diffCue = (*p_it)->GetBestCUE();
		cout << "Dealt: ";
		(*p_it)->ShowCards();
		cout << "\n";
		(*p_it)->ShowBestHand(diffCue);
		cout << "---------->";
		(*p_it)->GetHandName();

		if (E.CompareCues(bestCue, diffCue) == 0)
		{
			cout << " <---WINNER!";
		}
		player++;
		cout << endl;
	}
}

//DESTRUCTORS
DrawTable::~DrawTable()
{
	//cout << "DrawTable destructor called\n";
	//DELETE DEALER WHEN DONE WITH HIM 
	delete m_dealer;
	//DELETE PLAYERS
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		//std::cout << "player: " << player << " Killed\n";
		player++;
	}
};
StudTable::~StudTable()
{
	//cout << "StudTable destructor called\n";
	//DELETE DEALER WHEN DONE WITH HIM 
	delete m_dealer;
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		//std::cout << "player: " << player << " Killed\n";
		player++;
	}
}
OmahaTable::~OmahaTable()
{
	//cout << "OmahaTable destructor called\n";
	//DELETE DEALER WHEN DONE WITH HIM 
	delete m_dealer;
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		//std::cout << "player: " << player << " Killed\n";
		player++;
	}
}
TexasTable::~TexasTable()
{
	//cout << "TexasTable destructor called\n";
	//DELETE DEALER WHEN DONE WITH HIM 
	delete m_dealer;
	int player = 1;
	for (vector<Player*>::iterator p_it = m_players.begin(); p_it != m_players.end(); p_it++)
	{
		delete *p_it;
		//std::cout << "player: " << player << " Killed\n";
		player++;
	}
}


