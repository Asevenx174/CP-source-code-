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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 305 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int dis[maxx][maxx],f[maxx][maxx],crr[maxx][maxx]; 
std::vector< int > g[maxx] ;
int main()
{
   debugMode();
   ms(dis,mod) ; 
   int n,m ;
   cin >> n >> m ; 
   for (int i = 0; i < m ; ++i)
   {
       int u,v,w ;
       cin >> u >> v >> w ; 
       dis[u][v] = w ; 
       dis[v][u] = w ; 
       crr[u][v] = w ; 
       crr[v][u] = w ; 
       g[u].push_back(v) ; 
       g[v].push_back(u) ; 
   }
   for(int m=1;m<=n;m++)
   {
      for(int l=1;l<=n;l++)
      {
         for(int r=1;r<=n;r++)
         {
            if(l==r){ dis[l][r]=0; continue ; }
            int temp =  dis[l][m]+dis[m][r] ; 
            if(temp==crr[l][r] && m!=l && m!=r )
            {
               f[l][r] = 1 ; 
               //cout << l << " " << r << endl ;
            }
            dis[l][r] = min(dis[l][r],temp) ; 
         }
      }
   }
   int ans = 0 ; 
   for(int l=1;l<=n;l++)
   {
         for(int r=1;r<=n;r++)
         {
            if(l==r){ continue ; }
            if(f[l][r]==1){ans++;}
            //cout << l << "  " << r << " " << dis[l][r] << endl ;
         }
   }
   ans = ans/2 ; 
   cout << ans << endl ;
   return 0 ;
}