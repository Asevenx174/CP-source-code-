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
int ar[maxx+10],br[maxx+10],n,m ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      cin >> m ; 
      for (int i = 0; i < m ; ++i)
      {
         cin >> br[i+1] ; 
      }
      int ans = 0 ;
      int sum = 0 ; 
      for(int i=0;i<=n;i++)
      {
         sum+=ar[i] ; 
         int temp = sum ; 
         for(int j=0;j<=m;j++)
         {
            temp+=br[j] ; 
            ans = max(ans,temp) ; 
         }
      }
      cout << ans << endl ;
   }
  return 0 ;
}