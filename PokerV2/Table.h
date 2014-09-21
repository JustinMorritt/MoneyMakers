#if !defined(TABLE_H__)
#define TABLE_H__
#include <iostream>
#include <exception>
#include "Player.h"

using namespace std;

class Table
{
public:
	virtual void Play() = 0;
	virtual ~Table(){};
	friend class Dealer;
	
};


class DrawTable : public Table
{
public:
	DrawTable(){};
	DrawTable(int players, int gametype);
	virtual void Play();
	void AddPlayers();
	virtual ~DrawTable();

private:
	int _gameType;
	int _players;
	const int _maxCards = 5;
	vector<const Card*> m_communityCards;
	vector<const Card*> m_burnPile;
	vector<Player*> m_players;
};

class StudTable : public Table
{
public:
	StudTable(){};
	StudTable(int players, int gametype);
	virtual void Play();
	void AddPlayers();
	virtual ~StudTable();

private:
	int _gameType;
	int _players;
	const int _maxCards = 7;
	vector<const Card*> m_communityCards;
	vector<const Card*> m_burnPile;
	vector<Player*> m_players;
};

class OmahaTable : public Table
{
public:
	OmahaTable(){};
	OmahaTable(int players, int gametype);
	virtual void Play();
	void AddPlayers();
	virtual ~OmahaTable();

private:
	int _gameType;
	int _players;
	const int _maxCards = 4;
	vector<const Card*> m_communityCards;
	vector<const Card*> m_burnPile;
	vector<Player*> m_players;
};

class TexasTable : public Table
{
public:
	TexasTable(){};
	TexasTable(int players, int gametype);
	virtual void Play();
	void AddPlayers();
	virtual ~TexasTable();
	

private:
	int _gameType;
	int _players;
	const int _maxCards = 2;
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



