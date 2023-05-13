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
const ll maxx = 55 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[10] = {0,0,1,1} ;
int fy[10] = {1,0,0,1} ; 
int dx[10] = {0,-1,0,1} ;
int dy[10] = {-1,0,1,0} ; 
int kx[10] = {-1,-1,1,1} ;
int ky[10] = {-1,1,1,-1} ; 
int ar[maxx+10][maxx+10],n,m,co=2 ; 
void calco(int x,int y)
{
   if(x+1>n || y+1>m){return;}
   int sum = 0 ; 
   for (int i = 0; i < 4 ; ++i)
   {
      int a = x+fx[i] ; 
      int b = y+fy[i] ; 
      if(ar[a][b]>1){return;}
      if(ar[a][b]==1){sum++;}
   }
   if(sum!=3){return ;}
   //cout << sum << endl ;
   for (int i = 0; i < 4 ; ++i)
   {
      int a = x+fx[i] ; 
      int b = y+fy[i] ; 
      if(ar[a][b]==1)
      {
         //cout << a << " " << b << " " << co << endl ;
         ar[a][b] = co ; 
      }
   }
   co++ ; 
}
bool valid(int x,int y)
{
   for (int i = 0; i < 4 ; ++i)
   {
      int a = x+dx[i] ; 
      int b = y+dy[i] ; 
      if(min(a,b)==0 || a>n || b>m ){continue;}
      if(ar[a][b]!=ar[x][y]){ return  true ; }
   }
   for (int i = 0; i < 4 ; ++i)
   {
      int a = x+kx[i] ; 
      int b = y+ky[i] ; 
      if(min(a,b)==0 || a>n || b>m ){continue;}
      if(ar[a][b]!=ar[x][y]){return true ; }
   }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      co = 2 ; 
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s  )
         {
            int x = c=='*' ? 1 : 0 ; 
            ar[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            calco(i,j) ; 
         }
      }
      int f = 0 ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            if(ar[i][j]==1){f=0;continue;}
            if(valid(i,j) && ar[i][j]!=0)
            {
               f=0 ; 
            }
         }
      }
      if(f)
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