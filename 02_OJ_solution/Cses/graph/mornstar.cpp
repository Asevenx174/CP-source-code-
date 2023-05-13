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
const ll maxx = 1010 ,mod=1e9+7,imax=1e18+10;
int dx[10] = {1,-1,0,0} , dy[10] = {0,0,1,-1};
ll arr[maxx+5][maxx+5],r,c,req[maxx+5][maxx+5],lvl[maxx+5][maxx+5],brr[maxx*maxx];
vector < pii > dot ;
int pq[maxx][maxx];
int par[maxx*4];
map < int ,pii  > lq ;
int ans[maxx][maxx];
ll bfs(ll x,ll y)
{
    queue < pii > q ;
    q.push( {x,y} );
    lvl[x][y]=0;
    while(!q.empty())
    {
        pii p = q.front() ;
        x = p.ff , y = p.ss ;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = x+dx[i] ;
            int yy = y+dy[i] ;
            if(xx>0 && xx<=r && yy>0 && yy<=c && arr[xx][yy]!=4 && lvl[xx][yy]> (lvl[x][y]+1) )
            {
                lvl[xx][yy]=lvl[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
}
void dfs(int x,int y)
{
    queue < pii > q ;
    q.push( {x,y} );
    req[x][y]=0;
    while(!q.empty())
    {
        pii p = q.front() ;
        x = p.ff , y = p.ss ;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = x+dx[i] ;
            int yy = y+dy[i] ;
            if(xx>0 && xx<=r && yy>0 && yy<=c && arr[xx][yy]!=4 && lvl[xx][yy]> (req[x][y]+1) && req[xx][yy]==mod )
            {
                req[xx][yy]=req[x][y]+1;
                q.push({xx,yy});
                ans[xx][yy]=i ;
                par[ pq[xx][yy] ] = pq[x][y] ;
            }
        }
    }
}
int main()
{
   for(int i=1;i<maxx;i++)
   {
       for(int j=1;j<maxx;j++)
       {
           lvl[i][j]=mod;
           req[i][j]=mod;
       }
   }
   int sx,sy,temp=1;
   cin >> r >> c ;
   for(int i=1;i<=r;i++)
   {
       string s ;
       cin >> s ;
       int idx = 1 ;
       for(auto c : s )
       {
           if(c=='.') { arr[i][idx] = 1 ;  }
           else if (c=='M') { arr[i][idx] = 2 ; dot.push_back( {i,idx} ); }
           else if (c=='A') { arr[i][idx] = 3 ; sx = i , sy = idx ; }
           else
           {
               arr[i][idx] = 4 ;
           }
           pq[i][idx]=temp;
           lq[temp]={i,idx};
           idx++;
           temp++;
       }
   }
   for(auto p : dot )
   {
       bfs(p.ff,p.ss);
   }
   dfs(sx,sy);
   int ex=-1,ey=-1 ;
   for(int i=1;i<=r;i++)
   {
       if(i==1 || i==r)
       {
           for(int j=1;j<=c;j++)
           {
               if(req[i][j]!=mod)
               {
                   ex = i ;
                   ey = j ;
               }
           }
       }
       else
       {
           if(req[i][1]!=mod)
           {
               ex = i ;
               ey = 1 ;
           }
           if(req[i][c]!=mod)
           {
               ex = i ;
               ey = c ;
           }
       }
       if(ex!=-1){break;}
   }
   //cout << ex << " ?? " << ey << endl ;
   if(ex==-1){cout << "NO" << endl ; return 0 ; }
   if(req[ex][ey]==0)
   {
       cout << "YES" << endl ;
       cout << "0" << endl ;
       return 0;
   }
   int k = 0 ;
   while(1)
   {
       pii p = lq[pq[ex][ey]];
       //cout << ex << " " << ey << " -> " << p.ff << " " << p.ss << endl;
       if(p.ff==sx && p.ss==sy)
       {
           brr[++k]=ans[ex][ey];
           break;
       }
       else
       {
           brr[++k]=ans[ex][ey];
           ex = p.ff ;
           ey = p.ss ;
       }
   }
   cout << "YES" << endl;
   cout << k << endl;
   for(int i=k;i>0;i--)
   {
       if(brr[i]==0)
       {
           cout << "D" ;
       }
       else if (brr[i]==1)
       {
           cout << "U" ;
       }
       else if (brr[i]==2)
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
