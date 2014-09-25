#include <algorithm>
#include "Player.h"



vector<const Card*> Player::Sort(vector<const Card*> cards)
{
	vector<const Card*> newHand; //CREATE TEMP HAND
	int card = 0;
	for (int i = 0; i <= 12 && newHand.size() != cards.size(); ++i) //ITERATES THROUGH EACH PIP VALUE STARTING WITH LOWEST ---> ACE
	{
		for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
		{
			const Card* p = *c_it;
			if (p->GetPip() == card)
			{
				newHand.push_back(p);
			}
		}
		card++;
	}
	cards = newHand; //Assign cards the NEW SORTED HAND
	newHand.erase(newHand.begin(), newHand.end()); //Erase the temp hand
	cout << "Sorted Hand ! ---->";
	return cards;
};

void Player::Show(vector<const Card*>& cards) const
{
	for (vector<const Card*>::iterator c_it = cards.begin(); c_it != cards.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << " " << p->ToString() << " ";
	}
}


void DrawPlayer::SortHand()
{
	m_Hand = Sort(m_Hand);
};
void StudPlayer::SortHand()
{
	m_Hand = Sort(m_Hand);
};
void OmahaPlayer::SortHand()
{
	m_Hand = Sort(m_Hand);
};
void TexasPlayer::SortHand()
{
	m_Hand = Sort(m_Hand);
};


void DrawPlayer::GetBestCUE()
{
	CUE c(m_Hand);
	m_Cues.push_back(c);
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


void DrawPlayer::ShowCards()
{
	//Player::Show(m_Hand);
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