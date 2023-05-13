#include<bits\stdc++.h>
using namespace std ;
#define mem(arr,n) memset(arr,n,sizeof(arr));
#define pii pair<int,int>
#define uu first
#define vv second
#define pb(x) push_back(x)
#define rep(i,n) for(int i=0;i<(int)n;i++);
#define valid(r,c) r>=1 && r<=row && c>=1 && c<=col

int row=8,col=8,fx[]={1,-1,0,0},fy[]={0,0,1,-1};
int vis[100][100],dis[100][100];

void bfs(int x,int y)
{
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    queue < pii > q ;
    q.push(pii(x,y));
    while(!q.empty())
    {
        pii top = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = top.uu + fx[i];
            int yy = top.vv + fy[i];
            if(valid(xx,yy))
            {
                vis[xx][yy]=1;
                dis[xx][yy]= dis[top.uu][top.vv]+1;
                q.push(pii(xx,yy));
            }
        }
    }
}
int main()
{
     printf("input source co-ordinate row and col\n");
     int x,y,m,n;
     cin >> x >> y ;
     bfs(x,y);
    // printf("input your destination co-ordinate\n minimum step = ");
    // cin >> m >> n ;
     //cout << dis[m][n] << endl;
     return 0;
}
