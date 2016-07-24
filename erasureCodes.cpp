#include "erasureCodes.h"
void RDP(int n)
{
    bitm.clear();
    int p=n-1;
    while(!isprime(p)){
        p=p+1;
    }
    setshift(p+1-n);

    w=p-1;

    n=p+1;
    m=2;
    k=n-m;

    block_number=w*n;

    for(int r=0;r<=p-1;r++)
    {
        vector<bool> equation(block_number,false);
        equation[prt(r,p-1)]=true;
        for(int c=0;c<=p-1;c++)
            equation[prt(r,c)]=true;
        bitm.push_back(equation);
    }

    for(int r=0;r<=p-1;r++)
    {
        vector<bool> equation(block_number,false);
        equation[prt(r,p)]=true;
        for(int c=0;c<=p;c++){
            int r1=(r-c+p)%p;
            if(r1!=p-1)
                equation[prt(r1,c)]=true;
        }
        bitm.push_back(equation);
    }

}
