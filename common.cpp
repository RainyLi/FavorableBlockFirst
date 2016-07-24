#include "common.h"

bool isprime(int p){
    if(p<=2)
        return false;
    int i=2;
    while(i*i<=p){
        if(p%i==0)
            return false;
        i=i+1;
    }
    return true;
}

void setshift(int i)
{
    forbid.clear();
    for(int x=0;x<i;i++)
        forbid.insert(x);
}

int prt(int r,int c){
    set<int>::iterator it;
    it=forbid.find(c);
    if(*it)
        return -1;
    int sh=0;
    for(it=forbid.begin();it!=forbid.end();++it){
        if(*it<c)
            sh++;
    }
    return r*w+c;
}
