#include<bits\stdc++.h>
#define pii pair <int,int>
#define mp make_pair
///#define pb push_back
#define ff first
#define ss second
using namespace std ;
int nodes,edges;
int main()
{
    vector < pair < int, pair<int,int > >  > v ;
    cin >> nodes >> edges ;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cin >> u >> v >> w ;
        v.push_back(mp(1,mp(2,3)));
    }
    return 0;
}
