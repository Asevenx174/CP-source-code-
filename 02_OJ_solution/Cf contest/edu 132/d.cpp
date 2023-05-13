#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,t=2,z=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,m,k,f=0 ;
      cin >> n >> m >> k ;
      if(n%t==z && m%t==z && k%t==z)
      {
         f = 1 ;  
      }
      else if(n%t==z && m%t==1LL && k%t==z)
      {
         f = 1 ; 
      }
      else if(n%t==1LL && m%t==z)
      {
        ll p = m/t ; 
        ll v = k/p ; 
        if(k%p==z && v%t==1LL){f=1;}
      }
      if(f)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}