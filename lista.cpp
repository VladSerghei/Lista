#include "lista.h"

lista::lista()//constructorul fara parametri creeaza o lista vida
{
    first=last=NULL;

    len=0;
}
lista::lista(int x)//constructorul cu un parametru creeaza o lista cu un singur nod,care are in campul info valoarea x
{
    nod *p=new nod(x,NULL);
    p->setNext(p);
    first=last=p;
    len=1;
}
lista::lista(int x,int i)//constructorul cu doi parametri creeaza o lista de lungime i in care toate nodurile au valoarea x in campul info
{
    first=last = NULL;
	for (int j= 0;j<i;j++)
		ins(x,j);

}
int lista::getLen()const//intoarce lungimea listei
{
    return len;
}
lista::~lista()//destructorul dezaloca nodurile
{
    nod *p =first,*o;
	while (p!=last) {
		o = p;
		p = p->getNext();
		delete o;
	}
    delete p;
	first=NULL;
	len= 0;
}
void lista::ins(int i,int poz)//insereaza un nod nou cu valoare i in campul info pe pozitia poz in lista
{
    if (first == NULL)//se trateaza cazul in care lista este vida separat
    {
		nod *p=new nod(i,NULL);
        p->setNext(p);
        first=last=p;
        len=1;
        return;
	}
	nod* n = new nod(i, NULL);
	if (poz== 0)
    {
		n->setNext(first);
		first=n;
        last->setNext(first);
        len++;
		return;
	}
	if (poz<0||poz>=len)
    {
		last->setNext(n);
		last = n;
		last->setNext(first);
		len++;
		return;
	}
	nod* a = first;
	for (int j=poz;j>1;j--)
		a = a->getNext();
	n->setNext(a->getNext());
	a->setNext(n);

	len++;//se modifica lungimea listei din campul len

}
lista& lista::operator=(const lista&l)//supraincarcarea operatorului = pentru a copia informatia dintr-o instanta in alta
{

    if(&l==this)//se verifica intai sa nu fie o atribuire de tip a=a
        return *this;

    delete this;//se sterge continutul vechi
    nod *n=l.first;
    this->first=this->last=NULL;

    this->len=l.getLen();//se copiaza informatiile din lista l
    int i,s=this->getLen();
    for(i=0;i<s;i++)
        {
            this->ins(n->getInfo(),i);
            n=n->getNext();
        }
    this->len=i;
    return *this;

}
int lista::sum()//calculeaza suma elementelor listei,parcurgandu-le pe rand
{
    nod *n=first;
    int s=0,l=this->getLen();
    for(int i=0;i<l;i++)
    {
        s+=n->getInfo();
        n=n->getNext();
    }
    return s;
}
lista& lista::rev()//inverseaza ordinea elementelor schimband pe rand campul next al fiecarui nod
{

	nod *p=this->first;
	nod *q=p->getNext();
	nod *r=q->getNext();
	nod *s;
	while(q!=first)
    {
		q->setNext(p);
		p=q;
		q=r;
		r=r->getNext();
	}
	s=this->first;
	this->first=this->last;
    this->last=s;
	return *this;
}
int lista::mini()//cauta minimul elementelor din lista parcurgandu-le pe rand si comparand minimul actual cu fiecare dintre ele.Intoarce INT_MIN daca lista e vida
{
    nod *n=first;
    if(n==NULL)
    {
        cout<<"Lista vida!";
        return INT_MIN;
    }

    int minim=n->getInfo();
    n=n->getNext();
    int l=this->getLen();

    for(int i=0;i<l-1;i++)
    {
        if(n->getInfo()<minim)
            minim=n->getInfo();

        n=n->getNext();
    }
    return minim;

}
int lista::maxi()//cauta maximul elementelor din lista parcurgandu-le pe rand si comparand maximul actual cu fiecare dintre ele.Intoarce INT_MAX daca lista e vida
{
    nod *n=first;
    if(n==NULL)
    {
        cout<<"Lista vida!";
        return INT_MAX;
    }

    int maxim=n->getInfo();
    n=n->getNext();
    int l=this->getLen();

    for(int i=0;i<l-1;i++)
    {
        if(n->getInfo()>maxim)
            maxim=n->getInfo();

        n=n->getNext();
    }
    return maxim;

}
int lista::src(int x)//cauta valoarea x in lista.Intoarce -1 daca lista e vida sau x nu este gasit in lista
{
    nod *n=first;
    if(n==NULL)
    {
        cout<<"Lista vida!";
        return -1;
    }
    int l=this->getLen();
    int i;
    for(i=0;i<l;i++)
    {
        if(n->getInfo()==x)
            return i;
        n=n->getNext();
    }
    return -1;
}
void lista::del(int i)//sterge elementul de pe pozitia i din lista
{
    if (i < 0 || i >= len)//se verifica daca pozitia i exista in lista
		return;


	if (i == 0)//inserarea la inceputul listei se trateaza separat
        {
            if (len == 1 || len == 0)//se trateaza cazurile listei vide si ale celei cu un element separat
            {
                nod* q=last;
                last=first= NULL;
                delete q;
            }
            else
            {
                nod *q=first;
                first= first->getNext();
                last->setNext(first);
                delete q;
            }
        }
	else
        {//se parcurge lista pana la pozitia i si apoi se sterge nodul respectiv,mentinand conexiunile intre noduri
            nod* n=first;
            for(int j=i;j>1;j--)
                n=n->getNext();
            nod* q=n->getNext();
            n->setNext(q->getNext());
            delete q;
        }
	len--;//se modifica lungimea listei din campul len
}
lista::lista(const lista &l)//implementarea constructorului de copiere
{
	first=last=NULL;
	len=0;
	nod *n=l.first;
	int i=0;
	while (n!=l.last)
        {
            {
                ins(n->getInfo(),i);
                i++;
            }
            n=n->getNext();
        }
    ins(n->getInfo(),i);
}
istream& operator >>(istream& in,lista& l)//supraincarcarea operatorului >> pt citirea variabilelor de tip lista
{
    int n,x;
    cout<<"Introduceti nr de elemente al noii liste:";//se citeste intai lungimea listei
    in>>n;
    cout<<"Introduceti elementele listei:";//se citesc apoi elementele listei
    for(int i=0;i<n;i++)
    {
        in>>x;
        l.ins(x,i);
    }
    return in;
}
ostream& operator <<(ostream& out,const lista&l)//supraincarcarea operatorului << pt citirea variabilelor de tip lista
{
    nod *n=l.first;
    if(n==NULL)
    {
        out<<"Lista vida!\n";
        return out;
    }
    out<<n->getInfo()<<' ';//se parcurge lista element cu element,afisand capurile info ale fiecaruia
    n=n->getNext();
    for(int i=1;i<l.getLen();i++)
    {
        out<<n->getInfo()<<' ';
        n=n->getNext();
    }
    out<<endl;
    return out;
}
int lista::operator[](const int p)const//supraincarcarea operatorului [] pt accesarea elementului de pe pozitia p din lista
//Intoarce INT_MAX si afiseaza un mesaj sugestiv daca lista e vida sau p>len
{
    if(len==0)
        {
            cout<<"Lista vida!\n";
            return INT_MAX;
        }
    if(len<p)
        {
            cout<<"Lungime depasita!\n";
            return INT_MAX;
        }

    nod *n=first;//se parcurge lista nod cu nod pana la pozitia p
    for(int i=0;i<p;i++)
        n=n->getNext();
    return n->getInfo();
}
lista lista::operator+(const lista &l)//supraincarcarea operatorului + pt concatenarea a doua liste
{
    lista s=l;//se creeaza o noua lista in care se copiaza intai una din liste
    nod *n=this->first;

    if(n==NULL)
        return s;
    int sz=this->getLen();
    for(int i=0;i<sz;i++)//elementele celeilalte liste sunt adaugate pe rand folosind functia membru ins()
    {
        s.ins(n->getInfo(),i);
        n=n->getNext();
    }

    return s;
}
int lista::operator<(const lista& l)//supraincarcarea operatorului < pt compararea a doua liste dupa suma elementelor lor
{
    lista s=l;
    if(this->sum()<s.sum())
        return 1;
    return 0;
}
int lista::operator>(const lista& l)//supraincarcarea operatorului > pt compararea a doua liste dupa suma elementelor lor
{
    lista s=l;
    if(this->sum()>s.sum())
        return 1;
    return 0;
}
lista operator*(int x,const lista& l)//supraincarcarea operatorului * pt inmultirea tuturor elementelor unei liste cu un scalar
{
    lista a=l;
    nod *n=a.first;
    int sz=a.getLen();
    for(int i=0;i<sz;i++)
    {
        n->setInfo(n->getInfo()*x);
        n=n->getNext();
    }

    return a;
}
lista operator*(const lista& l,int i)//supraincarcarea operatorului * pt inmultirea tuturor elementelor unei liste cu un scalar(a doua oara pt comutativitate)
{
    return i*l;
}
