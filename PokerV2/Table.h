#if !defined(TABLE_H__)
#define TABLE_H__
#include <iostream>
#include "Player.h"

using namespace std;

class Table
{
public:
	virtual void Play() = 0;
	virtual ~Table();
	friend class Dealer;
};




class DrawTable : public Table
{
public:
	DrawTable(){};
	DrawTable(int players, int gametype);

	virtual void Play();
	virtual ~DrawTable();
	friend class Dealer;
private:
	int _gameType;
	int _players;
	vector<const Player*> m_players;
};

class StudTable : public Table
{
public:
	StudTable(){};
	StudTable(int players, int gametype);
	virtual void Play();
	virtual ~StudTable();
	friend class Dealer;
private:
	int _gameType;
	int _players;
	vector<const Player*> m_players;
};

class OmahaTable : public Table
{
public:
	OmahaTable(){};
	OmahaTable(int players, int gametype);
	virtual void Play();
	virtual ~OmahaTable();
	friend class Dealer;
private:
	int _gameType;
	int _players;
	vector<const Player*> m_players;
};

class TexasTable : public Table
{
public:
	TexasTable(){};
	TexasTable(int players, int gametype);
	virtual void Play();
	virtual ~TexasTable();
	friend class Dealer;
private:
	int _gameType;
	int _players;
	vector<const Player*> m_players;
};




#endif