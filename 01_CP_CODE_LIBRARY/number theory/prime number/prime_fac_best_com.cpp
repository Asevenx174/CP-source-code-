void primefactor(int x);
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n;
    cin >> n ;
    primefactor(n);
    return 0 ;
}
void primefactor(int x)
{
    int i,j,k;
    while(x%2==0)
    {
        x/=2;
    }
    k=sqrt(x);
    for(i=3; i<=k; i+=2)
    {
        if(x%i==0)
        {
            cout << i << endl ;
            x=x/i ;
        }
    }
    if(x==2)
    {
        cout << x << endl ;
    }
}
