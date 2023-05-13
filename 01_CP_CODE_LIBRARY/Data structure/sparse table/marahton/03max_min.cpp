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
int ar[maxx+10] ; // 0 based 
int st[maxx+10][26][5],n,lg[maxx+10] ; // 26>= log2(maxx<=1e7)
int getval(int l,int r,int op)
{
   int len = r-l+1 ;
   int j = lg[len] ; 
   int ans = 0 ; 
   if(op==0)
   {
      ans = min(st[l][j][0],st[r-( (1<<j) - 1 )][j][0]) ; 
   }
   else
   {
      ans = max(st[l][j][1],st[r-( (1<<j) - 1 )][j][1]) ; 
   }
   return ans ; 
}
void precom() // nlogn
{
   lg[1] = 0 ; // 1 can be divided 0 times by 2 
   for(int i=2;i<=maxx;i++)
   {
      lg[i] = lg[i/2]+1 ; 
   }  
   for (int i = 0; i < n ; ++i)
   {
      st[i][0][0] = ar[i] ;
      st[i][0][1] = ar[i] ; 
   }
   for(int j=1;j<=25;j++)
   {
      for (int i = 0; i + (1<<j) <= n ; ++i)
      {
         st[i][j][0] = min(st[i][j-1][0],st[i+(1<<(j-1))][j-1][0]) ; 
         st[i][j][1] = max(st[i][j-1][1],st[i+(1<<(j-1))][j-1][1]) ;
      } 
   }
}
int main()
{
   debugMode();
   double EPS=1e-3;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i] ; 
   }
   precom() ; 
   
   return 0 ;
}