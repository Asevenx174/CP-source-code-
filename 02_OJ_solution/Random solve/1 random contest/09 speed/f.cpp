#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll maxx = 1e6+10,mod=1e9+7 ; 
ll dp[maxx+10],ar[maxx+10],n,sum ; 
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main( )
{
    debugMode();
    cin >> n >> sum ;
    for(int i = 1 ; i <= n; i++)
    {
        cin >> ar[i] ; 
    }
    dp[0] = 1;
    for(int i = 1 ; i <= sum ; i++)
    {
        for(int j=1 ; j <= n; j++)
        {
           ll val = i-ar[j] ; 
           if(val>=0)
           {
              dp[i] = (dp[i]+dp[val]+mod)%mod ;
           }
        }
    }
    cout << dp[sum] << endl ;
}
