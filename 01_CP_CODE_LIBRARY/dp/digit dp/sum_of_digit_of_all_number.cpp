#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
int dp[10][2][85];
using namespace std ;
int cal(int idx,int state,int sum,vector< int > &v)
{
   if(idx==-1){return sum;};
   if(dp[idx][state][sum]!=-1){return dp[idx][state][sum];}
   int  limit = state ==0 ? 9 : v[idx];
   int ret=0;
   for(int i=0;i<=limit;i++)
   {
       int new_state = (i==limit) ? 1 : 0 ;
       ret+=cal(idx-1,new_state,sum+i,v);
   }
   dp[idx][state][sum]=ret;
   return ret;
}
void store_digit(int n ,vector < int > &v)
{
    while(n>9)
    {
        v.push_back(n%10);
        n/=10;
    }
    v.push_back(n%10);
}
int sum_of_digit(int l,int r)
{
    int first,second;
    vector < int > digitl,digitr;
    store_digit(l-1,digitl);
    store_digit(r,digitr);
    memset(dp,-1,sizeof(dp));
    first = cal (digitl.size()-1,1,0,digitl);
    memset(dp,-1,sizeof(dp));
    second = cal(digitr.size()-1,1,0,digitr);
    return second-first;
}
int main()
{
    ///find sum of digit of all number range l to r
    int l,r;
    cin >> l >> r ;
    cout << sum_of_digit(l,r) << endl;
    return 0;
}
