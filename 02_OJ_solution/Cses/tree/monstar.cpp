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
int arr[maxx][maxx],r,c,dis[maxx][maxx],req[maxx][maxx];
int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1},par[maxx][maxx];
bool used[maxx][maxx];
map < pii ,int > ans ;
map < pii , pii > ww ;
int bfs(int x,int y)
{
    if(arr[x][y]==4){return 0;}
    queue < pii > q ;
    q.push({x,y});
    ms(used,false);
    used[x][y]=true ;
    par[x][y]=0;
    while(!q.empty())
    {
        pii p = q.front() ;
        q.pop();
        x = p.ff ;
        y = p.ss ;
        for(int j=0;j<4;j++)
        {
            int xx = x+dx[j];
            int yy = y+dy[j];
            if(!used[xx][yy] && xx>0 && xx<=r && yy>0 && yy<=c && arr[xx][yy]!=1)
            {
                used[xx][yy]=true ;
                q.push({xx,yy});
                par[xx][yy]=par[x][y]+1;
                if(arr[xx][yy]==4){return par[xx][yy];}
            }
        }
    }
    return mod ;
}


void bfs2(int x,int y)
{
    queue < pii > q ;
    q.push({x,y});
    ms(used,false);
    used[x][y]=true ;
    par[x][y]=0;
    ww[{x,y}]={x,y};
    while(!q.empty())
    {
        pii p = q.front() ;
        q.pop();
        x = p.ff ;
        y = p.ss ;
        for(int j=0;j<4;j++)
        {
            int xx = x+dx[j];
            int yy = y+dy[j];
            if(!used[xx][yy] && xx>0 && xx<=r && yy>0 && yy<=c && arr[xx][yy]!=1 && par[x][y]+1<dis[xx][yy])
            {
                //cout << xx << " " << yy << " " << arr[xx][yy] << endl;
                used[xx][yy]=true ;
                q.push({xx,yy});
                par[xx][yy]=par[x][y]+1;
                ans[{xx,yy}]=j;
                ww[{xx,yy}]={x,y};
            }
        }
    }
}

int main()
{
   int sx,sy;
   ms(dis,mod);
   vector < pii > mon ;
   cin >> r >> c ;
   for(int i=1;i<=r;i++)
   {
       string s ;
       cin >> s ;
       int idx = 1 ;
       for(auto c : s )
       {
           if(c=='#')
           {
               arr[i][idx]=1;
           }
           else if (c=='.')
           {
               arr[i][idx]=2;
               mon.push_back({i,idx});
           }
           else if (c=='A')
           {
               arr[i][idx]=3;
               sx = i ;
               sy = idx ;
           }
           else
           {
               arr[i][idx]=4;
           }
           idx++;
       }
   }
   for(auto p : mon )
   {
       dis[p.ff][p.ss]=bfs(p.ff,p.ss);
   }
   ms(par,mod);
   bfs2(sx,sy);
   int ex,ey,f=0;
   for(int i=1;i<=r;i++)
   {
       if(i==1 || i==r)
       {
           for(int j=1;j<=c;j++)
           {
               if(par[i][j]!=mod)
               {
                   ex = i ;
                   ey = j ;
                   f=1;
                   break;
               }
           }

       }
       else
       {
           if(par[i][1]!=mod)
           {
                   ex = i ;
                   ey = 1 ;
                   f=1;
                   break;
           }
           if(par[i][c]!=mod)
           {
                   ex = i ;
                   ey = c ;
                   f=1;
                   break;
           }
       }
       if(f==1){break;}
   }
   cout << par[1][1] << endl;
   if(f==1)
   {
       cout << "YES" << endl;
       string kk="" ;
       while(ex!=sx || ey!=sy)
       {
           int qq = ans[{ex,ey}] ;
           if(qq==0)
           {
               kk+='R';
           }
           else if (qq==1)
           {
               kk+='L';
           }
           else if (qq==2)
           {
              kk+='U';
           }
           else
           {
              kk+='D';
           }
           pii pp =  ww[{ex,ey}] ;
           ex = pp.ff ;
           ey = pp.ss ;
       }
       cout << kk.size() << endl;
       if(!kk.empty())
       {
           cout << kk << endl;
       }
   }
   else
   {
       cout << "NO" << endl;
   }
   return 0 ;
}
