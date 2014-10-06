#include <iostream>
#include <map>
#include "Dealer.h"
#include "HashEvaluator.h"



using namespace std;

int main()
{
	cout << "Welcome to the HashEvaluator Test Platform\n"
		 << " To Do:  Need To Create Each combination of all the hands.\n\n\n";


	HashEvaluator H;

	cout << "\n\n";
	int HandNum = 1;
	while (true)
	{
		Dealer* D = new TexasDealer(5);
		vector<const Card*> Cards;

		for (unsigned i = 0; i < 5; ++i)
		{
			const Card*  c = D->deal();
			Cards.push_back(c);
		}

		cout << "Hand " << HandNum << ":";

		for (vector<const Card*>::iterator c_it = Cards.begin(); c_it != Cards.end(); ++c_it)
		{
			cout << " " << (*c_it)->ToString() ;
		}
		cout << "--> Value:    Rank:     Name:    ";
		cin.get();
		++HandNum;
		delete D;
	}
	
	return 0;
}