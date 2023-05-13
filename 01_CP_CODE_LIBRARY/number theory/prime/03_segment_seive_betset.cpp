#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<bitset>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<vector>
#include<utility>
#include<cstring>
#define pb(a)             push_back(a)
#define mp(a,b)           make_pair(a,b)
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define loop(i,a)          for(int i=1;i<=a;i++)
#define pii                pair <int,int>
#define sl(a)              scanf("%I64d",&a)
#define sll(a,b)           scanf("%I64d %I64d",&a,&b)
#define si(a)              scanf("%d",&a)
#define sii(a,b)           scanf("%d %d",&a,&b)
using namespace std ;
typedef long long ll ;
const ll mod = 1e9+7,maxx = 150000010;
ll digitcount(ll n) {return (ll)log2(n)+1;}///logn cox we can change the base
bitset < maxx+5 > b ;
vector < ll > primes ;
void seive()
{
    b.reset();
    b[0]=1;
    b[1]=1;
    for(ll i=2;i<maxx;i++)
    {
        if(b[i]==0)
        {
            primes.pb(i);
            for(ll j=i*i;j<maxx;j+=i)
            {
                b[j]=1;
            }
        }
    }
}
int main()
{
    seive();
    cout << primes.size() << endl;
    return 0 ;
}
