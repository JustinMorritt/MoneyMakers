#if !defined(EVAL_H__)
#define EVAL_H__
#include <map>
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



class HashEvaluator
{
public:
	HashEvaluator();
	~HashEvaluator();

	void MakeHashTable();
	void OutPutMap() const;
	unsigned GetHash(vector<const Card*>& cards) const;
	unsigned GetValue(unsigned hash) const;
	string GetName(unsigned hash, vector<const Card*>& cards) const;
	map<unsigned, pair<unsigned, string>>& GetMap()const;

	void HashStraightFlushes();
	void HashQuads();
	void HashBoats();
	void HashFlushs();
	void HashStraights();
	void HashTrips();
	void HashTwoPair();
	void HashOnePair();
	void HashHighCards();

private:
	static int TableMade;
	const static unsigned PrimeNumbers[];
	const static unsigned FlushPrimeNum[];
	const static unsigned HandSize;
	static map<unsigned, pair<unsigned, string>> m_HashTable; //first create the pair then insert the unsigned and pair together .
};



#endif