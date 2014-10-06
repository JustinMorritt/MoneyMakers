#include <iostream>
#include <fstream>
# include <algorithm>
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
		hashOutput << "\n ";
		HashQuads();
		hashOutput << "\n ";
		HashBoats();
		hashOutput << "\n ";
		HashFlushs();
		hashOutput << "\n ";
		HashStraights();
		hashOutput << "\n ";
		HashTrips();
		hashOutput << "\n ";
		HashTwoPair();
		hashOutput << "\n ";
		HashOnePair();
		hashOutput << "\n ";
	    HashHighCards();
		hashOutput << "\n ";
		TableMade = 1;

		hashOutput.close();
	}

}

void HashEvaluator::HashStraightFlushes()
{

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
				hashOutput << "Hand ";
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4)
					{
						hashResult *= PrimeNumbers[j];
						hashOutput << Card::PIP_CHARS[j] << " * ";
					}
					else
					{
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
					}
				}
				this->m_Quads.push_back(hashResult);
				hashOutput << " = " << hashResult << " <---Quad " << endl;
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
				hashOutput << "Hand ";
				for (unsigned k = 0; k < HandSize; ++k)
				{
					if (k == 4 || k == 3)
					{
						hashResult *= PrimeNumbers[j];
						hashOutput << Card::PIP_CHARS[j] << " * ";
					}
					else
					{
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
					}
				}
				this->m_Boats.push_back(hashResult);
				hashOutput << " = " << hashResult << " <---Boat " << endl;
				hashResult = 1;
			}
		}
	}

}
void HashEvaluator::HashFlushs()
{

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
	hashOutput << "Hand " << Card::PIP_CHARS[12] << " * " << Card::PIP_CHARS[0] << " * " << Card::PIP_CHARS[1] << " * " << Card::PIP_CHARS[2] << " * " << Card::PIP_CHARS[3] << " * ";
	hashOutput << " = " << hashResult << " <---Wheel Straight " << endl;
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		hashOutput << "Hand ";
		for (unsigned j = i ; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			hashOutput << Card::PIP_CHARS[j] << " * ";
		}
		this->m_Straights.push_back(hashResult);
		hashOutput << " = " << hashResult << " <---Straight " << endl;
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
						hashOutput << "Hand ";
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[j];
						hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[l];
						hashOutput << Card::PIP_CHARS[l] << " * ";
						this->m_Trips.push_back(hashResult);
						hashOutput << " = " << hashResult << " <--- Three - o - Kind " << endl;
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
						hashOutput << "Hand ";
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[i];
						hashOutput << Card::PIP_CHARS[i] << " * ";
						hashResult *= PrimeNumbers[j];
						hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[j];
						hashOutput << Card::PIP_CHARS[j] << " * ";
						hashResult *= PrimeNumbers[l];
						hashOutput << Card::PIP_CHARS[l] << " * ";
						this->m_TwoPair.push_back(hashResult);
						hashOutput << " = " << hashResult << " <---Two Pair " << endl;
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
								hashOutput << "Hand ";
								hashResult *= PrimeNumbers[i];
								hashOutput << Card::PIP_CHARS[i] << " * ";
								hashResult *= PrimeNumbers[i];
								hashOutput << Card::PIP_CHARS[i] << " * ";
								hashResult *= PrimeNumbers[j];
								hashOutput << Card::PIP_CHARS[j] << " * ";
								hashResult *= PrimeNumbers[m];
								hashOutput << Card::PIP_CHARS[m] << " * ";
								hashResult *= PrimeNumbers[l];
								hashOutput << Card::PIP_CHARS[l] << " * ";
								//if (find(m_OnePair.begin(), m_OnePair.end(), hashResult) != m_OnePair.end())
								//{http://www.cplusplus.com/reference/algorithm/none_of/
									this->m_OnePair.push_back(hashResult);
									hashOutput << " = " << hashResult << " <---One Pair " << endl;
								//}
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