#ifndef LISTA_H
#define LISTA_H
#include "nod.h"
#include <limits>

using namespace std;
class lista
{
	nod *first,*last;
	int len;
public:
	lista();
	lista(int);
	lista(int, int);
	lista(const lista&);
	~lista();

	lista& operator=(const lista&);

	void ins(int,int);
	int src(int);
	void del(int);


    int operator[](const int p)const;
	friend lista operator+(const lista&,const lista&);
	friend int operator<(const lista&,const lista &);
	friend int operator>(const lista&,const lista &);
	friend lista operator*(int i,const lista&);
	friend ostream& operator<<(ostream&,const lista&);
	friend istream& operator>>(istream&,lista&);

	int sum();
    int numElem();
    lista rev();
    int mini();
    int maxi();






};

#endif // LISTA_H
