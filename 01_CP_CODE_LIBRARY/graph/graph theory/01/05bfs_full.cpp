#include<cstdio>
#include<vector>
#include<bits\stdc++.h>
using namespace std;
#define MAX 1000 //maximum node
#define ll long long
vector<ll>graph[MAX];
vector<ll>cost[MAX]; //parallel vector to store costs;
ll lvl[10000]; // for counting the level. Or shortest distance of every node from starting node.
void bfs(ll starting_node)
{
    queue < ll > qq;
    qq.push(starting_node);
    memset(lvl, -1, sizeof lvl);///level -1 kre nilam shob
    lvl[starting_node] = 0;///source node lvl 0
    while(!qq.empty())
    {
        ll top = qq.front();
        qq.pop();
        ll sz = graph[top].size();///top er sathe connected node shonkha
        for(ll i = 0; i < sz; i++)
        {
            ll v = graph[top][i];
            if(lvl[v] != -1) continue;///-1 shoman na mane touched
            lvl[v] = lvl[top] + 1;
            qq.push(v);
        }
    }
}
int main()/// egula kintu vector er array ///////////////////////////////////////
{
    int N,E,i;
    scanf("%d%d",&N,&E);///n means number of node and e means number of edge
    for(i=1; i<=E; i++)
    {
        ///its a unweighted and undirected graph
        int x,y;/// x to y node
        scanf("%d%d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost[x].push_back(1);/// 1 for unweighted graph ,unweighted graph er jnno na use krleo chole
        cost[y].push_back(1);
        ///x,y er jnno same cost dia bujhaitaisi tara connected
    }
    bfs(1);
    cout << lvl[10]<< endl;/// we want to know distance of 10 from staring node
  /* int  ss=graph[1].size();/// 1 number node sathe ei prjont koeta node add hoise ?? mane push_back kre input disi
    for(int i=0; i < ss ; i++)
        printf("%lld ",graph[1][i]);///will print those node who have connection with node 1*/
    return 0;
}
