#include <iostream>
#include <fstream>
#include "nod.h"
#include "lista.h"
using namespace std;
lista a,b(1),c(1,3);
int main()
{
    a.ins(2,2);
    a.ins(3,2);
    a.ins(4,4);
    a.ins(5,4);
    a.del(1);
    lista d=a;
    cout<<a.src(2)<<endl;
    cout<<a[2]<<endl;
    a=a+b;
    if(a<b)
        cout<<1;
    else
        cout<<2;
    cout<<endl;

    return 0;
}
