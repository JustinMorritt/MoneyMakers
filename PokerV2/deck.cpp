#include "deck.h"

const unsigned Deck::CARDS_PER_SUIT = 13;
const unsigned Deck::SUIT_PER_DECK = 4;


const Card Deck::DECK[] = 
{
	Card(0),
	Card(1),
	Card(2),
	Card(3),
	Card(4), 
	Card(5),
	Card(6),
	Card(7),
	Card(8),
	Card(9), 
	Card(10),
	Card(11),
	Card(12),
	Card(13),
	Card(14), 
	Card(15),
	Card(16),
	Card(17),
	Card(18),
	Card(19),
	Card(20),
	Card(21),
	Card(22),
	Card(23),
	Card(24), 
	Card(25),
	Card(26),
	Card(27),
	Card(28),
	Card(29),
	Card(30),
	Card(31),
	Card(32),
	Card(33),
	Card(34), 
	Card(35),
	Card(36),
	Card(37),
	Card(38),
	Card(39), 
	Card(40),
	Card(41),
	Card(42),
	Card(43),
	Card(44), 
	Card(45),
	Card(46),
	Card(47),
	Card(48),
	Card(49), 
	Card(50),
	Card(51)
};

const unsigned Deck::DECK_SIZE = sizeof(Deck::DECK) / sizeof(Deck::DECK[0]);
