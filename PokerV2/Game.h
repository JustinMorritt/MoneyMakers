#if !defined(GAME_H__)
#define GAME_H__
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