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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   lp(i,1,n){cin >> ar[i];}
   if(n==2)
   {
      cout << "0" << endl ; 
      return 0 ; 
   }
   sort(ar+1,ar+n+1) ; 
   ll ans = min(ar[n]-ar[2],ar[n-1]-ar[1]) ; 
   cout << ans << endl ;
   return 0 ;
}