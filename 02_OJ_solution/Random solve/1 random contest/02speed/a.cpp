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
int ar[maxx+10],n,k ; 
int calco(int p,int a)
{
   if(p%2==1){return !a;}else{return a;}
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n >> k ; 
      int temp = k ; 
      std::vector < int > br(n+10,0) ;
      string s ;
      cin >> s ;
      int idx = 1 ; 
      for(auto c : s )
      {
         int x = c=='1' ? 1 : 0 ; 
         ar[idx++] =x ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(temp==0){break;}
         if(calco(k,ar[i])==0)
         {
            br[i]++ ; 
            temp-- ; 
         }
      }
      int p = temp/2 ; 
      while(p--)
      {
         br[1]+=2 ; 
      }
      if(temp%2==1)
      {
         br[n]++ ; 
      }
      for(int i=1;i<=n;i++)
      {
         cout << calco(k-br[i],ar[i]) ; 
      }
      cout << endl ; 
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ;}
         cout << br[i+1] ; 
      }
      cout << endl ;
   }
   return 0 ;
}