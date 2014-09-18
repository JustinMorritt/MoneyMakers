#include "Player.h"

void DrawPlayer::ShowCards()
{
	for (vector<const Card*>::iterator c_it = m_Hand.begin(); c_it != m_Hand.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << " " << p->ToString() << " ";
	}
};

void StudPlayer::ShowCards()
{
	for (vector<const Card*>::iterator c_it = m_Hand.begin(); c_it != m_Hand.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << " " << p->ToString() << " ";
	}
};

void OmahaPlayer::ShowCards()
{
	for (vector<const Card*>::iterator c_it = m_Hand.begin(); c_it != m_Hand.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << " " << p->ToString() << " ";
	}
};

void TexasPlayer::ShowCards()
{
	for (vector<const Card*>::iterator c_it = m_Hand.begin(); c_it != m_Hand.end(); ++c_it)
	{
		const Card* p = *c_it;
		cout << " " << p->ToString() << " ";
	}
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