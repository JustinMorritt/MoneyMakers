#if !defined(TABLE_H__)
#define TABLE_H__
#include <iostream>

using namespace std;

class Table
{
public:
	virtual void Play() = 0;
	virtual ~Table();
};

class DrawTable : public Table
{
public:
	DrawTable(){};
	virtual void Play();
	virtual ~DrawTable();
};

class StudTable : public Table
{
public:

	StudTable(){};
	virtual void Play();
	virtual ~StudTable();
};

class OmahaTable : public Table
{
public:
	OmahaTable(){};
	virtual void Play();
	virtual ~OmahaTable();
};

class TexasTable : public Table
{
public:
	TexasTable(){};
	virtual void Play();
	virtual ~TexasTable();
};




#endif