#include<bits\stdc++.h>
using namespace std ;
vector < int > v [10000];
vector < int > cost [10000];
int level[10000],parent[10000];
void bfs(int source,int des)
{
     memset(level,-1,sizeof(level));
     queue < int > q ;
     q.push(source);
     parent[source]=0;
     level[source]=0;
     while(q.size()!=0)
     {
         int u = q.front();
         q.pop();
         int siz=v[u].size();
         for(int i=0;i<siz;i++)
         {
             int x = v[u][i];
             if(level[x]==-1){level[x]=level[u]+1;q.push(x);parent[x]=u;}
         }
     }
     cout << level[des] << endl;
     while(parent[des]!=0)
     for(int i=0;i<level[des];i++)
     {
         cout << parent[des] << " " ;
         des =  parent[des] ;
     }
}
int main()
{
    int node,edge;
    printf("input node and edge\n");
    cin >> node >> edge ;
    for(int i=1;i<=edge;i++)
    {
        int x,y;
        cin >> x >> y ;
        v[x].push_back(y);
        v[y].push_back(x);
        cost[y].push_back(1);
        cost[x].push_back(1);
    }
    printf("input source node and destination node\n");
    int source,des;
    cin >> source >> des ;
    bfs(source,des);
    return 0;
}
