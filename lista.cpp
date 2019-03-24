#include "lista.h"
#include <iostream>
lista::lista()
{
	first = last = NULL;
	len = 0;
}

lista::lista(int i)
{
	first = last = new nod(i, NULL);
	first->setNext(last);

	len = 1;
}

lista::lista(int a, int b)
{
	first=last = NULL;
	for (int i = 0; i < a; i++)
		ins(b,i);

}

lista& lista::operator=(const lista&l)
{
    lista a=l;
    if(&l==this)
        return *this;
    nod *n=this->first;
    this->len=a.len;
    this->first=this->last=NULL;
    for(int i=0;i<this->len;i++)
        {
            ins(n->getInfo(),i);
            n=n->getNext();
        }
    return *this;

}

lista operator*(int i,const lista&l)
{
    lista a=l;
    nod *n=a.first;
    for(int x=0;x<a.numElem();x++)
    {
    n->setInfo(n->getInfo()*i);
    n=n->getNext();
    }
    return a;


}

void lista::ins(int x, int i)
{
	if (first == NULL)
    {
		first = last = new nod(x, NULL);
		first->setNext(first);
		len = 1;
		return;
	}
	nod* n = new nod(x, NULL);
	if (i == 0)
    {
		n->setNext(first);
		first=n;
        last->setNext(first);
		return;
	}
	if (i < 0 || i >= int(len)) {
		last->setNext(n);
		last = n;
		last->setNext(first);
		len++;
		return;
	}
	nod* a = first;
	for (int j = i; j > 1; j--)
		a = a->getNext();
	n->setNext(a->getNext());
	a->setNext(n);
	len++;

}

lista::lista(const lista& l)
{
	first = last = NULL;
	len = 0;
	nod* n = l.first;
	int i=0;
	while (n != NULL) {
		{
		    ins(n->getInfo(),i);
		    i++;
		}
		n = n->getNext();
	}
}

lista::~lista()
{
	nod *p =first,*o;
	while (p != NULL) {
		o = p;
		p = p->getNext();
		delete o;
	}
	first=last=NULL;
	len= 0;
}

lista::src(int x)
{
    nod *n=first;
    if(n==NULL)
    {
        cout<<"Lista vida";
        return -1;
    }
    if(x==n->getInfo())
        return 0;
    int i=0;
    while(n->getNext()!=first)
    {

        if(x==n->getInfo())
            return i;
        i++;

    }
    return -1;
}

void lista::del(int i)
{
	if (i < 0 || i >= len) {
		return;
	}
	nod* p = first;
	if (i == 0)
        {
            if (len == 1 || len == 0)
            {
                last=first= NULL;
            }
            else
            {
                first= first->getNext();
                last->setNext(first);
                delete p;
            }
        }
	else
        {
            for (int j = i; j > 1; j--)
            {
                p = p->getNext();
            }
            nod* o = p->getNext();
            p->setNext(o->getNext());
            delete o;
	}
	len--;
}



istream& operator >>(istream& in,lista& l)
{
    int n,x;
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>x;
        l.ins(x,i);
    }
    return in;
}

ostream& operator <<(ostream& out,const lista&l)
{
    nod *n=l.first;
    if(n==NULL)
    {
        out<<"Lista vida\n";
        return out;
    }
    out<<n->getInfo();
    while(n->getNext()!=l.first)
    {
        n=n->getNext();
        out<<n->getInfo();
    }
    return out;
}

lista operator+(const lista&l1,const lista &l2)
{
    lista l3;
    l3.first=l1.first;
    l3.last=l1.last;
    l3.last->setNext(l2.first);
    l3.last=l2.last;
    l3.last->setNext(l1.first);
    return l3;
}


int lista::sum()
{
    nod* n=first;
    if(n==NULL)
        return 0;
    int sum=0;
    for(int i=0;i<len;i++)
        {
            sum+=n->getInfo();
            n=n->getNext();
        }
    return sum;
}

int operator<(const lista&l1,const lista &l2)
{
    lista a=l1,b=l2;
    int x=a.sum();
    int y=b.sum();
    if(x<y)
        return 1;
    return 0;
}

int operator>(const lista&l1,const lista &l2)
{
    lista a=l1,b=l2;
    int x=a.sum();
    int y=b.sum();
    if(x>y)
        return 1;
    return 0;
}


int lista::numElem()
{
    return len;
}

lista lista::rev()
{
	lista l;
	nod *p = first;
	while (p !=last)
    {
		l.ins(p->getInfo(), 0);
		p = p->getNext();
	}
	l.ins(p->getInfo(),0);
	p = p->getNext();
	return l;
}

int lista::mini()
{
    nod *n=first;
    if(len==0)
        return INT_MIN;
    int m=n->getInfo();
    n=n->getNext();
    while(n!=first)
        if(m>n->getInfo())
            m=n->getInfo();
    return m;
}

int lista::maxi()
{
    nod *n=first;
    if(len==0)
        return INT_MAX;
    int m=n->getInfo();
    n=n->getNext();
    while(n!=first)
        if(m<n->getInfo())
            m=n->getInfo();
    return m;
}

int lista::operator[](const int p)const
{
    if(len==0)
        return INT_MAX;
    if(len<p)
        return INT_MAX;
    nod *n=first;
    for(int i=0;i<p;i++)
        n=n->getNext();
    return n->getInfo();


}
































