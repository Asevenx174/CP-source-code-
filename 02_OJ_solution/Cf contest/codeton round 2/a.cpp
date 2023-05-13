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
const ll maxx = 50+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
      cin >> n >> m ; 
      string a,b ;
      cin >> a >> b ; 
      int idx = 1 ; 
      for(auto c : a )
      {
         int x = c=='1' ? 1 : 0 ; 
         ar[idx++] = x ; 
      }
      idx = 1 ; 
      for(auto c : b )
      {
         int x = c=='1' ? 1 : 0 ; 
         br[idx++] = x ; 
      }
      int p = n ; 
      int q = m ; 
      while(ar[p]==br[q] && min(p,q)>0)
      {
         p-- ; 
         q-- ; 
      }
      int f=0,g=0 ; 
      for (int i = 0; i < p ; ++i)
      {
         if(ar[i+1]==0){f=1;}else{g=1;}
      }
      int ans = 0 ; 
      if(q==0){ans=1;}
      else if(q==1)
      {
         if(br[1]==0 && f==1){ans=1;}
         if(br[1]==1 && g==1){ans=1;}
      }
      if(ans)
      {
         cout << "YES" << endl ;
      }
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}