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
const ll maxx = 310 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll xr[maxx+10],yr[maxx+10],m,k,n,xx,yy;
set < pii > s ;  
map < pii ,int > pq ; 
std::vector< int > g[maxx*maxx] ;
bool used[maxx][maxx] ; 
void store(int i,int j,int z)
{
   int a = yr[i]-yr[j] ; 
   int b = xr[i]-xr[j] ; 
   int x = max(a,-a) ; 
   int y = max(b,-b) ; 
   int g = __gcd(x,y) ; 
   x = x/g ; 
   y = y/g ; 
   if(a<0){x=-x;}
   if(b<0){y=-y;}
   if(x*y>0)
   {
      x = max(x,-x) ; 
      y = max(y,-y) ; 
   }
   else if(x*y<0)
   {
      x = min(x,-x) ; 
      y = max(y,-y) ;
   }
   else
   {
      x = 0 ; 
      y = 0 ; 
   }
   xx = x ; 
   yy = y ; 
   if(z==0) { return ; }
   s.insert({x,y}) ;
}
int main()
{
   debugMode();
   cout << "yes" << endl ;
   cin >> n >> k ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i+1] >> yr[i+1] ; 
   }
   for (int i = 0; i < n ; ++i)
   {
      for (int j = 0; j < n ; ++j)
      {
         if(i==j){continue;}
         store(i+1,j+1,1) ; 
      }
   }
   int idx = 1,ans = 0  ; 
   for( auto p : s )
   {
      pq[p]=idx++ ; 
   }
   for(int i=1;i<=n;i++)
   {
     
      vector < int > temp[maxx*maxx] ; 
      set < int > pk ; 
      for(int j=1;j<=n;j++)
      {
         if(i==j){continue;}
         if(used[i][j]){continue;}
         store(i,j,0) ; 
         idx = pq[{xx,yy}] ;
         temp[idx].push_back(j) ; 
         pk.insert(idx) ; 
      }
      for(auto x : pk )
      {
         temp[x].push_back(i) ; 
         if(temp[x].size()>=k){ans++;}
         for(auto a : temp[x] )
         {
            for(auto b : temp[x] )
            {
               if(a==b){continue ;}
               used[a][b] = true ;
               used[b][a] = true ; 
            }
         }
      }
   }
   cout << ans << endl ; 
   return 0 ;
}