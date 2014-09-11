#include "card.h"
#include "deck.h"


const char Card::SUIT_CHARS[] = 
{
	'C', 'D', 'H', 'S'
};

const char Card::PIP_CHARS[] = 
{
	'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
};


Card::Card(unsigned index) : m_index(index)
{
	if(index >= Deck::DECK_SIZE)
	{
		//TODO: We need to deal with this.
	}
}


Card::SUIT Card::GetSuit() const
{
	return static_cast<SUIT>(m_index / Deck::CARDS_PER_SUIT);
}

Card::PIP Card::GetPip() const
{
	return static_cast<PIP>(m_index % Deck::CARDS_PER_SUIT);
}


std::string Card::ToString() const
{
	std::string ret;
	ret += Card::PIP_CHARS[GetPip()];
	ret += Card::SUIT_CHARS[GetSuit()];
	return ret;
}


