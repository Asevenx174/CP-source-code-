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
ll ar[maxx+10],n,br[maxx+10],b,q,suf[maxx+10],pr[maxx+10] ; 
bool valid(ll ex)
{
   ll idx = br[b-ex+1] ; 
   ll temp = q ; 
   while(idx<=n)
   {
      if(ar[idx]>temp)
      {
         if(temp==0){return false ; }
         temp-- ; 
      }
      idx++ ; 
   }
   return true ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll ans = 0 ; 
      b = 0 ; 
      cin >> n >> q ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         if(ar[i+1]>q)
         {
            br[++b] = i+1 ; 
            pr[i+1] = 0 ; 
         }
         else{ans++;pr[i+1]=1;}
      }
      ll l=0,r=b,ex=0 ; 
      while(l<=r)
      {
         ll mid = (l+r)/2LL ;
         if(valid(mid))
         {
            ex = mid ; 
            l = mid+1 ; 
         }
         else
         {
            r = mid-1 ; 
         }
      }
      while(ex--)
      {
         pr[ br[b--] ] = 1 ;  
      }
      for (int i = 0; i < n ; ++i)
      {
         cout << pr[i+1] ; 
      } 
      cout << endl ;
   }
   return 0 ;
}