#include <iostream>
#include <map>
#include <iomanip>
#include "Dealer.h"
#include "HashEvaluator.h"

using namespace std;

int main()
{
	cout
		<< "____    ____       _        ____   ____    ____  \n"
		<< "`MM'    `MM'      dM.      6MMMMb\  `MM'    `MM'  \n"
		<< " MM      MM      ,MMb     6M'    `  MM      MM   \n"
		<< " MM      MM      d'YM.    MM        MM      MM   \n"
		<< " MM      MM     ,P `Mb    YM.       MM      MM   \n"
		<< " MMMMMMMMMM     d'  YM.    YMMMMb   MMMMMMMMMM   \n"
		<< " MM      MM    ,P   `Mb        `Mb  MM      MM   \n"
		<< " MM      MM    d'    YM.        MM  MM      MM   \n"
		<< " MM      MM   ,MMMMMMMMb        MM  MM      MM   \n"
		<< " MM      MM   d'      YM. L    ,M9  MM      MM   \n"
		<< "_MM_    _MM__dM_     _dMM_MYMMMM9  _MM_    _MM_  By:Justin\n";
                                                                                                                      

	HashEvaluator* H = new HashEvaluator;

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

		unsigned hash = H->GetHash(Cards);
		unsigned value = H->GetValue(hash);
		string  name = H->GetName(hash);

		cout << "--> Hash#: " << hash << setw(5) << right << " Rank:" << value << " Name: " << name;
		cin.get();
		++HandNum;
		delete D;
	}
	
	return 0;
}