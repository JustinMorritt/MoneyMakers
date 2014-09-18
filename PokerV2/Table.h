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
};




class DrawTable : public Table
{
public:
	DrawTable(){};
	DrawTable(int players, int gametype);

	virtual void Play();
	virtual ~DrawTable();
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
private:
	int _gameType;
	int _players;
	vector<const Player*> m_players;
};




#endif