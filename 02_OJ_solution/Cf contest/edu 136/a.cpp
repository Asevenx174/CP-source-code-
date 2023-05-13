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
int X[10] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[10] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int n,m ; 
bool valid(int i,int j)
{
   bool ans = true ; 
   for (int k = 0; k < 8 ; ++k)
   {
      int x = i+X[k] ; 
      int y = j+Y[k] ; 
      if(min(x,y)>0 && x<=n && y<=m)
      {
         ans = false ; 
      }
   }
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
     int ans = 0 ; 
     int p = 1 , q = 1 ; 
     cin >> n >> m ;
     for(int i=1;i<=n;i++)
     {
      for(int j=1;j<=m;j++)
      {
         if(valid(i,j)){p=i;q=j;}
      }
     }
     cout << p << " " << q << endl ;
   }
   return 0 ;
}