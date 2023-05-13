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
ll ar[maxx+10],last[maxx+10],ans[maxx+10]  ; 
bool used[maxx+10] ;
int main()
{
   debugMode();
   ll n,q,sum=0,pos=0,all=0 ;
   cin >> n >> q ;
   for (int i = 1 ; i <= n ; ++i)
   {
      cin >> ar[i] ; 
      last[i] = 0 ; 
      sum+=ar[i] ; 
   }
   for (int i = 1 ; i <=  q ; ++i)
   {
      int t,idx,val ;
      cin >> t ; 
      if(t==1)
      {
         cin >> idx >> val ; 
         ll p = 0 ; 
         if(last[idx]<pos)
         {
            p = all ; 
         }
         else
         {
            p = ar[idx] ;  
         }
         sum+=(val-p) ;  
         ar[idx] = val ; 
         last[idx] = i ;  
      }
      else
      {
         cin >> val ; 
         sum = val*n ; 
         pos = i ; 
         all = val ; 
      }
      ans[i] = sum ; 
   }
   for (int i = 0; i < q ; ++i)
   {
      cout << ans[i+1] << endl ;
   }
   return 0 ;
}