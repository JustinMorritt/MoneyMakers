#include "Player.h"

vector<const Card*> Player::Sort(vector<const Card*> cards)
{
	return cards;
};

void Player::Show(vector<const Card*> cards)
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