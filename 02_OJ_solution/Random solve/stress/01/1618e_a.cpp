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
const ll maxx = 4e4+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll br[maxx+10],ar[maxx+10],n,s[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      ll sum = 0 ; 
      for (int i = 0; i < n ; ++i)
      {
          ll x ;
          cin >> x ;
          sum+=x ; 
          br[i+1] = sum ; 
      }
      ll k = (n*(n+1))/2 ;
      s[n] = k ; 
      ll sub = n ; 
      for(int i=n-1;i>0;i--)
      {
         s[i] = k-sub ; 
         sub+=i ; 
      } 
   }
   return 0 ;
}