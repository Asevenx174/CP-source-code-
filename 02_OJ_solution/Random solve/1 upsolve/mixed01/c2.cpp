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
const ll maxx = 30 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;


int ar[maxx+10][maxx+10] ; 
string sr[maxx+10] ; 
int main()
{
   //debugMode();
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> sr[i] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      int j = 0 ; 
      string s = sr[i] ;
      for(auto c : s )
      {
         int x = c=='B' ? 1 : 0 ; 
         ar[i+1][j+1] = x ; 
         j++ ; 
      }
   }
   int r = n ; 
   int c = n ; 
   int f = 1 ; 
   for(int i=1;i<=r;i++)
   {
      int a = 0 , b = 0 ; 
      for(int j=1;j<=c;j++)
      {
         if(ar[i][j]==1){a++;}else{b++;}
         if(j+2<=c && ar[i][j]==ar[i][j+1] && ar[i][j]==ar[i][j+2] )
         {
            f = 0 ; 
         }
      }
      if(a!=b){f=0;}
   }
   for(int i=1;i<=c;i++)
   {
      int a = 0 , b = 0 ; 
      for(int j=1;j<=r;j++)
      {
         if(ar[j][i]==1){a++;}else{b++;}
         if(j+2<=r && ar[j][i]==ar[j+1][i] && ar[j][i]==ar[j+2][i] )
         {
            f = 0 ; 
         }
      }
      if(a!=b){f=0;}
   }
   cout << f << endl ;
   return 0 ;
}