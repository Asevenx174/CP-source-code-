#include<iostream>
#include<cstring>
using namespace std ;
int weight[1000],value[1000],pro,num;
int knapsack(int cap,int p)
{
    int dp[cap+2][num+2];
    memset(dp,-1,sizeof(dp));
    if(dp[cap][p]!=-1){return dp[cap][p];}
    if(cap<0){return -value[p];}
    if(cap==0 || p>=pro){return 0;}
    int ans = max(knapsack(cap,p+1),knapsack(cap-weight[p],p+1)+value[p]);
    dp[cap][p]=ans;
    return ans;
}
int main()
{
    int cap;
    cin >> pro >> cap ;
    for(int i=0;i<pro;i++)
    {
        int x,y;
        cin >> x >> y ;
        value[i]=x;
        weight[i]=y;
    }
    cout << knapsack(cap,0) << endl;
    return 0;
}
