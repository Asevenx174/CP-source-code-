#include<bits\stdc++.h>
#define pii pair <int,int>
#define valid(x,y) x>=1 && x<=row && c>=1 && c<=col
#define uu first
#define vv second
#define mem(arr,n) memset(arr,n,sizeof(arr));
#include<map>
vector  < pii ,pii > m;
int des[100][100],vis[100][100];
int fx[]={0,0,1,-1},fy[]={1,-1,0,0};
int row=8,col=8;
using namespace std ;
void bfs(int r,int c)
{
    map < pii ,pii > m;
    memset(vis,0,sizeof(vis));
    vis[r][c]=1;
    des[r][c]=0;
    queue < pii > q ;
    q.push(pii(r,c));
    while(!q.empty())
    {
        pii top = q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = top.uu + fx[i];
            int yy = top.vv + fy[i];
            if(xx>=1 && xx<=row && yy>=1 && yy<=col && vis[xx][yy]==0)
            {
                vis[xx][yy]=1;des[xx][yy]=des[top.uu][top.vv]+1;
                m[pii(xx,yy)]=pii(top.uu,top.vv);
                q.push(pii(xx,yy));
            }
        }
    }
}
int main()
{
    cout <<"input source co-ordinate" << endl;
    int x,y,z,p;
    cin >> x >> y ;
    bfs(x,y);
    cout << "destination co-ordinate" << endl;
    cin >> x >> y ;
    z=des[x][y];
    cout << z << endl;
    cout << "path->" << endl;
    while(z--)
    {
       pii p = m[pii(x,y)];
       cout << p.uu << " " << p.vv << endl;
       x=p.uu;y=p.vv;
    }
    return 0;
}

