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
bool isprime(ll n)
{
    if(n<2){return false;}
    if(n%2==0 || n%3==0 || n%5==0){return false;}
    ll root = sqrt(n);
    int wheel[10]={7,11,13,17,19,23,29,31};
    for(ll shell=0;shell<root;shell+=30)///which shell are u in
    {
        for(ll pos = 0 ; pos < 8 ; pos++)
        {
            if(wheel[pos]>root){break;}
            if(n%(shell+wheel[pos])==0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ll n ;
    cin >> n ;
    if(isprime(n))
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0 ;
}
