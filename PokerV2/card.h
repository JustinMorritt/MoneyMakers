#if !defined(CARD_H__)
#define CARD_H__

#include <string>



class Card
{
public:
	enum SUIT
	{
		clubs, diamonds, hearts, spades
	};
	enum PIP
	{
		_2, _3, _4, _5, _6, _7, _8, _9, _T, _J, _Q, _K, _A
	};

	const static char SUIT_CHARS[];
	const static char PIP_CHARS[];

	Card(unsigned index);

	SUIT GetSuit() const;

	PIP GetPip() const;

	std::string ToString() const;

private:
	const unsigned m_index;
};


#endif
