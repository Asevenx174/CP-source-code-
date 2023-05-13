#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std ;
int dp[10][100][100][2],k;
int store_v(int n,vector < int > &v)
{
    while(n)
    {
        v.push_back(n%10);
        n/=10;
    }
}
int divret(int idx,int digitsum,int num,int state,vector <int> &v)
{
    if(idx==-1){if(num%k==0 && digitsum%k==0){return 1;}else{return 0;}}
    if(dp[idx][digitsum][num][state]!=-1 && state==0){return dp[idx][digitsum][num][state];}
    int limit = (state==0) ? 9 : v[idx];
    int ret=0;
    for(int i=0;i<=limit;i++)
    {
        int new_state = (i==v[idx]) ? state : 0 ;
        ret+=divret(idx-1,digitsum+i,(num*10+i)%k,new_state,v);
    }
    if(state==0){dp[idx][digitsum][num][state]=ret;}
    return ret;
}
int getnum(int left,int right)
{
    int l,r;
    vector < int > vl,vr;
    store_v(left-1,vl);
    store_v(right,vr);
    memset(dp,-1,sizeof(dp));
    l=divret(vl.size()-1,0,0,1,vl);
    memset(dp,-1,sizeof(dp));
    r=divret(vr.size()-1,0,0,1,vr);
    return r-l;
}
int main()
{
    int t;
    cin >> t ;
    for(int i=1;i<=t;i++)
    {
    int left,right;
    cin >> left >> right >> k;
    if(left>right){int temp;temp=right;right=left;left=temp;}
    if(k>99){cout << "Case " << i << ": " <<"0" << endl;}
    else{cout << "Case " << i << ": " <<getnum(left,right) << endl;}
    }
    return 0;
}
