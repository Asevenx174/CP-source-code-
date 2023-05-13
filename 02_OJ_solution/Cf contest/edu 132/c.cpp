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
ll ar[maxx+10],n,last,br[maxx+10],q,in[maxx+10] ; 
bool valid(ll ex)
{
  ll idx = br[last-ex+1] ; 
  ll temp = q ; 
  while(idx<=n)
  {
     if(ar[idx]>temp)
     {
         if(temp==0){break;}
         temp-- ; 
     }
     idx++ ;
  }
  if(idx>n){return true ;}
  return false ;
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      last = 0 ;
      cin >> n >> q ;
      for (int i = 1 ; i <= n ; ++i)
      {
         cin >> ar[i] ; 
         if(ar[i]>q)
         {
            br[++last] = i ;
            in[i] = 0 ; 
         }
         else { in[i]=1; }
      }
      ll l=1,r=last,add=0 ; 
      while(l<=r)
      {
         ll mid = (l+r)/2LL ;
         if(valid(mid))
         {
            add = mid ; 
            l = mid+1 ; 
         }
         else
         { 
            r = mid-1 ; 
         }
      } 
      br[last+1] = n+1 ; 
      ll pos = last-add+1 ; 
      for(int i=1;i<=n;i++)
      {
         int x = br[pos]<=i ? 1 : in[i] ; 
         cout << x ; 
      }
      cout << endl ;
   }
   return 0 ;
}