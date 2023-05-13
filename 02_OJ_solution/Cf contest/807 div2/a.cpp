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
const ll maxx = 210+10 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int br[5][maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< int > v ;
      int n,x ;
      cin >> n >> x ;
      for (int i = 0; i < 2*n ; ++i)
      {
         int y ;
         cin >> y ; 
         v.push_back(y) ; 
      }
      sort(v.begin(),v.end(),greater<int>()) ; 
      auto it = v.begin() ;  
      for(int r=1;r<=2;r++)
      {
         for(int c=n;c>0;c--)
         {
            //cout << *it << endl ;
            br[r][c] = *it ; it++ ; 
         }
      }
      int f = 1 ; 
      for(int i=1;i<=n;i++)
      {
         //cout << br[1][i] << " " << br[2][i] << endl ; 
         if(br[1][i]-br[2][i]<x){f=0;}
      }
      if(f==1)
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