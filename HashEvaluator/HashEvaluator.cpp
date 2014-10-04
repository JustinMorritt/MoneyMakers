#include "HashEvaluator.h"


HashEvaluator::~HashEvaluator()
{
}
//HASH EVALUATOR **************************************
int HashEvaluator::TableMade = 0;
const unsigned HashEvaluator::PrimeNumbers[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
const unsigned HashEvaluator::FlushPrimeNum[]{41};
const unsigned HashEvaluator::HandSize = 5;
void HashEvaluator::MakeHashTable() const
{
	if (TableMade == 0)//Making sure only one hash table is made.
	{
		//MAKE ALL THE VECTORS
		void HashStraightFlushes();
		void HashQuads();
		void HashBoats();
		void HashFlushs();
		void HashStraights();
		void HashTrips();
		void HashTwoPair();
		void HashOnePair();
		void HashHighCards();
		TableMade = 1;
	}


}

void HashEvaluator::HashStraightFlushes()
{

}
void HashEvaluator::HashQuads()
{

}
void HashEvaluator::HashBoats()
{

}
void HashEvaluator::HashFlushs()
{

}
void HashEvaluator::HashStraights()
{

}
void HashEvaluator::HashTrips()
{

}
void HashEvaluator::HashTwoPair()
{

}
void HashEvaluator::HashOnePair()
{

}
void HashEvaluator::HashHighCards()
{

}