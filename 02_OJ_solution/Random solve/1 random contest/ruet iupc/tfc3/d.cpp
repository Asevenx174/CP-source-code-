#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int prime[maxx+10];
vector < ll > v ;
void seive(int n)
{
    int x = sqrt(n);
    prime[0]=prime[1]=1;
    for(int i=4;i<=n;i+=2)
    {
        prime[i]=1;
    }
    for(int i=3;i<=x;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(prime[i]==0)
        {
            v.push_back(i);
        }
    }
}

int main()
{
   debugMode();
   seive(maxx) ; 
   sort(v.begin(),v.end()) ; 
   ll n ; 
   cin >> n ;
   ll ans = 0 ; 
   for(auto x : v )
   {
      ll q = (ll)x*x*x ;
      if(q>n){break;}
      ll p = n/q ;
      p = min(p,x-1) ; 
      auto it = upper_bound(v.begin(),v.end(),p);
      ans+=(it-v.begin()) ; 
   }
   cout << ans << endl ;
   return 0 ;
}