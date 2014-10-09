#if !defined(EVAL_H__)
#define EVAL_H__
#include <vector>
#include "card.h"
#include <map>

using namespace std;

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