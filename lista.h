#ifndef LISTA_H
#define LISTA_H
#include <limits>
#include "nod.h"



class lista{//clasa ce implementeaza o lista circulara de intregi

    int len;//lungimea listei
    nod *first,*last;//adresele primului si ultimului nod
public:
    lista();//constructorul fara parametri
    lista(int);//constructorul cu parametri
    lista(int,int);//constructorul cu parametri
    lista(const lista&);//constructorul de copiere
    ~lista();//destructorul

    int getLen()const;//intoarce lungimea listei
    void ins(int,int);//introduce un nod nou in lista
    int src(int);//cauta o valoare in lista
    void del(int);//sterge nodul de pe o pozitie din lista

    lista& operator=(const lista&);//supraincarcarea operatorului =
    friend istream& operator>>(istream&,lista&);//supraincarcarea operatorului >> pt citire
    friend ostream& operator<<(ostream&,const lista&);//supraincarcarea operatorului << pt afisare
    int operator[](const int)const;//supraincarcarea operatorului [] pt accesarea unui element de pe o anumita pozitie
    lista operator+(const lista&);//supraincarcarea operatorului + pt concatenarea a doua liste
    int operator<(const lista &);//supraincarcarea operatorului < pt compararea a doua liste dupa suma elementelor
    int operator>(const lista &);//supraincarcarea operatorului > pt compararea a doua liste dupa suma elementelor
    friend lista operator*(int,const lista&);//supraincarcarea operatorului * pt inmultirea tuturor elementelor unei liste cu un scalar
    friend lista operator*(const lista&,int);//supraincarcarea operatorului * pt inmultirea tuturor elementelor unei liste cu un scalar

    int sum();//intoarce suma elementelor listei
    lista& rev();//inverseaza ordinea elementelor in lista
    int mini();//intoarce valoarea minima din lista
    int maxi();//intoarce valoarea maxima din lista
};

#endif // LISTA_H
