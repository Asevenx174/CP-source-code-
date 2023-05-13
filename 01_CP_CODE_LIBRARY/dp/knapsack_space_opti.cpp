#include<iostream>
#include<cstring>
using namespace std ;
int cap,pro,val[1000],weight[1000];
int knapsack()
{
    int i=0;
    int dp[2][cap+1];///2ta row thakle kaj chole
    memset(dp,0,sizeof(dp));
    while(i<pro)
    {
        int j=0;
        int x = i%2;///ei line important
        while(j<=cap)
        {
            if(weight[i]<=j)
            {
                ///i'th element nilam ,near pro jarga thakle [!x][j-weight[i] nibo
                dp[x][j]=max(dp[!x][j],val[i]+dp[!x][j-weight[i]]);
            }
            else
            {
                ///ager row same col er value ta optimal solution
                dp[x][j]=dp[!x][j];
            }
            j++;
        }
        i++;
    }
    /// row to 2ta ,value koi ase ?
    return (pro%2==1) ? dp[0][cap] : dp[1][cap] ;
}
int main()
{
    cin >>  cap >> pro ;
    for(int i=0;i<pro;i++)
    {
        int x,y;
        cin >> x >> y ;
        val[i]=x;
        weight[i]=y;
    }
    cout << knapsack() << endl;
    return 0;
}
