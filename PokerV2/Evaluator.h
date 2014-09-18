#if !defined(EVAL_H__)
#define EVAL_H__

#include "cue.h"


class Evaluator
{
public:
	Evaluator();
	~Evaluator();
	int compareCues(const CUE& cl, const CUE& c2);

	int compareKickers(const CUE& c1, const CUE& c2);

	int compareStraightFlushes(const CUE& c1, const CUE& c2);
	bool isFlush(const CUE& c);
	bool isStraight(const CUE& c);

	bool isQuad(const CUE& c);
	int compareQuads(const CUE& c);

	bool IsBoat(const CUE& c); //FULL HOUSE 
	int compareBoats(const CUE& c1, const CUE& c2);

	bool IsFlush(const CUE& c);
	int compareFlushs(const CUE& c1, const CUE& c2);

	bool IsStraight(const CUE& c);
	int compareStraights(const CUE& c1, const CUE& c2);

	bool IsTrips(const CUE& c);
	int compareTrips(const CUE& c1, const CUE& c2);

	bool IsTwoPair(const CUE& c);
	int compareTwoPair(const CUE& c1, const CUE& c2);

	bool IsOnePair(const CUE& c);
	int compareOnePair(const CUE& c1, const CUE& c2);

};

#endif