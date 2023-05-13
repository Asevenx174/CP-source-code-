#include<bits/stdc++.h>
using namespace std ;
const int maxx = 105;
int parent[maxx+5];
void makeset(int nodes)
{
    for(int i=1;i<=nodes;i++)
    {
        parent[i]=i;
    }
}
int findd(int node)
{
    if(parent[node]==node)
    {
        return node; /// nijer parent nijei so nijei nijer set er representative
    }
    return parent[node]=findd(parent[node]);/// node er parent change kre dei//path compression
}
void unionn(int a,int b)
{
    int u = findd(a);
    int v = findd(b);
    if(u==v)
    {
        cout << "frineds" << endl;
    }
    else
    {
        parent[u]=v;
    }
}
int main()
{
    int nodes;
    cin >> nodes ;
    makeset(nodes);
    return 0 ;
}
