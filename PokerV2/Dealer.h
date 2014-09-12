#if !defined(DEALER_H__)
#define DEALER_H__
#include <iostream>

using namespace std;

class Dealer
{
public:

	virtual void Deal() = 0;
	virtual ~Dealer();
};

class DrawDealer : public Dealer
{
public:
	DrawDealer();
	virtual void Deal();
	virtual ~DrawDealer();
};

class StudDealer : public Dealer
{
public:

	StudDealer();
	virtual void Deal();
	virtual ~StudDealer();
};

class OmahaDealer : public Dealer
{
public:
	OmahaDealer();
	virtual void Deal();
	virtual ~OmahaDealer();
};

class TexasDealer : public Dealer
{
public:
	TexasDealer();
	virtual void Deal();
	virtual ~TexasDealer();
};




#endif