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
int st[maxx+10][26],n ; // 26>= log2(maxx<=1e7)
int fun(int x,int y)
{
   return x+y ; 
}
int comsum(int l,int r)
{
   int sum = 0 ; 
   // st[2,9] = st[2,2+2^2-1]+st[5][5+2^2-1] ; 
   for(int j=25;j>=0;j--)
   {
      if( (1<<j) <= (r-l+1) )
      {
         sum+=st[l][j] ; 
         l+=(1<<j) ; 
      }
   }
   return sum ; 
}
void precom() // nlogn
{
   // st[i][j] will answer for the range [i,i+2^j-1] (len is 2^j)
   for (int i = 0; i < n ; ++i)
   {
      st[i][0] = fun(ar[i],0) ; // s[i][i+2^0-1] = s[i][i]
   }
   // st[i][j] = st[i][j-1]+st[i+(1<<(j-1))][j-1]
   // st[2][9] = ( s[2][2+2^2-1]=s[2][5] ) + s[6][6+2^2-1]=s[2][9]
   for(int j=1;j<=25;j++)
   {
      for (int i = 0; i + (1<<j) <= n ; ++i)
      {
         st[i][j] = fun(st[i][j-1],st[i+(1<<(j-1))][j-1]) ; 
      } 
   }
}
int main()
{
   debugMode();
   
   return 0 ;
}