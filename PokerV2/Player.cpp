#include "Player.h"

void DrawPlayer::ShowCards()
{
	for (int i = 0; i <= sizeof(m_Hand); ++i)
	{
		const Card* p = m_Hand[i];
		cout << " " << p->ToString() << " ";
	}
};

void StudPlayer::ShowCards()
{
	for (int i = 0; i <= sizeof(m_Hand); ++i)
	{
		const Card* p = m_Hand[i];
		cout << " " << p->ToString() << " ";
	}
};

void OmahaPlayer::ShowCards()
{
	for (int i = 0; i <= sizeof(m_Hand); ++i)
	{
		const Card* p = m_Hand[i];
		cout << " " << p->ToString() << " ";
	}
};

void TexasPlayer::ShowCards()
{
	for (int i = 0; i <= sizeof(m_Hand); ++i)
	{
		const Card* p = m_Hand[i];
		cout << " " << p->ToString() << " ";
	}
};