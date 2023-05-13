#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std ;
#define pb push_back
#define pii pair<int,int>
#define uu first
#define vv second
#define mem(arr,n) memset(arr,n,sizeof(arr));

int main()
{
    while(1)
    {
        vector < int > n1[10005];
        int color[100010];
        mem(color,-1);
        int node,edge,f=0;
        cin >> node ;
        if(node==0){return 0;}
        cin >> edge;
        while(edge--)
        {
            int x,y ; cin >> x >> y  ; n1[x].pb(y) ; n1[y].pb(x);
        }
        color[0]=0;
        queue < int > q ;
        q.push(0);
        while(!q.empty())
        {
            int top = q.front() ; q.pop();
            int siz=n1[top].size();
            for(int i=0;i<siz;i++)
            {
                int y = n1[top][i] ;
                if(color[y]==-1)
                {
                    int p = color[top]==1 ? 0 : 1 ;
                    color[y]=p;
                    q.push(y);
                }
                else if(color[y]==color[top]){f=1;break;}
            }
            if(f==1){break;}
        }
        if(f==0){cout << "BICOLORABLE." << endl;}else{cout << "NOT BICOLORABLE." << endl;};
    }
return 0;}
