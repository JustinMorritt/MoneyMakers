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
	
	void StartGame();
	int MainMenu();
	int SetPlayers();
	void TableMenu();
	//MAKE A CHECK INPUT FOR INT 
	int getLegitInt(int low, int high) const;
	void GoodBye() const;
	void GameTitle() const;
	int GetGameType() const;
	int GetPlayers() const;
	Table* CreateTable(int gametype);

private:
	int _gameType;
	int _players;
};

#endif