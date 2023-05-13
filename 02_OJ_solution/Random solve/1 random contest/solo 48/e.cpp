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
const ll maxx = 500+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10][maxx+10],sum=0,n,m ; 
int flag[10] ; 
int valid(int i,int j)
{
   if(ar[i][j]==0){return 0;}
   int ans = 1 ; 
   int y = j+1 ;
   while(y<=m && ar[i][y]==1)
   {
      ans++ ; 
      y++ ; 
      flag[1]=1 ; 
   }
   y = j-1 ; 
   while(y>0 && ar[i][y]==1)
   {
      ans++ ; 
      y-- ; 
      flag[2]=1;
   }

   int x = i+1 ;
   while(x<=n && ar[x][j]==1)
   {
      ans++ ; 
      x++ ; 
      flag[3]=1;
   }
   x = i-1 ; 
   while(x>0 && ar[x][j]==1)
   {
      ans++ ; 
      x-- ; 
      flag[4]=1;
   }
   return ans ; 
}
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      for(auto c : s)
      {
        int x = c=='*' ? 1 : 0 ; 
        ar[i+1][j+1] = x ;  
        j++ ; 
        sum+=x ; 
      }
   }
   int f = 0 ;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         ms(flag,0) ; 
         if(valid(i,j)==sum && flag[1]==1 && flag[2]==1 && flag[3]==1 && flag[4]==1)
         {
            f = 1 ;  
         }
      }
   }
   if(f && sum>3 )
   {
      cout << "YES" << endl ; 
   }
   else
   {
      cout << "NO" << endl ;
   }
   return 0 ;
}