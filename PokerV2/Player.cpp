#include <iostream>
#include <algorithm>
#include <string>
#include "Player.h"
#include "Evaluator.h"


void Player::ShowBestHand(const CUE& c)
{
	const CUE& Cue = c;
	cout << "Built:";
	for (int i = 0; i < 5; ++i)
	{
		const Card* p = Cue[i] ;
		cout << " " << p->ToString();
	}
}

string Player::GetCUEName(const CUE& c)
{
	Evaluator E;
	string cueName;
	if (E.IsStraight(c) && E.IsFlush(c) && E.IsWheelStraight(c))
	{
		char value = c[0]->GetPip();
		char value2 = c[4]->GetPip();
		char value3 = c[3]->GetSuit();
		cueName = "Wheel Straight Flush: ";
		cueName += Card::PIP_CHARS[value];
		cueName += " to ";
		cueName += Card::PIP_CHARS[value2];
		cueName += " ";
		cueName += Card::SUIT_CHARS[value3];
		cueName += "'s  ";
		cueName += " High Card:";
		cueName += Card::PIP_CHARS[value2];
		return cueName;
	}
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
		cueName += Card::SUIT_CHARS[value3];
		cueName += "'s  ";
		cueName += " High Card:";
		cueName += Card::PIP_CHARS[value2];
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
		if (c[0]->GetPip() == c[2]->GetPip())
		{
			char value = c[0]->GetPip();
			char value2 = c[3]->GetPip();
			cueName = "Full House: ";
			cueName += Card::PIP_CHARS[value];
			cueName += "'s Full of ";
			cueName += Card::PIP_CHARS[value2];
			cueName += "'s";
			return cueName;
		}
		if (c[2]->GetPip() == c[4]->GetPip())
		{
			char value = c[3]->GetPip();
			char value2 = c[0]->GetPip();
			cueName = "Full House: ";
			cueName += Card::PIP_CHARS[value];
			cueName += "'s Full of ";
			cueName += Card::PIP_CHARS[value2];
			cueName += "'s";
			return cueName;
		}
	
	}
	if (E.IsFlush(c))
	{
		char value = c[3]->GetSuit();
		char value2 = c[4]->GetPip();
		cueName = "Flush: ";
		cueName += Card::SUIT_CHARS[value];
		cueName += "'s    ";
		cueName += Card::PIP_CHARS[value2];
		cueName += " High";
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
		char value2 = c[4]->GetPip();
		int value = E.GetPipValueofOnePair(c);
		cueName = "One Pair: ";
		cueName += Card::PIP_CHARS[value]; 
		cueName += "'s  ";
		cueName += Card::PIP_CHARS[value2];
		cueName += " High";
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


vector<CUE> DrawPlayer::BuildCUEs()
{
	CUE c;
	for (vector<const Card*>::iterator c_it = m_Hand.begin(); c_it != m_Hand.end(); ++c_it)
	{
		const Card* p = *c_it;
		c.push_back(p);
	}
	sort(c.begin(), c.end(), HigherCard());

	m_Cues.push_back(c);
	return m_Cues;
};
vector<CUE> StudPlayer::BuildCUEs()
{
	for (int pointer1 = 0; pointer1 < 6; ++pointer1)
	{
		for (int pointer2 = pointer1 + 1; pointer2 < 7; ++pointer2)
		{
			CUE c;
			for (int i = 0; i < 7; ++i)
			{
				if (i != pointer1 && i != pointer2)
				{
					c.push_back(m_Hand[i]);
				}
			}
			sort(c.begin(), c.end(), HigherCard());
			m_Cues.push_back(c);
		}
	}
	return m_Cues;
};
vector<CUE> OmahaPlayer::BuildCUEs()
{
	vector<const Card*> CUEBuilder;
	for (int i = 0; i < m_Hand.size(); ++i)
	{
		CUEBuilder.push_back(m_Hand[i]);
	}

	for (int i = 0; i < m_CommunityCards.size(); ++i)
	{
		CUEBuilder.push_back(m_CommunityCards[i]);
	}

	for (int pointer1 = 0; pointer1 <= 2; ++pointer1)
	{
		for (int pointer2 = pointer1 + 1; pointer2 <= 3; ++pointer2)
		{
			for (int pointer3 = 4; pointer3 <= 7; ++pointer3)
			{
				for (int pointer4 = pointer3 + 1; pointer4 <= 8; ++pointer4)
				{
					CUE c;
					for (int i = 0; i < CUEBuilder.size(); ++i)
					{
						if (i != pointer1 && i != pointer2 && i != pointer3 && i != pointer4)
						{
							c.push_back(CUEBuilder[i]);
						}
					}
					sort(c.begin(), c.end(), HigherCard());
					m_Cues.push_back(c);
				}
			}
		}
	}
	return m_Cues;
};
vector<CUE> TexasPlayer::BuildCUEs()
{
	vector<const Card*> CUEBuilder;
	for (int i = 0; i < m_Hand.size(); ++i)
	{
		CUEBuilder.push_back(m_Hand[i]);
	}

	for (int i = 0; i < m_CommunityCards.size(); ++i)
	{
		CUEBuilder.push_back(m_CommunityCards[i]);
	}
	
	for (int pointer1 = 0; pointer1 < 6; ++pointer1)
	{
		for (int pointer2 = pointer1 + 1; pointer2 < 7; ++pointer2)
		{
			CUE c;
			for (int i = 0; i < CUEBuilder.size(); ++i)
			{
				if (i != pointer1 && i != pointer2)
				{
					c.push_back(CUEBuilder[i]);
				}
			}
			sort(c.begin(), c.end(), HigherCard());
			m_Cues.push_back(c);
		}
	}
	return m_Cues;
};

CUE& DrawPlayer::GetBestCUE()
{
	
	m_Cues = BuildCUEs();						//BUILD
	_bestCUE = m_Cues[0];						//ASSIGN BEST CUE
	m_HandName = GetCUEName(_bestCUE);			//ASSIGN HANDNAME
	
	//FOR OTHERS .. EVALUATE THROUGH m_CUES
	return _bestCUE;							//RETURN BEST CUE
};
CUE& StudPlayer::GetBestCUE()
{
	m_Cues = BuildCUEs();
	Evaluator E;
	vector<CUE>::iterator p_it = m_Cues.begin();
	CUE bestCue = m_Cues[0];

	for (p_it = m_Cues.begin() + 1; p_it != m_Cues.end(); p_it++)
	{
		CUE& comparedCUE = *p_it;
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}
	_bestCUE = bestCue;
	m_HandName = GetCUEName(_bestCUE);

	return _bestCUE;
};
CUE& OmahaPlayer::GetBestCUE()
{
	m_Cues = BuildCUEs();
	Evaluator E;
	vector<CUE>::iterator p_it = m_Cues.begin();
	CUE bestCue = m_Cues[0];

	for (p_it = m_Cues.begin() + 1; p_it != m_Cues.end(); p_it++)
	{
		CUE& comparedCUE = *p_it;
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}
	_bestCUE = bestCue;
	m_HandName = GetCUEName(_bestCUE);

	return _bestCUE;
};
CUE& TexasPlayer::GetBestCUE()
{
	m_Cues = BuildCUEs();
	Evaluator E;
	vector<CUE>::iterator p_it = m_Cues.begin();
	CUE bestCue = m_Cues[0];

	for (p_it = m_Cues.begin() + 1; p_it != m_Cues.end(); p_it++)
	{
		CUE& comparedCUE = *p_it;
		int Compare = E.CompareCues(bestCue, comparedCUE);
		//cout << "Compaired :" << Compare << "\n";
		if (Compare != 1)
		{
			bestCue.clear();
			bestCue = comparedCUE;
		}
	}
	_bestCUE = bestCue;
	m_HandName = GetCUEName(_bestCUE);

	return _bestCUE;
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


void DrawPlayer::ShowBestCue(const CUE& c)
{
	Player::ShowBestHand(c);
}
void StudPlayer::ShowBestCue(const CUE& c)
{
	Player::ShowBestHand(c);
}
void OmahaPlayer::ShowBestCue(const CUE& c)
{
	Player::ShowBestHand(c);
}
void TexasPlayer::ShowBestCue(const CUE& c)
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



void DrawPlayer::GetComCards(vector<const Card*> cards)
{

}
void StudPlayer::GetComCards(vector<const Card*> cards)
{

}
void TexasPlayer::GetComCards(vector<const Card*> cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		m_CommunityCards.push_back(cards[i]);
	}
}
void OmahaPlayer::GetComCards(vector<const Card*> cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		m_CommunityCards.push_back(cards[i]);
	}
}