#include<bits\stdc++.h>
using namespace std ;
bool saved [1000][1000];///dp krar jnno,same solution bar bar kra jate na lage
int dp[1000][1000];///lcm func er 2 ta parameter so
string a,b;
int lcm(int la,int lb)
{
    if(la==0 || lb==0)///base case
    {
        return 0 ;///ntun kre kisu add hbe na
    }
    if(saved[la][lb]==true)///same solution abar krte chai na
    {
        return dp[la][lb];
    }
    int l=0;
    if(a[la]==b[lb])///match khaise so 1 jog kre prer gula nia kaj kri
    {
        l=1+lcm(la-1,lb-1);
    }
    else
    {
        l=max(lcm(la-1,lb),lcm(la,lb-1));///match khae na so 2 ta option,tar mdde best ta nei
    }
    saved[la][lb]=true;///solution ta save kre rakhi
    dp[la][lb]=l;///value store kre rakhi
    return dp[la][lb];
}
int main()
{
    int la,lb;
    cin >> a >> b ;
    la= a.size();
    lb = b.size();
    cout << lcm(la,lb) << endl;;
    return 0;
}
