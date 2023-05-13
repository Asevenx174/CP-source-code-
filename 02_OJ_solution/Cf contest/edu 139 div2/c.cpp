#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[5][maxx+10],n ; 
string sr[5] ; 
int to=0,fx=0,fy=0,co=0 ;
void dfs(int x,int y,int p)
{
   co++ ;  
   if(p<2)
   {
      if(x==1)
      {
         if(ar[2][y])
         {
            dfs(2,y,4) ; 
            return ;
         }
      }
      else
      {
         if(ar[1][y])
         {
            dfs(1,y,2) ;
            return ;
         }
      }
   }
   if(ar[x][y+1])
   {
       dfs(x,y+1,1) ; 
   }
} 
void solve()
{
   int lx=0,ly=0 ;  
   co = 0 ; 
   fx = 0 ; 
   to = 0 ; 
   cin >> n ; 
   cin >> sr[0] >> sr[1] ;
   for (int j = 0; j < n ; ++j )
   {
      int u = sr[0][j]=='B' ? 1 : 0 ; 
      int d = sr[1][j]=='B' ? 1 : 0 ; 
      ar[1][j+1] = u ; 
      ar[2][j+1] = d ; 
      if(u==1 && fx==0)
      {
         fx = 1 ; 
         fy = j+1 ; 
         if(ar[2][j+1])
         {
            lx = 2 ; 
            ly = j+1 ; 
         }
      }
      else if(d==1 && fx==0)
      {
         fx = 2 ; 
         fy = j+1 ; 
         if(ar[1][j+1])
         {
            lx = 1 ; 
            ly = j+1 ; 
         }
      }
      to+=(u+d) ; 
   }
   ar[1][n+1] = 0 ; 
   ar[2][n+1] = 0 ; 
   if(fx==0){ cout << "YES" << endl ; return ;}
   dfs(fx,fy,0) ; 
   if(co!=to && lx!=0)
   {
      co = 0 ; 
      dfs(lx,ly,0) ; 
   }
   if(co==to)
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ;
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}