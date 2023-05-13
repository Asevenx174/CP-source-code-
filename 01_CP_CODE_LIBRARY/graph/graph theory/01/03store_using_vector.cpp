#include<cstdio>
#include<vector>
#include<bits\stdc++.h>
using namespace std;
#define MAX 1000 //maximum node
vector<int>edges[MAX];
vector<int>cost[MAX]; //parallel vector to store costs;
int main()/// egula kintu vector er array ///////////////////////////////////////
{
    int N,E,i;
    scanf("%d%d",&N,&E);///n means number of node and e means number of edge
    for(i=1; i<=E; i++)
    {
        ///its a unweighted and undirected graph
        int x,y;/// x to y node
        scanf("%d%d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        cost[x].push_back(1);/// 1 for unweighted graph ,unweighted graph er jnno na use krleo chole
        cost[y].push_back(1);
        ///x,y er jnno same cost dia bujhaitaisi tara connected
    }
   int  ss=edges[1].size();/// 1 number node sathe ei prjont koeta node add hoise ?? mane push_back kre input disi
    for(int i=0; i < ss ; i++)
        printf("%d ",edges[1][i]);///will print those node who have connection with node 1
    return 0;
}
