#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll maxx = 1e7 ;///1e8 limitation
vector < ll > lowfactor(maxx+5);
void seive()
{
    for(int i=1;i<=maxx;i+=2){lowfactor[i]=i;}
    for(int i=2;i<=maxx;i+=2){lowfactor[i]=2;}
    for(int i=3;(ll)i*i<=maxx;i+=2)
    {
        if(lowfactor[i]==i)
        {
            for(int j=(ll)i*i;j<=maxx;j+=i)
            {
                if(lowfactor[j]==j){lowfactor[j]=i;}
            }
        }
    }
}
void factors(int n)
{
    while(n!=1)
    {
        cout << lowfactor[n] << endl;
        n=n/lowfactor[n];
    }
}
int main()
{
    seive();
    int q ;
    cin >> q ;
    while(q--)
    {
        int x ;
        cin >> x ;
        factors(x);
    }
    return 0 ;
}
