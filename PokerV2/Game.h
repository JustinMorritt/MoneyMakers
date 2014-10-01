#if !defined(GAME_H__)
#define GAME_H__
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include "Table.h"

class Game
{
public:
	Game();
	~Game();
	
	void GameTitle() const;
	void StartGame();
	int MainMenu();
	int getLegitInt(int low, int high) const;
	int GetGameType() const;
	int SetPlayers();
	int GetPlayers() const;
	Table* CreateTable(int gametype);
	void TableMenu();
	void GoodBye() const;

private:
	int _gameType;
	int _players;
};

#endif