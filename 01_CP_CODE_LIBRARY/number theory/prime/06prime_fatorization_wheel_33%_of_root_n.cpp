#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
vector < ll > factors ;
void findfactors(ll n)///one third of root n
{
    ll arr[5]={2,3,5};///7,11,13,17,23,29,31,37....
    for(ll x=0;x<3;x++)
    {
        while(n%arr[x]==0){n/=arr[x];factors.push_back(arr[x]);}
    }
    ll increase[10]={4, 2, 4, 2, 4, 6, 2, 6},k=0;
    for(ll i=7;i*i<=n;i+=increase[k++])
    {
        while(n%i==0){n/=i;factors.push_back(i);}
        if(k==8){k=0;}
    }
    if(n>1){factors.push_back(n);}
    cout << endl;
}
int main()
{
    ll n ;
    cin >> n ;
    findfactors(n);
    for(auto x : factors)
    {
        cout << x << endl;
    }
    return 0;
}
