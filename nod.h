#ifndef NOD_H
#define NOD_H
#include <iostream>

class nod
{
    int info;
    nod *next;
    public:
        nod();
        nod(int,nod*);
        void setInfo(int);
        void setNext(nod*);
        int getInfo();
        nod* getNext();

};

#endif // NOD_H
