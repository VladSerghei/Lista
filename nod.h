#ifndef NOD_H
#define NOD_H
#include <iostream>
using namespace std;

class nod{//clasa nod si metodele utilizate pt a-i modifica field-urile

    int info;
    nod* next;
public:
    nod();//constructorul fara parametri
    nod(int,nod*);//constructorul cu parametri
    int getInfo();
    nod* getNext();
    void setInfo(int);
    void setNext(nod*);

};

#endif // NOD_H
