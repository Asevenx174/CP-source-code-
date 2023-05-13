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
int n,A,B,C,lr[15],tk[15] ; 
int dfs(int idx)
{
   if(idx==n)
   {
      int a=0,b=0,c=0 ;
      int fa=0,fb=0,fc=0 ;
      for (int i = 0; i < n ; ++i)
      {
          if(tk[i]==0)
          {
             a+=lr[i] ; 
             fa++ ; 
          }
          else if(tk[i]==1)
          {
             b+=lr[i] ; 
             fb++ ;
          }
          else if(tk[i]==2)
          {
             c+=lr[i] ; 
             fc++ ;
          }
      } 
      if( (fa*fb*fc) == 0 ) { return mod ;}
      int cost = (fa-1)*10 + (fb-1)*10 + (fc-1)*10 ; 
      cost += ( abs(a-A)+abs(b-B)+abs(c-C) ) ;
      return cost ;    
   }
   int ans = mod ;  
   for (int i = 0; i < 4 ; ++i)
   {
       tk[idx] = i ; 
       int temp = dfs(idx+1) ;
       ans = min(ans,temp) ;  
   }
   return ans ; 
}
int main()
{
   debugMode();
   cin >> n >> A >> B >> C  ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> lr[i] ; 
   }
   int ans = dfs(0) ; 
   cout << ans << endl ;
   return 0 ;
}