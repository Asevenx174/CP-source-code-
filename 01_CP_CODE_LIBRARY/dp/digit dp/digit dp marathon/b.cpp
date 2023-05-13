#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stdio.h>
using namespace std ;
int dp[2][10][100][100],k;
void store_value(int n ,vector < int > &v)
{
    while(n>9)
    {
        v.push_back(n%10);
        n/=10;
    }
    v.push_back(n);
}
int sum(int state,int idx,int num,int digit,vector <int > &v)
{
    if(idx==-1)
    {
       return !(num+digit%k);
    }
    if(dp[state][idx][num][digit]!=-1){return dp[state][idx][num][digit];}
    int k = (state == 1) ? v[idx] : 9 ;
    int ret=0;
    for(int i=0;i<=k;i++)
    {
        int new_state = (k==i) ? 1 : 0 ;
        ret += sum(new_state,idx,(num*10+i)%k,digit+i,v);
    }
    dp[state][idx][num][digit]=ret;
    return ret;
}
int sum_of_digit(int l,int r)
{
    int left,right;
    vector < int > vl,vr;
    store_value(l-1,vl);
    store_value(r,vr);
    memset(dp,-1,sizeof(dp));
    left = sum(vl.size()-1,0,0,1,vl);
    memset(dp,-1,sizeof(dp));
    right = sum(vr.size()-1,0,0,1,vr);
    return right-left;
}
int main()
{
    int l,r;
    cin >> l >> r >> k ;
    cout << sum_of_digit(l,r) << endl;
    return 0;
}
