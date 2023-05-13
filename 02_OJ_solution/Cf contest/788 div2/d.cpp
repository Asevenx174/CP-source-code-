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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,x,l=mod,r=0 ;
      cin >> n >> x ;
      lp(i,1,n)
      {
         cin >> ar[i] ; 
         l = min(l,ar[i]) ; 
         r = max(r,ar[i]) ; 
      }
      ar[0]=ar[1];
      ll sum = 0 ; 
      lp(i,1,n)
      {
         sum+=abs(ar[i]-ar[i-1]) ; 
      }
      if(l>1)
      {
         ll best = min(ar[1]-1,ar[n]-1) ; 
         lp(i,2,n)
         {
            ll add = ar[i]+ar[i-1]-2-abs(ar[i]-ar[i-1]) ; 
            best = min(best,add) ; 
         }
         sum+=best ; 
      }
      if(x>r)
      {
         ll best = min(x-ar[1],x-ar[n]) ;
         lp(i,2,n)
         {
            ll add = (2*x)-ar[i-1]-ar[i]-abs(ar[i]-ar[i-1]) ; 
            best = min(best,add) ; 
         } 
         sum+=best ; 
      }
      cout << sum << endl ;
   }
   return 0 ;
}