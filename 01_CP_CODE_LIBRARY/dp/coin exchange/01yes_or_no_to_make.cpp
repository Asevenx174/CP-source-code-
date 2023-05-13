int coin[]= {5,8,11,15,18}; //value of coins available
int make; //our target value
int dp[6][100];///2 ta parameter so 2d array ,1st para hlo coin er index,2nd holo amount
int call(int i,int amount)
{
    if(i>=5)   //All coins have been taken,base case shob coin nea shesh
    {///base case 0/1 hoche recursuion sheshe egulai return krbe
        if(amount==make)
            return 1;///banaite parsi
        else
            return 0;///banaite pari nai
    }
    if(dp[i][amount]!=-1)///kaj kra hoise age so ager value tai return kre dei
    {
        return dp[i][amount]; //no need to calculate same state twice
    }
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make)
    {///i+1 bodoel abar i nisi cos ekhane coin infinite r ekta neai jai jdi nai >make na hoy
        ret1=call(i,amount+coin[i]); //try to take coin i
    }
    ret2=call(i+1,amount); //dont take coin i/// prer coin ta nia try kre dekhi
    return dp[i][amount]=ret1|ret2; //storing and returning.
/// i or i+1 mane ret1 or ret2 jekono ekta 1 hlei holo
///if we ret1+ret2 instead of ret1|ret2 then psb way gula jog hoy jabe so return krbe make kto vabe banano jabe
}
int main()
{
    // freopen("in","r",stdin);
    while(cin>>make)
    { ///ekhane bar bar initialized kra lagtese cos its depend on a global variable
        /// er optimization ta 02 code ase
        memset(dp,-1,sizeof(dp));///intially -1 kre nilam,-1 mane kaj kra hoi nai
        cout<<call(0,0)<<endl;/// this func will tell us whether its psb to make make
    }
    return 0;
}
