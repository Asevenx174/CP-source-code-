#include<bits/stdc++.h>
using namespace std ;
const int maxx = 1e5+5 ;
int parent[maxx+5],sized[maxx+5];
void make_set(int v)
{
    parent[v] = v;
    sized[v]=1;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void unionn(int a,int b)
{
    int p = findd(a);
    int q = findd(b);
    if(p!=q)
    {
        if(sized[p]<sized[q])
        {
            swap(p,q);
            swap(a,b);
        }
        parent[q]=p;
        sized[p]+=sized[q];
    }
}
int main()
{

    return 0 ;
}
