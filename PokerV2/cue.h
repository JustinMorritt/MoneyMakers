#if !defined(CUE_H__)
#define CUE_H__
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class CUE : public vector<const Card*>
{
public:
	CUE();
	~CUE();
};




#endif