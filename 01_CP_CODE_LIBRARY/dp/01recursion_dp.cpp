#include<bits\stdc++.h>
int dp[100];/// this is array is used to store the value that has been counted so that we dont need to calculate that value twice
using namespace std ;
int fab(int n)
{
    if(n==0)
    {
        return 0 ;
    }
    if (n==1)
    {
        return 1 ;
    }
    if(dp[n]!=-1)// value -1 na mane ekbar kaj kra hoise ,value ta store ase ,so ager calculate kra value tao return kri
    {
        return dp[n];
    }
    else
    {
        dp[n] = fab(n-1)+fab(n-2);
        return dp[n];
    }
}
int main()
{
    int n;
    cin >> n ;
    memset(dp,-1,sizeof(dp));
    cout << fab(n) << endl;
    return 0;
}
