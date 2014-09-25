#include "Evaluator.h"


Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}

//COMPARES ALL THE SUITS , RETURNS true if all the same

/*
bool Evaluator::IsFlush(const CUE& c)
{
	return  (c[0].GetSuit() == c[1].GetSuit()) &&
		(c[0].GetSuit() == c[2].GetSuit()) &&
		(c[0].GetSuit() == c[3].GetSuit()) &&
		(c[0].GetSuit() == c[4].GetSuit());  //CHECKS IF ALL 5 CARDS ARE THE SAME ,RETUR TRUE IF SO
}

bool Evaluator::IsStraight(const CUE& c)
{
	if (IsWheelStraight(c))
	{
		return true;
	}
	Card::PIP p = c[0].GetPip();
	for (unsigned i = 1; i < c.size(); ++i)
	{
		if (p != c[1].GetPip())
		{
			return false;
		}
	}
	return true;
}

bool Evaluator::IsWheelStraight(const CUE& c)
{
	return 	(c[0].GetPip() == _2) &&
		(c[1].GetPip() == _3) &&
		(c[2].GetPip() == _4) &&
		(c[3].GetPip() == _5) &&
		(c[4].GetPip() == _A);  //RETURNS TRUE IF IT IS A WHEEL STRAIGHT , 
}									//means that Ace is in last position

//ONLY HAVe to check 1st and 4th and 2nd and 5th spot because its aranged..
bool Evaluator::IsBoat(const CUE& c)
{
	return	(c[0].GetPip() == c[3].GetPip()) ||
		(c[1].GetPip() == c[4].GetPip());    //only works because the hands have been sorted
}

bool Evaluator::IsBoat(const CUE& c)
{
	return 		(c[0].getPip() == c[2].GetPip()) &&
		(c[3].getPip() == c[4].GetPip()) ||
		(c[0].getPip() == c[1].GetPip()) &&
		(c[2].getPip() == c[4].GetPip());
}

bool Evaluator::IsTrips(const CUE& c)
{
	return 	(c[0].getPip() == c[2].GetPip()) ||  	//if first and 3rd are same 
		(c[1].getPip() == c[3].GetPip()) ||		//if 2nd and 4th are same 
		(c[2].getPip() == c[4].GetPip());		//if 3rd and 5th are the same
}

bool Evaluator::IsTwoPair(const CUE& c)
{
	return 	(c[0].getPip() == c[1].GetPip()) &&
		(c[2].getPip() == c[3].GetPip()) ||
		(c[0].getPip() == c[1].GetPip()) &&
		(c[3].getPip() == c[4].GetPip()) ||
		(c[1].getPip() == c[2].GetPip()) &&
		(c[3].getPip() == c[4].GetPip())
}

bool Evaluator::IsOnePair(const CUE& c)
{
return 	(c[0].GetPip() == c[1].GetPip()) ||
		(c[1].GetPip() == c[2].GetPip()) ||
		(c[2].GetPip() == c[3].GetPip()) ||
		(c[3].GetPip() == c[4].GetPip());
}




int Evaluator::CompareCues(const CUE& c1, const CUE& c2)
{
	bool f1 = isFlush(c1);
	bool f2 = isFlush(c2);
	bool st1 = isStraight(c1);
	bool st2 = isStraight(c2);


	if (f1 && st1) //c1 is a straight flush
	{
		if (f2 && c2)//c2 is a straight flush
		{
			return compareStraightFlushes(c1, c2);
		}
		return 1;
	}
	if (f2 && st2)
	{
		return -1;
	}
	// neither hand is a straight flush ... next FOUR OF A KIND
	bool q1 = isQuad(c1);
	bool q2 = isQuad(c2);

	if (q1)
	{
		if (q2)
		{
			return compareQuads(c1, c2);
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
			return compareBoats(c1, c2);
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
		if (c2)
		{
			return CompareFlushs(c1, c2)
		}
		return 1;
	}
	if (F2)
	{
		return -1;
	}


	bool st1 = IsStraight(c1);
	bool st2 = IsStraight(c2);
	if (st1)
	{
		if (st2)
		{
			return compareStraights(c1, c2)
		}
		return 1;
	}
	if (st2)
	{
		return -1
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
		return -1
	}

	bool twop1 = IsTwoPair(c1);
	bool twop2 = IsTwoPair(c2);

	if (twop1)
	{
		if (twop2)
		{
			return CompareTwoPairs(c1, c2);
		}
		return 1;
	}
	if (twop2)
	{
		return -1
	}

	bool onep1 = IsOnePair(c1);
	bool onep2 = IsOnePair(c2);

	if (onep1)
	{
		if (onep2)
		{
			return CompareOnePairs(c1, c2);
		}
		return 1;
	}
	if (onep2)
	{
		return -1
	}
	return compareKickers(c1, c2); //COMPARE HIGH CARD IF NO HANDS
};

int Evaluator::CompareKickers(const CUE& c1, const CUE& c2)
{
	for (int i = 4; i >= 0; --i)
	{
		if (c1[i].getPiP > c2[i].GetPiP())
		{
			return 1; //C1 is greater
		}
		if (c1[i].getPiP < c2[i].GetPiP())
		{
			return -1;   //C2 is greater
		}
	}
	return 0;  //BOTH ARE THE SAME 
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

	if (c1[0].GetPip() < c2[0].getPip())
	{
		return -2; //any negative number .. C2 is greater
	}
	if (c1[0].GetPip() > c2[0].getPip())
	{
		return 10; //any positive number.. C1 is greater 
	}
	return 0; //Same
}

int Evaluator::CompareQuads(const CUE& c1, const CUE& c2)
{
	if (c1[2].GetPip() < c2[2].GetPip())
	{
		return -1
	}

	if (c1[2].GetPip() > c2[2].GetPip())
	{
		return 1;
	}
	return compareKickers(c1, c2);
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
	if (c1[3].GetPip() < c2[3].getPip())
	{
		return 1; //second hand higher
	}
	if (c1[3].GetPip() > c2[3].getPip())
	{
		return -1;
	}
	//BOTH HIGHER PAIRS ARE SAME THEN -->
	if (c1[1].GetPip() < c2[1].getPip())
	{
		return 1;
	}
	if (c1[1].GetPip() > c2[1].getPip())
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
Card::PIP GetPipValueofOnePair(const CUE& c)  //Helper function 
{
	if (c[0].GetPip() == c[1].GetPip())
	{
		return c[0].GetPiP();
	}
	if (c[1].GetPip() == c[2].GetPip())
	{
		return c[1].GetPiP();
	}
	if (c[2].GetPip() == c[3].GetPip())
	{
		return c[2].GetPiP();
	}
	if (c[3].GetPip() == c[4].GetPip())
	{
		return c[3].GetPiP();
	}
	//NEED TO RETURN A DUMMY VALUE OR ERROR ...Logic error
	throw std::logic_error("calling GetPipValueofOnePair() on a hand that is not a one pair");
	return _A; //Returns ace.. dummy value
}



*/