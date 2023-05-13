#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std ;
int dp[2][12][100][100];
void store_value(long long  n,vector < int > &v)
{
    while(n>9)
    {
        v.push_back(n%10);
        n/=10;
    }
    v.push_back(n);
}
int bin(long long  n)
{
    int arr[2],i=0,temp=0;
    while(n)
    {
        arr[i%2]=n%2;
        if(i!=0 && arr[0]==1 && arr[1]==1)
        {
            temp++;
        }
        i++;
        n/=2;
    }
    return temp;
}
int get_value(int idx,int sum,int num,int state,vector < int > &v)
{
    if(idx==-1){return sum;}
    if(dp[state][idx][sum][num]!=-1){return dp[state][idx][sum][num];}
    int kk = (state == 1) ? v[idx] : 9 ;
    int ret=0;
    for(int i=0;i<=kk;i++)
    {
        int new_state = (i==v[idx]) ? state : 0 ;
        int x = 10*num+i;
        int y = bin(x);
        ret+=get_value(idx-1,sum+y,x,new_state,v);
    }
    dp[state][idx][sum][num]=ret;
    return ret;
}
int gnum(long long   l)
{
    vector < int > vl;
    store_value(l,vl);
    memset(dp,-1,sizeof(dp));
    int a = get_value(vl.size()-1,0,0,1,vl);
    return a;
}
int main()
{
    int t ;
    long long l;
    cin >> t ;
    for(int i=1;i<=t;i++)
       {
       cin >> l ;
       cout << "Case " << i << ": " << gnum(l) << endl;
       }
    return 0;
}
