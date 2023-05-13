#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std ;
int prime[100],dp[2][12][90];
void gener()
{
    for(int i=4;i<100;i+=2){prime[i]=1;}
    prime[1]=1;
    prime[0]=1;
    for(int i=3;i<=10;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=i+i;j<100;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}
void store_value(int n,vector < int > &v)
{
    while(n>9)
    {
        v.push_back(n%10);
        n/=10;
    }
    v.push_back(n);
}
int get_value(int idx,int sum,int state,vector < int > &v)
{
    if(idx==-1){return !prime[sum];}
    if(dp[state][idx][sum]!=-1){return dp[state][idx][sum];}
    int k = (state == 1) ? v[idx] : 9 ;
    int ret=0;
    for(int i=0;i<=k;i++)
    {
        int new_state = (i==k) ? 1 : 0 ;
        ret+=get_value(idx-1,sum+i,new_state,v);
    }
    dp[state][idx][sum]=ret;
    return ret;
}
int gnum(int l,int r)
{
    vector < int > vl,vr;
    store_value(l-1,vl);
    store_value(r,vr);
    memset(dp,-1,sizeof(dp));
    int a = get_value(vl.size()-1,0,1,vl);
    memset(dp,-1,sizeof(dp));
    int b = get_value(vr.size()-1,0,1,vr);
    return b-a;
}
int main()
{
    gener();
    int t,l,r;
    cin >> t ;
    while(t--)
    {
       cin >> l >> r ;
       if(l>r){int temp;temp=l;l=r;r=temp;}
       cout << gnum(l,r) << endl;
    }
    return 0;
}
