#include <iostream>
#include <utility> 
#include <string>
#include <fstream>
#include "HashEvaluator.h"
#include "card.h"

using namespace std;

ofstream hashOutput("hashOutput.txt");


HashEvaluator::HashEvaluator()
{
	MakeHashTable();
}



HashEvaluator::~HashEvaluator()
{
}
//HASH EVALUATOR **************************************
map<unsigned, pair<unsigned, string>>  HashEvaluator::m_HashTable;
vector<unsigned> HashEvaluator::m_StraightFlushes;
vector<unsigned> HashEvaluator::m_Quads;
vector<unsigned> HashEvaluator::m_Boats;
vector<unsigned> HashEvaluator::m_Flushs;
vector<unsigned> HashEvaluator::m_Straights;
vector<unsigned> HashEvaluator::m_Trips;
vector<unsigned> HashEvaluator::m_TwoPair;
vector<unsigned> HashEvaluator::m_OnePair;
vector<unsigned> HashEvaluator::m_HighCards;
const unsigned HashEvaluator::PrimeNumbers[]{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
const unsigned HashEvaluator::FlushPrimeNum[]{41};
const unsigned HashEvaluator::HandSize = 5;
int HashEvaluator::TableMade = 0;


void HashEvaluator::MakeHashTable() 
{
	
	if (TableMade == 0)//Making sure only one hash table is made.
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
		hashOutput.close();
	}

}

void HashEvaluator::HashStraightFlushes()
{
	unsigned maxPIP = 12;
	unsigned hashResult = 1;

	//TAKE CARE OF THE WHEEL STRAIGHT
	hashResult *= PrimeNumbers[12];
	hashResult *= FlushPrimeNum[0];
	for (unsigned i = 0; i < 4; ++i)
	{
		hashResult *= PrimeNumbers[i];
		hashResult *= FlushPrimeNum[0];
	}
	//hashOutput << "Hand " << Card::PIP_CHARS[12] << " * " << Card::PIP_CHARS[0] << " * " << Card::PIP_CHARS[1] << " * " << Card::PIP_CHARS[2] << " * " << Card::PIP_CHARS[3] << " * ";
	//hashOutput << " = " << hashResult << " <---Wheel Straight " << endl;
	string rankName = " Wheel Straight Flush";
	m_HashTable.insert(make_pair(hashResult, make_pair(10, rankName)));
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		//hashOutput << "Hand ";
		for (unsigned j = i; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			hashResult *= FlushPrimeNum[0];
			//hashOutput << Card::PIP_CHARS[j] << " * ";
		}
		//this->m_Straights.push_back(hashResult);
		//hashOutput << " = " << hashResult << " <---Straight " << endl;

		string rankName = " Straight Flush";
		m_HashTable.insert(make_pair(hashResult, make_pair(11, rankName)));

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
				//hashOutput << "Hand ";
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4)
					{
						hashResult *= PrimeNumbers[j];
					//	hashOutput << Card::PIP_CHARS[j] << " * ";
					}
					else
					{
						hashResult *= PrimeNumbers[i];
					//	hashOutput << Card::PIP_CHARS[i] << " * ";
					}
				}
				//this->m_Quads.push_back(hashResult);
				//	hashOutput << " = " << hashResult << " <---Quad " << endl;
				string rankName = " Four-O-Kind";
				m_HashTable.insert(make_pair(hashResult, make_pair(9, rankName)));

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
				//hashOutput << "Hand ";
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4 || k == 3)
					{
						hashResult *= PrimeNumbers[j];
					//	hashOutput << Card::PIP_CHARS[j] << " * ";
					}
					else
					{
						hashResult *= PrimeNumbers[i];
					//	hashOutput << Card::PIP_CHARS[i] << " * ";
					}
				}
				//this->m_Boats.push_back(hashResult);
			//	hashOutput << " = " << hashResult << " <---Boat " << endl;
				
				string rankName = " Full House";
				m_HashTable.insert(make_pair(hashResult, make_pair(8, rankName)));

				hashResult = 1;
			}
		}
	}

}
void HashEvaluator::HashFlushs()
{
	// value 7



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
	//hashOutput << "Hand " << Card::PIP_CHARS[12] << " * " << Card::PIP_CHARS[0] << " * " << Card::PIP_CHARS[1] << " * " << Card::PIP_CHARS[2] << " * " << Card::PIP_CHARS[3] << " * ";
	//hashOutput << " = " << hashResult << " <---Wheel Straight " << endl;
	string rankName = " --> Wheel Straight";
	m_HashTable.insert(make_pair(hashResult, make_pair(5, rankName)));
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		//hashOutput << "Hand ";
		unsigned last;
		for (unsigned j = i ; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			last = j;
			//hashOutput << Card::PIP_CHARS[j] << " * ";
		}
		//this->m_Straights.push_back(hashResult);
		//hashOutput << " = " << hashResult << " <---Straight " << endl;
		
		string rankName = " Straight "; rankName += Card::PIP_CHARS[i]; rankName += " to "; rankName += Card::PIP_CHARS[last]; 
		m_HashTable.insert(make_pair(hashResult, make_pair(6, rankName)));

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
						//hashOutput << "Hand ";
						hashResult *= PrimeNumbers[i];
					    //hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
						//hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
					    //hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[j];
						//hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[l];
						//hashOutput << Card::PIP_CHARS[l] << " * ";
						//this->m_Trips.push_back(hashResult);
						//hashOutput << " = " << hashResult << " <--- Three - o - Kind " << endl;

						string rankName = " Three-o-Kind "; rankName += Card::PIP_CHARS[i]; rankName += "'s ";
						m_HashTable.insert(make_pair(hashResult, make_pair(4, rankName)));
						hashResult = 1;
					}
				}
			}
		}
	}
}
void HashEvaluator::HashTwoPair()
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
					//	hashOutput << "Hand ";
						hashResult *= PrimeNumbers[i];
						//hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
					//	hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[j];
						//hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[j];
					//	hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[l];
						//hashOutput << Card::PIP_CHARS[l] << " * ";
						//this->m_TwoPair.push_back(hashResult);
						//hashOutput << " = " << hashResult << " <---Two Pair " << endl;
						string rankName = "2 Pairs "; rankName += Card::PIP_CHARS[i]; rankName += "'s "; 
						rankName += "& "; rankName += Card::PIP_CHARS[j]; rankName += "'s ";
						m_HashTable.insert(make_pair(hashResult, make_pair(3, rankName)));
						//hashOutput << " = " << hashResult << " <---One Pair " << endl;
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
								
								string rankName = " Pair of "; rankName += Card::PIP_CHARS[i]; rankName += "'s ";
								m_HashTable.insert(make_pair(hashResult, make_pair(2, rankName)));
								//hashOutput << " = " << hashResult << " <---One Pair " << endl;
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
	unsigned ret = 1;
	for (unsigned i = 0; i < cards.size(); ++i )
	{
		//cout << cards[i]->GetPip();
		ret *= HashEvaluator::PrimeNumbers[cards[i]->GetPip()];
	}
	return ret;
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
string HashEvaluator::GetName(unsigned hash) const
{
	pair<unsigned, string> rank = m_HashTable[hash];
	string name = get<1>(rank);
	return name;
}
