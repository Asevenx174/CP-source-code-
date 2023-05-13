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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int qp[maxx+10],dr[maxx+10],pr[maxx+10],tk[maxx+10],ans[maxx+10] ; 
bool fix[maxx+10] ; 
int main()
{
   debugMode();
   int n,m ; 
   cin >> n >> m ;
   for(int i=1;i<=m;i++)
   {
      int s,d,c ;
      cin >> s >> d >> c ; 
      qp[i] = s ;
      dr[i] = d ; 
      pr[i] = c ; 
      fix[d] = true ; 
   }
   for(int i=1;i<=n;i++)
   {
      if(fix[i])
      {
         ans[i] = m+1 ; continue ; 
      }
      int ch=0,nx=mod ;
      for(int j=1;j<=m;j++)
      {
         if(qp[j]<=i && dr[j]>i && tk[j]<pr[j])
         {
             if(nx>dr[j])
             {
               nx = dr[j] ; 
               ch = j ; 
             }
         }
      }
      ans[i] = ch ; 
      tk[ch]++ ; 
   }
   int f = 1 ; 
   for (int i = 0; i < m ; ++i)
   {
      if(pr[i+1]!=tk[i+1]){f=0;}
   }
   if(f==0){cout << "-1" << endl ; return 0 ; }
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << ans[i+1] ; 
   }
   cout << endl ;
   return 0 ;
}