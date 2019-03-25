#include <cassert>
#include <exception>
#include "nod.h"
#include "lista.h"
using namespace std;

int main()
{
    nod *a=new nod;
    nod *b=new nod(3,NULL);
    b->setNext(a);
    a->setNext(b);
    a->setInfo(21);
    assert(a->getInfo()==21);
    assert(b->getInfo()==3);
    a=a->getNext();
    b=b->getNext();
    assert(a->getInfo()==3);
    assert(b->getInfo()==21);;

    lista l;
    lista m(2);
    lista n(1,3);
    cout<<"Lista l:"<<l<<"Lista m:"<<m<<"Lista n:"<<n<<endl;

    lista x;
    x=n;
    assert(x.getLen()==n.getLen());
    cout<<"Lista x,copie dupa lista n:\n"<<x<<endl;

    cout<<"Suma elementelor:\n"<<"l:"<<l.sum()<<endl<<"m:"<<m.sum()<<endl<<"n:"<<n.sum()<<endl<<endl;

    l.ins(1,1);
    l.ins(2,2);
    l.ins(3,3);
    l.ins(4,4);
    cout<<"Lista l:"<<l;
    l.rev();
    cout<<"Lista l dupa inversare:"<<l<<endl;

    cout<<"Elementul minim si cel maxim al lui l:\n";
    cout<<"Minim:"<<l.mini()<<endl<<"Maxim:"<<l.maxi()<<"\n\n";

    cout<<"Pozitia lui 2 in l:"<<l.src(2)<<endl<<"Pozitia lui 7 in l:"<<l.src(7)<<endl<<endl;

    l.del(1);
    cout<<"Lista l dupa stergerea elementului de pe pozitia 1:\n";
    cout<<"Lungime->"<<l.getLen()<<endl<<"Lista->"<<l<<endl;

    lista k;

    cin>>k;
    cout<<"Lista creata:\n"<<"Nr de elem->"<<k.getLen()<<endl<<"Lista:"<<k<<endl;

    lista v;
    cout<<"Elementul de pe pozitia 1 in lista l:"<<l[1]<<"\n\n";
    cout<<"Elementul de pe pozitia 19 in lista l:";
    cout<<l[19]<<"\n\n";
    cout<<"Elementul de pe pozitia 2 in lista v:";
    cout<<v[2]<<"\n\n";

    cout<<"Lista l:"<<l<<"Lista n:"<<n;
    v=l+n;
    cout<<"Lista l+n:\n"<<"Lungime->"<<v.getLen()<<endl<<"Lista->"<<v<<endl;

    assert(l>n);
    assert(!(l<n));

    cout<<"Lista l:"<<l<<"Lista 2*l:"<<2*l<<"Lista l*3:"<<l*3;

    return 0;
}
