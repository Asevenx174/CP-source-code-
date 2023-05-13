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
ll m,n,sx,sy,d ; 
ll ar[maxx+10][maxx+10] ; 
bool valid(ll a,ll b)
{
   ll ans = abs(a-sx)+abs(b-sy) ; 
   if(ans<=d){return true ;}
   return false ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> m >> sx >> sy >> d ;  
      if( ( valid(sx,1) && valid(sx,m) ) || ( valid(1,sy) && valid(n,sy) ) || ( valid(sx,1) && valid(1,sy) ) || ( valid(n,sy) && valid(sx,m) ) )
      {
         cout << "-1" << endl ;
         continue ; 
      }
      cout << (n+m-2) << endl ;
   }
   return 0 ;
}