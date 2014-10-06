#if !defined(EVAL_H__)
#define EVAL_H__
#include <vector>
#include <map>

using namespace std;

class HashEvaluator
{
public:
	HashEvaluator();
	~HashEvaluator();
	


	void MakeHashTable();

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
	static vector<unsigned> m_StraightFlushes;
	static vector<unsigned> m_Quads;
	static vector<unsigned> m_Boats;
	static vector<unsigned> m_Flushs;
	static vector<unsigned> m_Straights;
	static vector<unsigned> m_Trips;
	static vector<unsigned> m_TwoPair;
	static vector<unsigned> m_OnePair;
	static vector<unsigned> m_HighCards;

};





#endif