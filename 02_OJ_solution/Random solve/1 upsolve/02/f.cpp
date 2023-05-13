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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1505 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int fx[10] = {1,1,-1,-1} ; 
int fy[10] = {-1,1,-1,1} ;
int n,ar[maxx][maxx],sx,sy,ex,ey,dis[maxx][maxx] ; 

bool dp[maxx][maxx][8] ; 

// find shortest path from node 1 to all nodes 
int pi[maxx][maxx],mov[maxx][maxx] ; 
unordered_map < int , pii > ip ;  
bool vis[maxx][maxx] ; 
void dijkstra()
{
    dis[sx][sy] = 0 ;
    priority_queue< pii,vector<pii>,greater<pii>> q ;
    q.push({0, pi[sx][sy] });
    mov[sx][sy]=4 ;  
    while(!q.empty())
    {
        pii p = q.top();
        q.pop();
 
        int u = p.ss, cost = p.ff ;
        p = ip[u] ; 
        int x = p.ff ;
        int y = p.ss ; 
        vis[x][y] = true ; 
        int pmov = mov[x][y] ; 
        int temp = 1,op=0 ; 
        vector < bool > k(10,false) ; 
        while(temp<=n)
        {
        if(op==4){break;}
        for (int i = 0; i < 4 ; ++i)
        {
          if(k[i]){continue;}
          int nx = x+fx[i]*temp ; 
          int ny = y+fy[i]*temp ; 
          if(min(nx,ny)>0 && max(nx,ny)<=n)
          { 
            if(ar[nx][ny]==1){op++;k[i]=true;continue;}
            int add = pmov==i ? 0 : 1 ; 
            if(!vis[nx][ny])
            {
               dis[nx][ny] = dis[x][y]+add ; 
               mov[nx][ny] = i ; 
               q.push({dis[nx][ny],pi[nx][ny]}) ;  
            }
          }
        }
        temp++ ; 
        }
    }
}

int main()
{
   debugMode();
   cin >> n ;
   cin >> sx >> sy ; 
   cin >> ex >> ey ; 
   int idx = 1 ; 
   for (int i = 0; i < n ; ++i)
   {
      string s ;
      cin >> s ;
      int j = 0 ; 
      for(auto c : s)
      {
         int x = c=='.' ? 0 : 1 ; 
         ar[i+1][j+1] = x ; 
         dis[i+1][j+1] = mod ; 
         pi[i+1][j+1]=idx ; 
         ip[idx]={i+1,j+1} ; 
         idx++ ; 
         j++ ; 
      }
   }
   dijkstra() ; 
   int ans = dis[ex][ey] ; 
   if(ans==mod){ans=-1;}
   cout << ans << endl ;
   return 0 ;
}