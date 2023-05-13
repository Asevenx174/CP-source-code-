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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10][maxx+10],pr[maxx+10][maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      memset(ar,0,sizeof(ar)) ; 
      ll n,q ;
      cin >> n >> q ;
      for (int i = 0; i < n ; ++i)
      {
         ll h,w ;
         cin >> h >> w ; 
         ar[h][w]++ ; 
      }
      for(int i=1;i<maxx;i++)
      {
         for(int j=1;j<maxx;j++)
         {
            pr[i][j] = pr[i][j-1]+pr[i-1][j]-pr[i-1][j-1]+(ar[i][j]*i*j) ; 
         }
      }
      for (int i = 0; i < q ; ++i)
      {
         ll hs,ws,hb,wb ;
         cin >> hs >> ws >> hb >> wb ;
         ll ans = pr[hb-1][wb-1]-pr[hs][wb-1]-pr[hb-1][ws]+pr[hs][ws] ;
         cout << ans << endl ; 
      }
   }
   return 0 ;
}