#include <iostream>
#include <algorithm> 
#include "deal.h"
#include "randgen.h"

using namespace std;


Deal::Deal()
{
	for(unsigned i = 0; i < Deck::DECK_SIZE; ++i)
	{
	//	m_cards.push_back(&Deck::DECK[i]);	// exactly the same 
		m_cards.push_back(Deck::DECK + i);	// pointer arithmatic

	}
	Shuffle();
}

void Deal::Shuffle()
{
    RandGen rg;
	random_shuffle(m_cards.begin(), m_cards.end(), rg);
}

const Card* Deal::OneCard()
{
	const Card* p = m_cards.back();
	m_cards.pop_back();
	return p;
}



void Deal::Populate(Deal& d) const
{
	const unsigned DISPLAY_ROW = 4;
	std::cout << "\n\n\n   <<<<<<<<<<<<< Displaying Cards >>>>>>>>>>>>>>>";
	std::cout << "\n   **********************************************\n";
	unsigned i = 0;
	while (d.Empty() == false)
	{
		++i;
		const Card* p = d.OneCard();

		cout << " " << p->ToString() << " ";
		if (i == DISPLAY_ROW)
		{
			i = 0;
			cout << endl;
		}
	}
}