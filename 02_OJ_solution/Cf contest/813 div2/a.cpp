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
int ar[5][maxx],n,suf[maxx+10] ; 
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      ar[1][i+1] = x ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      ar[2][i+1] = x ; 
   }
   int a =0 ,b =0 ;
   for(int i=n;i>0;i--)
   {
      //a+=ar[1][i] ; 
      b+=ar[2][i] ; 
      suf[i] = max(a,b) ; 
   }
   int sum = 0 ; 
   int ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      int temp = ar[1][i]+ar[2][i]+suf[i+1]+sum ; 
      //cout << i << " " << temp << endl ; 
      ans = max(ans,temp) ; 
      sum+=ar[1][i] ; 
   }
   cout << ans << endl ;
   return 0 ;
}