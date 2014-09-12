
#include "Game.h"
#include "Table.h"

using namespace std;

Game::Game()
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
			Table* p = CreateTable(GetGameType());	//Create table child object assigned to Pointer* p 
			p->Play();								//activate Virtual Play() 
			delete p;								//delete the pointer.
			this->TableMenu();						//Menu after Table has been displayed.
		};
		if (GetGameType() == 0){ break; };
	};
}

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

int Game::MainMenu()
{
	int choice;
	while (true)
	{
		cout << "\n(1) Texas Hold'em\n"
			<< "(2) Ohmaha High\n"
			<< "(3) Seven Card Stud\n"
			<< "(4) Five Card Draw\n"
			<< "(0) Quit\n"
			<< "\nGameType:";
		cin >> choice;
		if (choice >= 0 && choice < 5)
		{
			break;
		}
		else
		{
			cout << "\n\n<Error> --Wrong Option--\n\n";
			continue;
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



Table* Game::CreateTable(int gametype)
{
	switch (gametype)
	{
	case 1:
		return new  TexasTable;
	case 2:
		return new OmahaTable;
	case 3:
		return new StudTable;
	case 4:
		return new DrawTable;
	}
}




void Game::TableMenu() 
{
	int choice;
	while (true)
	{
		cout << "\n(0) Quit\n"
			<< "(1) Main Menu\n"
			<< "(2) Re-Play ! ";
		cin >> choice;
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
		else
		{
			cout << "\n\n<Error> --wrong choice--\n\n";
			continue;
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
		case 1: maxPlayers = 9;
			break;
		case 2: maxPlayers = 9;
			break;
		case 3:	maxPlayers = 7;
			break;
		case 4: maxPlayers = 8;
			break;
	};
	while (true)
	{
		cout << "Please enter the number of players (" << minPlayers << " - " << maxPlayers << ")  \n";
		cin >> choice;
		if (choice >= minPlayers && choice <= maxPlayers)
		{
			_players = choice;
			return choice;
		}
		cout << "\n-Error Cannot Compute---Wrong Choice-\n\n";
		continue;
	}
};


int Game::getLegitInt() const
{
	
	int input = 0;
	string str;
	while (true)
	{

		stringstream ss(str); //create a stringstream 
		//object based on that sring
		ss >> input;          // parse the object
		if (!ss) //report an error
		{
			if (cin.eof())
			{
				cout << "End of file found." << endl;
				cin.clear();
			}
			else
			{
				cout << "Error parsing " << ss.str() << endl;
			}
		}
		else
		{
			if (input >= 0)
			{
				return input;
			}
		}
	}
};


void Game::GoodBye() const
{
	char bye;
	cout << "\nThanks For Playing...\n"
		<< " .88888.                          dP  888888ba                       dP\n"
		<< "d8'   `88                         88  88    `8b                      88\n"
		<< "88        .d8888b. .d8888b. .d888b88 a88aaaa8P' dP    dP .d8888b.    88\n"
		<< "88   YP88 88'  `88 88'  `88 88'  `88  88   `8b. 88    88 88ooood8    dP\n"
		<< "Y8.   .88 88.  .88 88.  .88 88.  .88  88    .88 88.  .88 88.  ...      \n"
		<< " `88888'  `88888P' `88888P' `88888P8  88888888P `8888P88 `88888P'    oo\n"
		<< "                                                     .88               \n"
		<< "                                                 d8888P                \n\n\n"
		<< "(enter any key to exit program)";
cin >> bye;

};