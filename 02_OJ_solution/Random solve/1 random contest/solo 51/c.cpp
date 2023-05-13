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
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
int main()
{
   debugMode();
   int n,sum=0 ;
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ; 
      sum+=ar[i] ; 
   }
   int ans=mod,idx=0 ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = ar[i]*n ; 
      int d = abs(x-sum) ; 
      if(d<ans)
      {
         ans = d ; 
         idx = i ; 
      }
   }
   cout << idx << endl ; 
   return 0 ;
}