#include<bits/stdc++.h>
using namespace std ;
long long  dp[1000],maxx,minn;
void calco(long long  x)
{
    maxx = 0 ;
    minn = 1e9+5;
    while(x>0)
    {
        long long d = x%10;
        x/=10;
        minn=min(d,minn);
        maxx=max(d,maxx);
    }
}
int main()
{
    int test ;
    cin >> test ;
    while(test--)
    {
        long long  a,k,ans ;
        cin >> a >> k ;
        dp[1]=a ;
        ans=a;
        for(long long  i=2;i<=k;i++)
        {
            calco(dp[i-1]);
           // cout << minn << " " << maxx << endl;
            dp[i]=dp[i-1]+minn*maxx;
            if(minn==0 || i==k ){ans=dp[i];break;}
        }
        cout << ans << endl;
    }
    return 0 ;
}
