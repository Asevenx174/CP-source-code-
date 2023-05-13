#include<iostream>
using namespace std ;
int cost[1005],weight[1005],num,cap,dp[10005];
int unboundedknapsack()
{
    ///1 theke cap prjonto shob cap jnno best result ber krbo
    ///like c=25 but cap 30
    /// c=25 jnno shob gula item check kre dekhbo
    for(int c=1;c<=cap;c++)///capacity
    {
        for(int j=1;j<=num;j++)///item
        {
            if(c>=weight[j])///cap 25 hle 25 to 26 dia create kra jabe na
            {
                dp[c]=max(dp[c],cost[j]+dp[c-weight[j]]);
            }
        }
    }
    return dp[cap];
}
int main()
{
    ///here items can be used as many as u want
    cin >> num >> cap ;
    for(int i=1;i<=num;i++)
    {
        int x,y;
        cin >> x >> y ;
        cost[i]=x;
        weight[i]=y;
    }
    cout <<  unboundedknapsack() << endl ;
    return 0;
}

