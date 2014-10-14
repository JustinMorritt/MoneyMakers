#include <iostream>
#include <string>
#include <fstream>
#include "HashEvaluator.h"
#include "card.h"

using namespace std;


HashEvaluator::HashEvaluator()
{
	MakeHashTable();
}
HashEvaluator::~HashEvaluator()
{
}
//HASH EVALUATOR **************************************
map<unsigned, pair<unsigned, string>> HashEvaluator::m_HashTable;
const unsigned HashEvaluator::PrimeNumbers[]{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
const unsigned HashEvaluator::FlushPrimeNum[]{41};
const unsigned HashEvaluator::HandSize = 5;
int HashEvaluator::TableMade = 0;
int HashEvaluator::rank = 1;


void HashEvaluator::MakeHashTable() 
{
	if (TableMade == 0)
	{
		//MAKE ALL THE VECTORS
		HashStraightFlushes();
		HashQuads();
		HashBoats();
		HashFlushs();
		HashStraights();
		HashTrips();
		HashTwoPair();
		HashOnePair();
	    HashHighCards();

		TableMade = 1;
		cout << "\n\nOutputing map ... . ";
		OutPutMap();
		cout << "Complete..." << m_HashTable.size() << " elements..\n";
	}
}

void HashEvaluator::HashStraightFlushes()
{
	unsigned maxPIP = 13;
	unsigned hashResult = 1;
	//TAKE CARE OF THE WHEEL STRAIGHT
	hashResult *= PrimeNumbers[12];
	hashResult *= FlushPrimeNum[0];
	for (unsigned i = 0; i < 4; ++i)
	{
		hashResult *= PrimeNumbers[i];
		hashResult *= FlushPrimeNum[0];
	}
	string rankName = " Wheel Straight Flush  :P";
	m_HashTable.insert(make_pair(hashResult, make_pair(9, rankName)));
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		unsigned last;
		for (unsigned j = i; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			hashResult *= FlushPrimeNum[0];
			last = j;
		}

		if (last == 12)
		{
			string rankName = " ROYAL Flush!! "; rankName += Card::PIP_CHARS[i]; rankName += " to "; rankName += Card::PIP_CHARS[last];
			m_HashTable.insert(make_pair(hashResult, make_pair(11, rankName)));
		}
		string rankName = " Straight Flush "; rankName += Card::PIP_CHARS[i]; rankName += " to "; rankName += Card::PIP_CHARS[last];
		m_HashTable.insert(make_pair(hashResult, make_pair(10, rankName)));

		hashResult = 1;
	}
}
void HashEvaluator::HashQuads()
{
	unsigned maxPIP = 13;
	unsigned hashResult = 1;
	for (unsigned i = 0; i < maxPIP; ++i)
	{
		for (unsigned j = 0; j < maxPIP; ++j)
		{
			if (j != i)
			{
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4)
					{
						hashResult *= PrimeNumbers[j];
					}
					else
					{
						hashResult *= PrimeNumbers[i];
					}
				}

			
				string rankName = " Four-O-Kind "; rankName += Card::PIP_CHARS[i]; rankName += "'s  "; rankName += Card::PIP_CHARS[j]; rankName += " High";
				m_HashTable.insert(make_pair(hashResult, make_pair(8, rankName)));

				hashResult = 1;
			}
		}
	}
}
void HashEvaluator::HashBoats()
{
	unsigned maxPIP = 12;
	unsigned hashResult = 1;
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP; ++i)
	{
		for (unsigned j = 0; j < maxPIP; ++j)
		{
			if (j != i)
			{
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4 || k == 3)
					{
						hashResult *= PrimeNumbers[j];
					}
					else
					{
						hashResult *= PrimeNumbers[i];
					}
				}

				
				string rankName = "Full House "; rankName += Card::PIP_CHARS[j]; rankName += "'s & "; rankName += Card::PIP_CHARS[i]; rankName += "'s ";
				m_HashTable.insert(make_pair(hashResult, make_pair(7, rankName)));

				hashResult = 1;
			}
		}
	}

}
void HashEvaluator::HashFlushs()
{
	unsigned maxPIP = 13;
	unsigned hashResult = 1;
	hashResult = 1;
	for (unsigned h = 0; h < maxPIP; ++h)
	{
		for (unsigned i = 0; i < maxPIP; ++i)
		{
			for (unsigned j = 0; j < maxPIP; ++j)
			{
				for (unsigned m = 0; m < maxPIP; ++m)
				{
					if (m != i && m != j && m != h)
					{
						for (unsigned l = 0; l < maxPIP; ++l)
						{
							if (l != i  && l != j && l != m && l != h)
							{
								hashResult *= PrimeNumbers[h]; hashResult *= FlushPrimeNum[0];
								hashResult *= PrimeNumbers[i]; hashResult *= FlushPrimeNum[0];
								hashResult *= PrimeNumbers[j]; hashResult *= FlushPrimeNum[0];
								hashResult *= PrimeNumbers[m]; hashResult *= FlushPrimeNum[0];
								hashResult *= PrimeNumbers[l]; hashResult *= FlushPrimeNum[0];
								string rankName = "Flush "; 
								m_HashTable.insert(make_pair(hashResult, make_pair(6, rankName)));
								hashResult = 1;
							}
						}
					}
				}
			}
		}
	}
}
void HashEvaluator::HashStraights()
{
	unsigned maxPIP = 12;
	unsigned hashResult = 1;

	//TAKE CARE OF THE WHEEL STRAIGHT
	hashResult *= PrimeNumbers[12];
	for (unsigned i = 0; i < 4; ++i)
	{
		hashResult *= PrimeNumbers[i];
	}
	string rankName = "--> Wheel Straight";
	m_HashTable.insert(make_pair(hashResult, make_pair(4, rankName)));
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		unsigned last;
		for (unsigned j = i ; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			last = j;
		}
		
		string rankName = "Straight "; rankName += Card::PIP_CHARS[i]; rankName += " to "; rankName += Card::PIP_CHARS[last]; 
		m_HashTable.insert(make_pair(hashResult, make_pair(5, rankName)));
		hashResult = 1;
	}
}
void HashEvaluator::HashTrips()
{
	unsigned maxPIP = 12;
	unsigned hashResult = 1;
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP; ++i)
	{
		for (unsigned j = 0; j < maxPIP; ++j)
		{
			if (j != i)
			{
				for (unsigned l = 0; l < maxPIP; ++l)
				{
					if (l != i  && l != j)
					{
						hashResult *= PrimeNumbers[i];
						hashResult *= PrimeNumbers[i];
						hashResult *= PrimeNumbers[i];
						hashResult *= PrimeNumbers[j];
						hashResult *= PrimeNumbers[l];
						string rankName = "Three-o-Kind "; rankName += Card::PIP_CHARS[i]; rankName += "'s ";
						m_HashTable.insert(make_pair(hashResult, make_pair(3, rankName)));
						hashResult = 1;
					}
				}
			}
		}
	}
}
void HashEvaluator::HashTwoPair()
{
	unsigned maxPIP = 13;
	unsigned hashResult = 1;
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP; ++i)
	{
		for (unsigned j = 0; j < maxPIP; ++j)
		{
			if (j != i)
			{
				for (unsigned l = 0; l < maxPIP; ++l)
				{
					if (l != i  && l != j)
					{
						hashResult *= PrimeNumbers[i];
						hashResult *= PrimeNumbers[i];
						hashResult *= PrimeNumbers[j];
						hashResult *= PrimeNumbers[j];
						hashResult *= PrimeNumbers[l];
						string rankName = "2 Pairs "; rankName += Card::PIP_CHARS[i]; rankName += "'s "; 
						rankName += "& "; rankName += Card::PIP_CHARS[j]; rankName += "'s ";
						m_HashTable.insert(make_pair(hashResult, make_pair(2, rankName)));
						hashResult = 1;
				
					}	
				}	
			}
		}
	}
}
void HashEvaluator::HashOnePair()
{
	unsigned maxPIP = 13;
	unsigned hashResult = 1;
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP; ++i)
	{
		for (unsigned j = 0; j < maxPIP; ++j)
		{
			if (j != i)
			{
				for (unsigned m = 0; m < maxPIP; ++m)
				{
					if (m != i && m != j)
					{
						for (unsigned l = 0; l < maxPIP; ++l)
						{
							if (l != i  && l != j && l != m)
							{
								hashResult *= PrimeNumbers[i];
								hashResult *= PrimeNumbers[i];
								hashResult *= PrimeNumbers[j];
								hashResult *= PrimeNumbers[m];
								hashResult *= PrimeNumbers[l];
								//thinking of pushing values onto the map here .. check if duplicates..
								
								string rankName = "Pair of "; rankName += Card::PIP_CHARS[i]; rankName += "'s ";
								m_HashTable.insert(make_pair(hashResult, make_pair(1, rankName)));
								hashResult = 1;
							}
						}
					}
				}
			}
		}
	}
}
void HashEvaluator::HashHighCards()
{

}


unsigned HashEvaluator::GetHash(vector<const Card*>& cards) const
{
	
	if (cards[0]->GetSuit() == cards[1]->GetSuit() &&
		cards[0]->GetSuit() == cards[2]->GetSuit() &&
		cards[0]->GetSuit() == cards[3]->GetSuit() &&
		cards[0]->GetSuit() == cards[4]->GetSuit())
	{

		unsigned ret = 1;
		for (unsigned i = 0; i < cards.size(); ++i)
		{
			ret *= HashEvaluator::PrimeNumbers[cards[i]->GetPip()];
			ret *= HashEvaluator::FlushPrimeNum[0];
		}
		return ret;

	}
	else
	{
		unsigned ret = 1;
		for (unsigned i = 0; i < cards.size(); ++i)
		{
			ret *= HashEvaluator::PrimeNumbers[cards[i]->GetPip()];
		}
		return ret;
	}
}
map<unsigned, pair<unsigned, string>>& HashEvaluator::GetMap() const
{
	return m_HashTable;
}
unsigned HashEvaluator::GetValue(unsigned hash) const
{
	pair<unsigned, string> rank = m_HashTable[hash];
	unsigned Rank = get<0>(rank);
	return Rank;
}
string HashEvaluator::GetName(unsigned hash, vector<const Card*>& cards) const
{
	if (GetValue(hash) < 1 )
	{
		char high = cards[0]->GetPip();
		for (unsigned i = 0; i < cards.size(); i++)
		{
			if (cards[i]->GetPip() > high)
			{
				high = cards[i]->GetPip();
			}
		}
		string name; name += Card::PIP_CHARS[high]; name += " High";
		return name;
	}
	pair<unsigned, string> rank = m_HashTable[hash];
	string name = get<1>(rank);
	return name;
}
void HashEvaluator::OutPutMap() const
{
	ofstream hashOutput("hashOutput.txt");
	
	for (map<unsigned, pair<unsigned, string>>::iterator it = m_HashTable.begin(); it != m_HashTable.end(); ++it)
	{
		hashOutput << "Hash #: ";
		hashOutput << it->first << " Rank=> ";
		hashOutput << it->second.first << "Name=>";
		hashOutput << it->second.second << "\n";
	}

	hashOutput.close();
		
}