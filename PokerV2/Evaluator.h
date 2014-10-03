#if !defined(EVAL_H__)
#define EVAL_H__

#include "cue.h"

class Evaluator
{
public:
	Evaluator();
	~Evaluator();

	bool IsQuad(const  CUE& c);
	bool IsBoat(const CUE& c); //FULL HOUSE 
	bool IsFlush(const CUE& c);
	bool IsStraight(const CUE& c);
	bool IsWheelStraight(const CUE& c);
	bool IsTrips(const CUE& c);
	bool IsTwoPair(const CUE& c);
	bool IsOnePair(const CUE& c);
	
	int CompareCues(const CUE& cl, const CUE& c2);
	int CompareStraightFlushes(const CUE& c1, const CUE& c2);
	int CompareQuads(const CUE& c1, const CUE& c2);
	int CompareBoats(const CUE& c1, const CUE& c2);
	int CompareFlushs(const CUE& c1, const CUE& c2);
	int CompareStraights(const CUE& c1, const CUE& c2);
	int CompareTrips(const CUE& c1, const CUE& c2);
	int CompareTwoPair(const CUE& c1, const CUE& c2);
	int CompareOnePair(const CUE& c1, const CUE& c2);
	int CompareKickers(const CUE& c1, const CUE& c2);
	int GetPipValueofOnePair(const CUE& c);
};
#endif