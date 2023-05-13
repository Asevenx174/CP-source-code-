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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,tr[maxx+10],ar[maxx+10],p ; 
int main()
{
   debugMode();
   cin >> n >> p ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> tr[i] >> ar[i] ; 
   }
   for(int j=0;j<n;j++)
   {
   for (int i = 0; i <=j  ; ++i)
   {
      if(tr[i]==1)
      {
         p = (p&ar[i]) ; 
      }
      else if(tr[i]==2)
      {
         p = (p|ar[i]) ;
      }
      else
      {
         p = (p^ar[i]) ;
      }
   }
   cout << p << endl ;
   }
   return 0 ;
}