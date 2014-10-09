#include "Game.h"
#include "Table.h"

using namespace std;

Game::Game() : _evaluator(1) //Default evaluator set to Sorted
{
	StartGame();
}

Game::~Game()
{
}

void Game::StartGame()
{
	this->GameTitle();								//Display Title
	while (true)
	{
		this->MainMenu();							//Get Game Type 
		if (GetGameType() == 0){ break; };			//if 0 Quit
		this->SetPlayers();							//Set Players

		while (GetPlayers() != 0)
		{
			Table* p = CreateTable(GetGameType());	//Create table child object assigned to Pointer* p 								//activate Virtual Play() 
			delete p;								//delete the pointer.
			this->TableMenu();						//Menu after Table has been displayed.
		};
		if (GetGameType() == 0){ break; };
	};
	GoodBye();
}

int Game::MainMenu()
{
	int choice;
	while (true)
	{
		cout << "\n(1) Texas Hold'em\n"
			<< "(2) Ohmaha High\n"
			<< "(3) Seven Card Stud\n"
			<< "(4) Five Card Draw\n"
			<< "(5) Evaluator Type: " << _evaluatorName
			<< "\n(0) Quit\n";
			
		choice = getLegitInt(0, 5);
		if (choice == 5)
		{
			SetEvaluator();
		}
		if (choice >= 0 && choice < 5)
		{
			break;
		}
	}
	this->_gameType = choice;
	return choice;
};

//Getters
int Game::GetGameType() const
{
	return _gameType;
};
int Game::GetPlayers() const
{
	return _players;
};
void Game::SetEvaluator()
{
	int choice;
	while (true)
	{
		cout << "\n(1) Sorted Evaluator\n"
			 << "(2) Hash Evaluator\n ";
		choice = getLegitInt(1, 2);
		if (choice == 1)
		{
			_evaluator = 1;
			_evaluatorName = "Sorted";
			break;
		}
		if (choice == 2)
		{
			_evaluator = 2;
			_evaluatorName = "Hash";
			pHash = new HashEvaluator;
			break;
		}
	}
};


Table* Game::CreateTable(int gametype)
{
	switch (gametype)
	{
	case 1:
		return new  TexasTable(_players, _evaluator); //Pass by Value ..players and gametype.
	case 2:
		return new OmahaTable(_players, _evaluator);
	case 3:
		return new StudTable(_players, _evaluator);
	case 4:
		return new DrawTable(_players, _evaluator);
	}
	return NULL;
}

void Game::TableMenu() 
{
	int choice;
	while (true)
	{
		cout << "\n(0) Quit\n"
			<< "(1) Main Menu\n"
			<< "(2) Re-Play ! \n"
			<< "(3) Change Evaluator, Current: " << _evaluatorName
			<< "\n";
		choice = getLegitInt(0, 3);
		if (choice == 3)
		{
			SetEvaluator();
		}
		if (choice == 1) //Break to main menu 
		{
			_players = 0;
			break;
		}
		if (choice == 2)
		{
			_players = SetPlayers();
			break;
		}
		if (choice == 0)
		{
			_players = 0;
			_gameType = 0;
			break;
		}
	}

};

int Game::SetPlayers()
{
	int maxPlayers;
	int minPlayers = 2;
	int choice;
	switch (GetGameType())
	{
		case 1: maxPlayers = 22; //Texas
			break;
		case 2: maxPlayers = 9; // Omaha 
			break;
		case 3:	maxPlayers = 7; // Stud
			break;
		case 4: maxPlayers = 8; // Draw
			break;
	};
	cout << "Please enter the number of players (" << minPlayers << " - " << maxPlayers << ")  \n";
	choice = getLegitInt(minPlayers, maxPlayers); //PASS MIN/MAX players to Is legit function 
	_players = choice;
	return choice;
};

int Game::getLegitInt(int low, int high) const
{	
	int ret;
	do
	{
		std::string str;
		std::getline(std::cin, str);
		std::stringstream ss(str);
		ss >> ret;
		if ((ss) && (ret >= low && ret <= high))
		{
			break;
		}
		else
		{
			std::cout << "-<error>--wrong option--choose(" << low << " - " << high << ")--" << std::endl;
			continue;
		}
	}while (true);
	return ret;
};

void Game::GameTitle() const
{
	cout << "\t|***************************************|\n"
		<< "\t|---JUSTIN---------&-----------LEVI's---|"
		<< "\n\t|---------------------------------------|\n"
		<< " ooooooooo.    .oooooo.   oooo    oooo oooooooooooo  ooooooooo.  \n"
		<< " 888   `Y88. d8P     Y8b  888   .8P'    888'    `8  `888   `Y88.\n"
		<< " 888   .d88' 888      888  888  d8'     888          888   .d88'\n"
		<< " 888ooo88P'  888      888  88888[       888oooo8     888ooo88P' \n"
		<< " 888         888      888  888`88b.     888    '     888  88b. \n"
		<< " 888         `88b    d88'  888  `88b.   888       o  888  `88b. \n"
		<< "o888o          Y8bood8P'  o888o  o888o o888ooooood8 o888o  o888o\n\n"
		<< "Please Enter one of the following options :\n";
};

void Game::GoodBye() const
{
	cout << "\nThanks For Playing...\n"
		<< " .88888.                          dP  888888ba                       dP\n"
		<< "d8'   `88                         88  88    `8b                      88\n"
		<< "88        .d8888b. .d8888b. .d888b88  88aaaa8P' dP    dP .d8888b.    88\n"
		<< "88   YP88 88'  `88 88'  `88 88'  `88  88   `8b. 88    88 88ooood8    dP\n"
		<< "Y8.   .88 88.  .88 88.  .88 88.  .88  88    .88 88.  .88 88.  ...      \n"
		<< " `88888'  `88888P' `88888P' `88888P8  88888888P `8888P88 `88888P'    oo\n"
		<< "                                                     .88               \n"
		<< "                                                 d8888P                \n\n\n";
	system("pause");
};