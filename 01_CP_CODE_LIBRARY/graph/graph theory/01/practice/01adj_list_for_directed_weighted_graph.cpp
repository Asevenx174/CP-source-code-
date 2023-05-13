#include<bits\stdc++.h>
using namespace std ;
#define MAX 1000
vector < int > node [MAX] ;
vector < int > cost [MAX] ;
int main()
{
    int n,e,n1,n2,co;
    cin >> n >> e ;
    for(int i=1; i<=e; i++)
    {
        cin >> n1 >> n2 >> co ;
        node[n1].push_back(n2);
        cost[n1].push_back(co) ;
    }
    int x ;
    cin >> x ;
    int ss = node[x].size();
    cout << "number of connected node = " << ss << endl;
    for(int i=0;i<ss;i++)
    {
        cout << node[x][i]  << endl;/// x node sathe ktogula node connected ase shegula print krbe
    }
    return 0;
}
