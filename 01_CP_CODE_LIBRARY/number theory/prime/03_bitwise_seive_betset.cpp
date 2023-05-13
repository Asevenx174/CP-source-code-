#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll maxx = 1e8 ;
vector < ll > primes ;
bitset < maxx+5 > b ;
void seive( ll limit)
{
    primes.push_back(2);
    b.reset();
    b[0]=b[1]=1;
    for(ll i=3;i<limit;i+=2)
    {
        if(b[i]==0)
        {
            for(ll j=(ll)i*i;j<limit;j+=i)
            {
                b[j]=1;
            }
            primes.push_back(i);
        }
    }
}
int main()
{
    seive(maxx+2);
    for(int i=0;i<primes.size();i+=100)
    {
        printf("%lld\n",primes[i]);
    }
    return 0 ;
}
