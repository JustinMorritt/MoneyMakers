#if !defined(TABLE_H__)
#define TABLE_H__
#include <iostream>
#include <exception>
#include "Dealer.h"
#include "Player.h"


class Table
{
public:
	Table(unsigned players) : _players(players){};
	virtual ~Table(){};	
private:
protected:
	
	unsigned _players;
};


class DrawTable : public Table
{
public:
	//DrawTable(){};
	DrawTable(int players, int gametype);
	void DealToPlayers();
	void AddPlayers();
	void PlayersShowCards();
	void PlayersShowHashCards();
	virtual ~DrawTable();

private:
	int _evaluator;
	const int _maxCards = 5;
	Dealer * m_dealer;
	vector<Player*> m_players;
};

class StudTable : public Table
{
public:
	StudTable(int players, int evaluator);
	void AddPlayers();
	void DealToPlayers();
	void PlayersShowCards();
	void PlayersShowHashCards();
	virtual ~StudTable();

private:
	int _evaluator;
	Dealer * m_dealer;
	const int _maxCards = 7;
	vector<Player*> m_players;
};

class OmahaTable : public Table
{
public:

	OmahaTable(int players, int evaluator);
	void AddPlayers();
	void DealToPlayers();
	void Flop();
	void PlayersShowCards();
	void PlayersShowHashCards();
	virtual ~OmahaTable();

private:
	int _evaluator;
	const int _maxCards = 4;
	Dealer * m_dealer;
	vector<const Card*> m_communityCards;
	vector<const Card*> m_burnPile;
	vector<Player*> m_players;
};

class TexasTable : public Table
{
public:

	TexasTable(int players, int evaluator);
	void AddPlayers();
	void DealToPlayers();
	void Flop();
	void PlayersShowCards();
	void PlayersShowHashCards();
	virtual ~TexasTable();

private:
	int _evaluator;
	const int _maxCards = 2;
	Dealer * m_dealer;
	vector<const Card*> m_communityCards;
	vector<const Card*> m_burnPile;
	vector<Player*> m_players;
};



class PlayerException : public logic_error
{
public:
	PlayerException(const char* r) : std::logic_error(r){};
};

//USE THE STUFF BELOW IF YOU ARE GOING TO THROW IN A CUSTOM EXCEPTION SOMEWHERE
//REMEMBER TO USE throw PlayerException("\n  ERROR MESSAGE IN HERE  \n");

/*
try{

}
catch (PlayerException ex)
{
cout << ex.what() << endl;
}*/



#endif



