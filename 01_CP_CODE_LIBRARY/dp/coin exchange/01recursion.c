int coin[]= {5,8,11,15,18}; //value of coins available
int make; //our target value
int dp[6][100];
int call(int i,int amount)///i coins er index ,amount ager nea coin er sum
{
    if(i>=5)   //All coins have been taken
    {
        if(amount==make)
            return 1;/// shob coin nia cheak krar pro jdio make touri kra jae
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make)
        ret1=call(i,amount+coin[i]); //try to take coin i
    ret2=call(i+1,amount); //dont take coin i
    return dp[i][amount]=ret1|ret2; //storing and returning.

}
int main()
{
    // freopen("in","r",stdin);
    while(cin>>make)
    {
        memset(dp,-1,sizeof(dp));/// intially -1 kre nichi
        cout<<call(0,0)<<endl;
///call func is used for whether we can collect make from those coins
    }
    return 0;
}
