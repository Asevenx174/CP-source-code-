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
const ll maxx = 50 ,mod=1e9+7,imax=1e18+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx],n ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n ;
      cin >> n ;
      lp(i,1,n) { cin >> ar[i] ; }
      ll p = ar[n] ; 
      ll idx = n-1 ; 
      ll ans = 0 ; 
      while(idx>0)
      {
         ll c = ar[idx] ; 
         while(c>=p)
         {
            ans++ ; 
            c = c/2LL ; 
            if(c==0){break;}
         }
         ar[idx] = c ; 
         p = c ; 
         idx-- ; 
      }
      idx = 2 ; 
      while(idx<=n)
      {
          if(ar[idx-1]>=ar[idx]){ ans=-1 ;}
          idx++ ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}