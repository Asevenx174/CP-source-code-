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
using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1e3+10,mod=1e9+7,imax=1e18+10;
bool vis[maxx][maxx];
int arr[maxx][maxx],idx,r,c,sx,sy,ex,ey,par[maxx][maxx];
int dx[10] = {1,-1,0,0} , dy[10] = {0,0,1,-1}  , req[maxx*maxx],dep[maxx][maxx];
map < pii ,pii > pq ;
void  bfs(int i,int j)
{
    vis[i][j]=true;
    queue < pii > q ;
    q.push({i,j});
    dep[i][j]=0;
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        i = p.ff , j = p.ss ;
        for(int k=0;k<4;k++)
        {
          int x = i+dx[k];
          int y = j+dy[k];
          if(!vis[x][y] && x>=1 && x<=r && y>=1 && y<=c && arr[x][y]!=0)
          {
            dep[x][y]=dep[i][j]+1;
            vis[x][y]=true;
            par[x][y]=k;
            pq[{x,y}]={i,j};
            q.push({x,y});
          }
        }
    }

}
int main()
{
   cin >> r >> c ;
   for(int i=1;i<=r;i++)
   {
       string s ;
       cin >> s ;
       idx = 1 ;
       for(auto c : s )
       {
           if(c=='.')
           {
               arr[i][idx]=1;
           }
           else if (c=='#')
           {
               arr[i][idx]=0;
           }
           else if (c=='A')
           {
               arr[i][idx]=3;
               sx = i ;
               sy = idx ;
           }
           else
           {
               arr[i][idx]=6;
               ex = i ;
               ey = idx ;
           }
           idx++;
       }
   }
   bfs(sx,sy);
   if(dep[ex][ey]==0){cout << "NO" << endl; return 0;}
   cout << "YES" << endl;
   cout << dep[ex][ey] << endl ;
   idx = 0 ;
   while(arr[ex][ey]!=3)
   {
        idx++;
        req[idx]=par[ex][ey];
        pii pp = pq[{ex,ey}];
        ex = pp.ff ;
        ey = pp.ss ;
   }
   for(int i=idx;i>0;i--)
   {
       if(req[i]==0)
       {
           cout << "D" ;
       }
       else if (req[i]==1)
       {
           cout << "U" ;
       }
       else if (req[i]==2)
       {
           cout << "R" ;
       }
       else
       {
           cout << "L" ;
       }
   }
   cout << endl;
   return 0 ;
}
