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
	DrawDealer(int players);
	virtual void Deal();
	virtual ~DrawDealer();
private:
	int _players;
};

class StudDealer : public Dealer
{
public:

	StudDealer(int players);
	virtual void Deal();
	virtual ~StudDealer();
private:
	int _players;
};

class OmahaDealer : public Dealer
{
public:
	OmahaDealer(int players);
	virtual void Deal();
	virtual ~OmahaDealer();
private:
	int _players;
};

class TexasDealer : public Dealer
{
public:
	TexasDealer(int players);
	virtual void Deal();
	virtual ~TexasDealer();
private:
	int _players;
};




#endif