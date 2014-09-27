#include <iostream>
#include <algorithm>
#include <string>
#include "Player.h"
#include "Evaluator.h"


void Player::ShowBestHand(vector<const Card*>& c)
{
	try{
		if (c.size() == 5)
		{
			sort(c.begin(), c.end(), HigherCard());
			cout << " Built:";
			for (vector<const Card*>::iterator c_it = c.begin(); c_it != c.end(); ++c_it)
			{
				const Card* p = *c_it;
				cout << "" << p->ToString() << " ";
			}
		}
		else
			throw CUEException("NOT 5 CARDS IN CUE");
	}
	catch (CUEException ex)
	{
		cout << ex.what() << endl;
	}
}

string Player::GetCUEName(const CUE& c)
{
	Evaluator E;
	string cueName;
	if (E.IsStraight(c) && E.IsFlush(c))
	{
		char value = c[0]->GetPip();
		char value2 = c[4]->GetPip();
		char value3 = c[3]->GetSuit();
		cueName = "Straight Flush: ";
		cueName += Card::PIP_CHARS[value];
		cueName += " to ";
		cueName += Card::PIP_CHARS[value2];
		cueName += " ";
		cueName += Card::SUIT_CHARS[value];
		cueName += "'s";
		return cueName;
	}
	if (E.IsQuad(c))
	{
		char value = c[3]->GetPip();
		cueName = "Four-o-Kind: ";
		cueName += Card::PIP_CHARS[value];
		cueName += "'s";
		return cueName;
	}
	if (E.IsBoat(c))
	{
		char value = c[0]->GetPip();
		char value2 = c[3]->GetPip();
		cueName = "Full House: ";
		cueName += Card::PIP_CHARS[value];
		cueName += "'s & ";
		cueName += Card::PIP_CHARS[value2];
		cueName += "'s";
		return cueName;
	}
	if (E.IsFlush(c))
	{
		char value = c[3]->GetSuit();
		cueName = "Flush: ";
		cueName += Card::SUIT_CHARS[value];
		cueName += "'s";
		return cueName;
	}
	if (E.IsWheelStraight(c))
	{
		char value = c[0]->GetPip();
		char value2 = c[4]->GetPip();
		cueName = "Wheel Straight: ";
		cueName += Card::PIP_CHARS[value];
		cueName += " to ";
		cueName += Card::PIP_CHARS[value2];
		return cueName;
	}
	if (E.IsStraight(c))
	{
		char value = c[0]->GetPip();
		char value2 = c[4]->GetPip();
		cueName = "Straight: ";
		cueName += Card::PIP_CHARS[value];
		cueName += " to ";
		cueName += Card::PIP_CHARS[value2];
		return cueName;
	}
	if (E.IsTrips(c))
	{
		char value = c[2]->GetPip();
		cueName = "Three-o-Kind: ";
		cueName += Card::PIP_CHARS[value];
		cueName += "'s";
		return cueName;
	}
	if (E.IsTwoPair(c))
	{
		char value = c[1]->GetPip();
		char value2 = c[3]->GetPip();
		cueName = "Two Pair: ";
		cueName += Card::PIP_CHARS[value];
		cueName += "'s & ";
		cueName += Card::PIP_CHARS[value2];
		cueName += "'s";
		return cueName;
	}
	if (E.IsOnePair(c))
	{
		int value = E.GetPipValueofOnePair(c);
		cueName = "One Pair: ";
		cueName += Card::PIP_CHARS[value]; 
		cueName += "'s";
		return cueName;
	}
	else
	{
		c[4]->ToString();
		cueName = "High Card: " + c[4]->ToString();
		cueName += "'s";
		return cueName;
	}
}


void Player::Show(vector<const Card*>& cards) const
{
	for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << "" << p->ToString() << " ";
	}
}


const CUE& DrawPlayer::GetBestCUE()
{
	vector<const Card*> newCue;
	CUE c(newCue);
	//HAD TO MANUALLY PUSH ON THE m_Hand Cards 
	for (unsigned i = 0; i < 5; ++i)
	{
		c.push_back(m_Hand[i]);
	}
	sort(c.begin(), c.end(), HigherCard());
	m_Cues.push_back(c);
	
	//ShowCards(); //shows original hand.
	m_HandName = Player::GetCUEName(c); //USED TO GET CUE NAME
	//cout << " = " << Cardname << endl;

	return c;	
	

	/*
	//ALL USED FOR MULTIPLE CUES ----v
	vector<CUE>::iterator c_it = m_Cues.begin();
	vector<const Card*> tempBest = *c_it; //create a temp best hand..
	for (c_it ; c_it != m_Cues.end(); ++c_it)
	{
	//cout << "Loop working ...YAE!\n\n";
	}
	*/
};
const CUE& StudPlayer::GetBestCUE()
{
	vector<const Card*> newCue;
	CUE c(newCue);
	//HAD TO MANUALLY PUSH ON THE m_Hand Cards 
	for (unsigned i = 0; i < 5; ++i)
	{
		c.push_back(m_Hand[i]);
	}
	sort(c.begin(), c.end(), HigherCard());
	m_Cues.push_back(c); 
	return c;
};
const CUE& OmahaPlayer::GetBestCUE()
{
	vector<const Card*> newCue;
	CUE c(newCue);
	//HAD TO MANUALLY PUSH ON THE m_Hand Cards 
	for (unsigned i = 0; i < 5; ++i)
	{
		c.push_back(m_Hand[i]);
	}
	sort(c.begin(), c.end(), HigherCard());
	m_Cues.push_back(c);
	return c;
};
const CUE& TexasPlayer::GetBestCUE()
{
	vector<const Card*> newCue;
	CUE c(newCue);
	//HAD TO MANUALLY PUSH ON THE m_Hand Cards 
	for (unsigned i = 0; i < 5; ++i)
	{
		c.push_back(m_Hand[i]);
	}
	sort(c.begin(), c.end(), HigherCard());
	m_Cues.push_back(c);
	return c;
};

string DrawPlayer::GetCUEName(const CUE& c)
{
	return Player::GetCUEName(c);
};
string StudPlayer::GetCUEName(const CUE& c)
{
	return Player::GetCUEName(c);
};
string OmahaPlayer::GetCUEName(const CUE& c)
{
	return Player::GetCUEName(c);
};
string TexasPlayer::GetCUEName(const CUE& c)
{
	return Player::GetCUEName(c);
};


void DrawPlayer::ShowBestHand(vector<const Card*>& c)
{
	Player::ShowBestHand(c);
}


void DrawPlayer::GetHandName()
{
	std::cout << m_HandName;
};

void StudPlayer::GetHandName()
{
	std::cout << m_HandName;
};

void OmahaPlayer::GetHandName()
{
	std::cout << m_HandName;
};

void TexasPlayer::GetHandName()
{
	std::cout << m_HandName;
};




void DrawPlayer::ShowCards()
{
	Player::Show(m_Hand);
};
void StudPlayer::ShowCards()
{
	Player::Show(m_Hand);
};
void OmahaPlayer::ShowCards()
{
	Player::Show(m_Hand);
};
void TexasPlayer::ShowCards()
{
	Player::Show(m_Hand);
};


void TexasPlayer::AddToHand(const Card* c)
{
	m_Hand.push_back(c);
	//cout << " added card to hand\n";
};
void OmahaPlayer::AddToHand(const Card* c)
{
	m_Hand.push_back(c);
	//cout << " added card to hand\n";
};
void StudPlayer::AddToHand(const Card* c)
{
	m_Hand.push_back(c);
	//cout << " added card to hand\n";
};
void DrawPlayer::AddToHand(const Card* c)
{
	m_Hand.push_back(c);
	//cout << " added card to hand\n";
};