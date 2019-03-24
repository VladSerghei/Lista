#include "nod.h"

nod::nod()
{
    info=0;
    next=NULL;
}

nod::nod(int a,nod* x)
{
    info=a;
    next=x;
}

void nod::setInfo(int a)
{
	info = a;
}

void nod::setNext(nod* x)
{
	next = x;
}

int nod::getInfo()
{
	return info;
}

nod* nod::getNext()
{
	return next;
}
