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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n ; 
   ll ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
       ll x ;
       cin >> x ;
       ar[i+1] = x%2ll ; 
       ans+=(x/2LL) ;  
       br[i+1] = x ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(ar[i]==1)
      {
         int l = i ; 
         int r = i ; 
         while(r+1<=n && ar[r+1]==1)
         {
            r++ ; 
         }
         int len = r-l+1 ;
         if(len%2==0)
         {
            ans+=(len/2) ; 
            i = r ; 
         } 
         else
         {
            ans+=(len/2) ; 
            if(r+2<=n && ar[r+2]==1 && br[i+1]>1)
            {
               ans++ ;
               r+=2 ; 
               ar[r] = 0 ; 
            }
            else{i=r;}
         }
      }
   }
   cout << ans << endl ;
   return 0 ;
}