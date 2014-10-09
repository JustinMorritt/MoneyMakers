#include "Evaluator.h"
#include <vector>
#include <string>
#include "card.h"

Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}

//COMPARES ALL THE SUITS , RETURNS true if all the same
bool Evaluator::IsQuad(const  CUE& c)
{
	return  (c[0]->GetPip() == c[3]->GetPip()) ||
			(c[1]->GetPip() == c[4]->GetPip());
};

bool Evaluator::IsFlush(const CUE& c)
{
	return  (c[0]->GetSuit() == c[1]->GetSuit()) &&
			(c[0]->GetSuit() == c[2]->GetSuit()) &&
			(c[0]->GetSuit() == c[3]->GetSuit()) &&
			(c[0]->GetSuit() == c[4]->GetSuit());  //CHECKS IF ALL 5 CARDS ARE THE SAME ,RETUR TRUE IF SO
}

bool Evaluator::IsStraight(const CUE& c)
{
	if (IsWheelStraight(c))
	{
		return true;
	}
	Card::PIP p = c[0]->GetPip();
	for (unsigned i = 1; i < c.size(); ++i)
	{
		if (p != c[i]->GetPip())
		{
			return false;
		}
	}
	return true;
}

bool Evaluator::IsWheelStraight(const CUE& c)
{
	return 	(c[0]->GetPip() == 0) &&
			(c[1]->GetPip() == 1) &&
			(c[2]->GetPip() == 2) &&
			(c[3]->GetPip() == 3) &&
			(c[4]->GetPip() == 12);		//RETURNS TRUE IF IT IS A WHEEL STRAIGHT , 
}											//means that Ace is in last position
	
//ONLY HAVe to check 1st and 4th and 2nd and 5th spot because its aranged..
bool Evaluator::IsBoat(const CUE& c)
{
	return	(c[0]->GetPip() == c[1]->GetPip()) &&
			(c[2]->GetPip() == c[4]->GetPip()) ||
			(c[0]->GetPip() == c[2]->GetPip()) &&   //only works because the hands have been sorted
			(c[3]->GetPip() == c[4]->GetPip());
}

bool Evaluator::IsTrips(const CUE& c)
{
	return 	(c[0]->GetPip() == c[2]->GetPip()) ||		//if first and 3rd are same 
			(c[1]->GetPip() == c[3]->GetPip()) ||		//if 2nd and 4th are same 
			(c[2]->GetPip() == c[4]->GetPip());			//if 3rd and 5th are the same
}

bool Evaluator::IsTwoPair(const CUE& c)
{
	return 	(c[0]->GetPip() == c[1]->GetPip()) &&
			(c[2]->GetPip() == c[3]->GetPip()) ||
			(c[0]->GetPip() == c[1]->GetPip()) &&
			(c[3]->GetPip() == c[4]->GetPip()) ||
			(c[1]->GetPip() == c[2]->GetPip()) &&
			(c[3]->GetPip() == c[4]->GetPip());
}

bool Evaluator::IsOnePair(const CUE& c)
{
	return 	(c[0]->GetPip() == c[1]->GetPip()) ||
			(c[1]->GetPip() == c[2]->GetPip()) ||
			(c[2]->GetPip() == c[3]->GetPip()) ||
			(c[3]->GetPip() == c[4]->GetPip());
}




int Evaluator::CompareCues(const CUE& c1, const CUE& c2)
{
	bool f1 = IsFlush(c1);
	bool f2 = IsFlush(c2);
	bool st1 = IsStraight(c1);
	bool st2 = IsStraight(c2);


	if (f1 && st1) //c1 is a straight flush
	{
		if (f2 && st2)//c2 is a straight flush
		{
			return CompareStraightFlushes(c1, c2);
		}
		return 1;
	}
	if (f2 && st2)
	{
		return -1;
	}
	// neither hand is a straight flush ... next FOUR OF A KIND
	bool q1 = IsQuad(c1);
	bool q2 = IsQuad(c2);

	if (q1)
	{
		if (q2)
		{
			return CompareQuads(c1, c2);
		}
		return 1; //hand 1 is greater
	}
	if (q2)
	{
		return -1;
	}

	bool boat1 = IsBoat(c1);
	bool boat2 = IsBoat(c2);

	if (boat1)
	{
		if (boat2)
		{
			return CompareBoats(c1, c2);
		}
		return 1;
	}
	if (boat2)
	{
		return -1;
	}


	bool F1 = IsFlush(c1);
	bool F2 = IsFlush(c2);
	if (F1)
	{
		if (F1 && F2)
		{
			return CompareFlushs(c1, c2);
		}
		return 1;
	}
	if (F2)
	{
		return -1;
	}


	bool str1 = IsStraight(c1);
	bool str2 = IsStraight(c2);
	if (str1)
	{
		if (str2)
		{
			return CompareStraights(c1, c2);
		}
		return 1;
	}
	if (str2)
	{
		return -1;
	}

	bool trips1 = IsTrips(c1);
	bool trips2 = IsTrips(c2);
	if (trips1)
	{
		if (trips2)
		{
			return CompareTrips(c1, c2);
		}
		return 1;
	}
	if (trips2)
	{
		return -1;
	}

	bool twop1 = IsTwoPair(c1);
	bool twop2 = IsTwoPair(c2);

	if (twop1)
	{
		if (twop2)
		{
			return CompareTwoPair(c1, c2);
		}
		return 1;
	}
	if (twop2)
	{
		return -1;
	}

	bool onep1 = IsOnePair(c1);
	bool onep2 = IsOnePair(c2);

	if (onep1)
	{
		if (onep2)
		{
			return CompareOnePair(c1, c2);
		}
		return 1;
	}
	if (onep2)
	{
		return -1;
	}
	return CompareKickers(c1, c2); //COMPARE HIGH CARD IF NO HANDS
};



int Evaluator::CompareKickers(const CUE& c1, const CUE& c2)
{
	for (int i = 4; i >= 0; --i)
	{
		if (c1[i]->GetPip() > c2[i]->GetPip())
		{
			return 1; //C1 is greater
		}
		if (c1[i]->GetPip() < c2[i]->GetPip())
		{
			return -1;   //C2 is greater
		}
	}
	return 0;  //BOTH ARE THE SAME 
};

int Evaluator::CompareStraightFlushes(const CUE& c1, const CUE& c2)
{
	return CompareStraights(c1, c2);
};

int Evaluator::CompareStraights(const CUE& c1, const CUE& c2)
{
	bool w1 = IsWheelStraight(c1);
	bool w2 = IsWheelStraight(c2);
	if (w1)
	{
		if (w2)
		{
			return 0;
		}
		return -1;
	}
	if (w2)
	{
		return 1;
	}

	if (c1[0]->GetPip() < c2[0]->GetPip())
	{
		return -2; //any negative number .. C2 is greater
	}
	if (c1[0]->GetPip() > c2[0]->GetPip())
	{
		return 10; //any positive number.. C1 is greater 
	}
	return 0; //Same
}

int Evaluator::CompareQuads(const CUE& c1, const CUE& c2)
{
	if (c1[2]->GetPip() < c2[2]->GetPip())
	{
		return -1;
	}

	if (c1[2]->GetPip() > c2[2]->GetPip())
	{
		return 1;
	}
	return CompareKickers(c1, c2);
}

int Evaluator::CompareBoats(const CUE& c1, const CUE& c2)
{
	return CompareQuads(c1, c2); // you can use the same comparison algorithm and it works.
}

int Evaluator::CompareFlushs(const CUE& c1, const CUE& c2)
{
	return CompareKickers(c1, c2);
}

int Evaluator::CompareTrips(const CUE& c1, const CUE& c2)
{
	return CompareQuads(c1, c2); //Checks all middle values
}

int Evaluator::CompareTwoPair(const CUE& c1, const CUE& c2)
{
	if (c1[3]->GetPip() < c2[3]->GetPip())
	{
		return 1; //second hand higher
	}
	if (c1[3]->GetPip() > c2[3]->GetPip())
	{
		return -1;
	}
	//BOTH HIGHER PAIRS ARE SAME THEN -->
	if (c1[1]->GetPip() < c2[1]->GetPip())
	{
		return 1;
	}
	if (c1[1]->GetPip() > c2[1]->GetPip())
	{
		return -1;
	}
	return CompareKickers(c1, c2);
}

int Evaluator::CompareOnePair(const CUE& c1, const CUE& c2)
{
	if (GetPipValueofOnePair(c1) < GetPipValueofOnePair(c2))
	{
		return -1;
	}
	if (GetPipValueofOnePair(c1) > GetPipValueofOnePair(c2))
	{
		return 1;
	}
	return CompareKickers(c1, c2); //both pairs are the same... compares the kicker code.
}

//WARNING DO NOT CALL ON ANY HAND THAT IS NOT A ONE PAIR
int Evaluator::GetPipValueofOnePair(const CUE& c)  //Helper function 
{
	if (c[0]->GetPip() == c[1]->GetPip())
	{
		return c[0]->GetPip();
	}
	if (c[1]->GetPip() == c[2]->GetPip())
	{
		return c[1]->GetPip();
	}
	if (c[2]->GetPip() == c[3]->GetPip())
	{
		return c[2]->GetPip();
	}
	if (c[3]->GetPip() == c[4]->GetPip())
	{
		return c[3]->GetPip();
	}
	//NEED TO RETURN A DUMMY VALUE OR ERROR ...Logic error
	throw std::logic_error("calling GetPipValueofOnePair() on a hand that is not a one pair");
	return 12; //Returns ace.. dummy value
}







//HASH EVALUATOR **************************************
HashEvaluator::HashEvaluator()
{
	MakeHashTable();
}
HashEvaluator::~HashEvaluator()
{
}


map<unsigned, pair<unsigned, string>>  HashEvaluator::m_HashTable;
const unsigned HashEvaluator::PrimeNumbers[]{1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
const unsigned HashEvaluator::FlushPrimeNum[]{41};
const unsigned HashEvaluator::HandSize = 5;
int HashEvaluator::TableMade = 0;


void HashEvaluator::MakeHashTable()
{
	if (TableMade == 0)//Making sure only one hash table is made.
	{
		//MAKE ALL THE VECTORS
		cout << "\nInitiating HashTable Building Sequence.";
		HashStraightFlushes();
		HashQuads();
		HashBoats();
		HashFlushs();
		cout << ".";
		HashStraights();
		cout << ".";
		HashTrips();
		cout << ".";
		HashTwoPair();
		cout << ".";
		HashOnePair();
		cout << ".";
		HashHighCards();
		cout << "Complete\n\n";
		TableMade = 1;
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
	string rankName = " Wheel Straight Flush  :P";
	m_HashTable.insert(make_pair(hashResult, make_pair(9, rankName)));
	hashResult = 1;
	for (unsigned i = 0; i < maxPIP - 3; ++i)
	{
		//hashOutput << "Hand ";
		unsigned last;
		for (unsigned j = i; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			hashResult *= FlushPrimeNum[0];
			last = j;
			//hashOutput << Card::PIP_CHARS[j] << " * ";
		}
		//this->m_Straights.push_back(hashResult);
		//cout << " = " << hashResult << " Straight Flush " << Card::PIP_CHARS[i] << " to " << Card::PIP_CHARS[last] << endl;

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
				//cout << " = " << hashResult << " <---Quad " << Card::PIP_CHARS[i] << "'s " << endl;
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
								//thinking of pushing values onto the map here .. check if duplicates..

								string rankName = "Flush "; //rankName += Card::SUIT_CHARS[i]; rankName += "'s ";
								m_HashTable.insert(make_pair(hashResult, make_pair(6, rankName)));
								//cout << " = " << hashResult << " <---Flush of " << Card::SUIT_CHARS[i] << "'s" << endl;
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
		//hashOutput << "Hand ";
		unsigned last;
		for (unsigned j = i; j < (i + 5); ++j)
		{
			hashResult *= PrimeNumbers[j];
			last = j;
			//hashOutput << Card::PIP_CHARS[j] << " * ";
		}
		//this->m_Straights.push_back(hashResult);
		//hashOutput << " = " << hashResult << " <---Straight " << endl;

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
						hashResult *= PrimeNumbers[j];
						hashResult *= PrimeNumbers[j];
						hashResult *= PrimeNumbers[l];
						//hashOutput << Card::PIP_CHARS[l] << " * ";
						//this->m_TwoPair.push_back(hashResult);
						//hashOutput << " = " << hashResult << " <---Two Pair " << endl;
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


unsigned HashEvaluator::GetHash(CUE& cards) const
{
	
	if (cards[0]->GetSuit() == cards[1]->GetSuit() &&
		cards[0]->GetSuit() == cards[2]->GetSuit() &&
		cards[0]->GetSuit() == cards[3]->GetSuit() &&
		cards[0]->GetSuit() == cards[4]->GetSuit())
	{

	unsigned ret = 1;
	for (unsigned i = 0; i < cards.size(); ++i)
	{
	//cout << cards[i]->GetPip();
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
		//cout << cards[i]->GetPip();
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
string HashEvaluator::GetName(unsigned hash, CUE& cards) const
{
	if (GetValue(hash) < 1)
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
	pair<unsigned, string> rank = HashEvaluator::m_HashTable[hash];
	string name = get<1>(rank);
	return name;
}


