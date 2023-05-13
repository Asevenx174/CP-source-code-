

#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 50+10,mod=30,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

int n=3,m ;
int board[maxx+5][maxx+5], dp[maxx+5][(1<<5)];

bool occupied(int i, int q)
{ 
    return q&(1 << (i-1)) ;
}

void search(int i, int j, int p, int q)
{
    if(i == n+1)
    {
        dp[j+1][p] += dp[j][q]; // jth col fill up complete [ dp[j][q]-->dp[j+1][p] ]
        return;
    }
    if(occupied(i, q))// i'th row er kth bit on ?
    {
        search(i+1, j, p, q);
        return;
    }
    if(i+1 <= n && !occupied(i+1, q))// ith and (i+1)th bit on
    {
        search(i+2, j, p, q);
    }
    if(j+1 <= m)
    {
        search(i+1, j, p^(1 << (i-1)), q); // next col er ith bit on kre dei
    }
}

int main()
{
    debugMode() ; 
    cin >> m ; 
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; //Initial condition // filling 0th column,no cell occupied (1th col)
    for(int j = 0; j < m; j++)
    {
        for(int q = 0; q < (1<<n); q++)
        {
            search(1, j, 0, q);
        }
    }
    cout<<dp[m][0]<<endl;
}