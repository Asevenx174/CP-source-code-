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
const ll maxx = 5010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,k,ar[maxx+10] ; 
vector < int > g[maxx+10] ; 
int main()
{
   debugMode();
   int ans = 1 ; 
   set < int > s ; 
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      s.insert(ar[i+1]) ; 
      g[ar[i+1]].push_back(i+1) ; 
      if( g[ar[i+1]].size()>k){ans=0;}
   }
   if(s.size()<k){ans=0;}
   if(ans==0){cout << "NO" << endl ; return 0 ;}
   cout << "YES" << endl ; 
   int p = 1 ; 
   for (int i = 0; i <= maxx; ++i)
   {
      for(auto x : g[i] )
      {
          ar[x]=p++ ; 
          if(p>k){p=1;}
      }
   }
   lp(i,1,n)
   {
      if(i!=1){cout << " " ;}
      cout << ar[i] ; 
   }
   cout << endl ;
   return 0 ;
}