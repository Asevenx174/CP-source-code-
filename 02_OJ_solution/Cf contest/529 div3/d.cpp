#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
int in[maxx][5],n,p[maxx],f=0 ; 
bool used[maxx+10] ; 
void dfs(int g,int u,int idx)
{   
    used[u] = true ; 
    if(idx>n)
    {
       //p[u]=1 ; 
       return ;
    }
    int x = in[u][1] ; 
    int y = in[u][2] ; 
    int x1 = in[x][1],x2=in[x][2] ;
    int y1 = in[y][1],y2=in[y][2] ;

    // u > x 
    // u -> x,y 
    // x -> x1,x2 ; 
    if( (y==x1 || y==x2) && g!=x )
    {
        p[u] = x ; 
        dfs(u,x,idx+1) ; 
    }
    else if (x==y1 || x==y2 )
    {
        p[u] = y ;
        dfs(u,y,idx+1) ;
    }
}
int main()
{
   debugMode();
   cin >> n ; 
   lp(i,1,n)
   {
      cin >> in[i][1] >> in[i][2] ; 
   }
   dfs(0,1,1); 
   int c = 1 ; 
   do
   {
      if(c!=1){cout << " " ;}
      cout << c ; 
      c = p[c] ; 
   }
   while(c!=1); 
   cout << endl ;
   return 0 ;
}