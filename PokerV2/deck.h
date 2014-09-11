#if !defined(DECK_H__)
#define DECK_H__

#include "card.h"


class Deck
{
	static const Card DECK[];
	friend class Deal;
public:
    static const unsigned DECK_SIZE;
	static const unsigned CARDS_PER_SUIT;
	static const unsigned SUIT_PER_DECK;	
};


#endif


