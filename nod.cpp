#include "nod.h"

nod::nod()//implementarea constructorului fara parametri,ce initializeaza un nod nul
{
    info=0;
    next=NULL;
}
nod::nod(int x,nod* n)//implementarea constructorului cu parametri,ce initializeaza un nod cu x in campul info si n in campul next
{
   info=x;
   next=n;
}
void nod::setInfo(int x)//functia seteaza valoarea campului info al unei instante la x
{
    info=x;
}
void nod::setNext(nod *n)//functia seteaza valoarea campului next al unei instante la n
{
    next=n;
}
int nod::getInfo()//functia intoarce valoarea aflata in campul info
{
    return info;
}
nod* nod::getNext()//functia intoarce adresa aflata in campul next
{
    return next;
}

