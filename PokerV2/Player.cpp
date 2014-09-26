#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Evaluator.h"


void Player::ShowBestHand(vector<const Card*>& c)
{
	try{
		if (c.size() == 5)
		{
			sort(c.begin(), c.end(), HigherCard());
			cout << " Sorted:";
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
	if (E.IsStraight(c))
	{
		cueName = "Straight ";
		return cueName;
	}
	if (E.IsWheelStraight(c))
	{
		cueName = "Wheel Straight ";
		return cueName;
	}
	if (E.IsFlush(c))
	{
		//char value = c[3]->;
		cueName = "Flush ";
		return cueName;
	}
	if (E.IsQuad(c))
	{
		char value = c[3]->GetPip();
		cueName = "Four-o-Kind ";
		return cueName;
	}
	if (E.IsTrips(c))
	{
		char value = c[3]->GetPip();
		cueName = "Three-o-Kind ";
		return cueName;
	}
	if (E.IsTwoPair(c))
	{
		cueName = "Two Pair ";
		return cueName;
	}
	if (E.IsOnePair(c))
	{
		char value = E.GetPipValueofOnePair(c);
		cueName = "One Pair ";
		return cueName;
	}

	else
	{
		cueName = "High Card";
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


void DrawPlayer::GetBestCUE()
{
	vector<const Card*> newCue;
	CUE c(newCue);
	//HAD TO MANUALLY PUSH ON THE m_Hand Cards 
	for (unsigned i = 0; i < 5; ++i)
	{
		c.push_back(m_Hand[i]);
	}
	m_Cues.push_back(c);
	//NOW we mus evaluate the hand ...get his best hand .. this case only one hand to judge
	//therfore this hand is his best :P
	
	vector<CUE>::iterator c_it = m_Cues.begin();
	vector<const Card*> tempBest = *c_it; //create a temp best hand..
	
	
	m_BestHand = c;
	ShowCards();
	ShowBestHand(m_BestHand);

	string Cardname = Player::GetCUEName(c);
	cout << " = " << Cardname << endl;
	
	
	

	for (c_it ; c_it != m_Cues.end(); ++c_it)
	{
	//cout << "Loop working ...YAE!\n\n";
	}

};
void StudPlayer::GetBestCUE()
{

};
void OmahaPlayer::GetBestCUE()
{

};
void TexasPlayer::GetBestCUE()
{

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