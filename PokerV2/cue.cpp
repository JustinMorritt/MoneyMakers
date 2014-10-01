#include "cue.h"

CUE::CUE(const CUE& cue)
{
	for (int i = 0; i < cue.size(); ++i)
	{
		this->push_back(cue[i]);
	}
}

CUE& CUE::operator=(const CUE& cue)
{
	for (int i = 0; i < cue.size(); ++i)
	{
		this->push_back(cue[i]);
	}
	return *this;
}

CUE::CUE(vector<const Card*> cards) 
{

}


CUE::~CUE()
{
}


