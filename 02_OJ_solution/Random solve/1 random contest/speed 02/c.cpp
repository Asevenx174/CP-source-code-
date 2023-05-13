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
int f[maxx+10] ; 
int ar[maxx+10],ans[maxx+10] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      f[x]++ ; 
      ar[i+1] = x ; 
   }
   int temp = 0 ; 
   for (int i = 0; i < maxx ; ++i)
   {
      if(f[i]==0)
      {
         temp = i ; break ; 
      }
   }
   ans[n] = temp ; 
   for(int i=n-1;i>0;i--)
   {
      int x = ar[i+1] ; 
      f[x]-- ; 
      if(f[x]==0)
      {
         temp = min(temp,x) ; 
      }
      ans[i] = temp ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      cout << ans[i+1] << endl ;
   }
   return 0 ;
}