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
int ar[maxx+10][maxx+10],n,m,col ; 
int fx[10]={0,0,1,1},fy[10]={0,1,1,0} ;
int gx[15]={-1,0,1,0,-1,-1,1,1},gy[15]={0,1,0,-1,-1,1,1,-1} ;
bool lim(int x,int y)
{
   if(min(x,y)==0 || x>n || y>m){return true ;}
   return false ; 
}
bool check(int i,int j)
{
   if(ar[i][j]==1){return false;}
   if(ar[i][j]==0){return true;}
   for (int idx = 0; idx < 8 ; ++idx)
   {
      int x = i+gx[idx] ; 
      int y = j+gy[idx] ; 
      if(lim(x,y)){continue;}
      if(ar[x][y]>1 && ar[x][y]!=ar[i][j]){return false;}
   }
   return true ; 
}
void valid(int i,int j)
{
   int a = 0 ; 
   int b = 0 ; 
   for (int idx = 0; idx < 4 ; ++idx)
   {
      int x = i+fx[idx] ; 
      int y = j+fy[idx] ; 
      if(lim(x,y)){continue;}
      if(ar[x][y]==0){a++;}else if(ar[x][y]==1){b++;}
   }
   //cout << i << " " << j << "->> " << a << " " << b << endl ;
   if( !(a==1 && b==3) )
   {
      return ; 
   }
   //cout << i << " " << j << endl ;
   for (int idx = 0; idx < 4 ; ++idx)
   {
      int x = i+fx[idx] ; 
      int y = j+fy[idx] ; 
      if(lim(x,y)){continue;}
      if(ar[x][y]==1)
      {
         ar[x][y] = col ; 
      }
   }
   col++ ; 
   return ;
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      col = 2 ; 
      cin >> n >> m ;
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ;
         for(auto c : s )
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
             valid(i,j) ; 
         }
      }
      int flag = 1 ; 
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            //cout << ar[i][j] ; 
            if(!check(i,j)){flag=0;}
         }
         //cout << endl ;
      }
      if(flag)
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