#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
int dp[10][2][85][85];
using namespace std ;
int cal(int idx,int state,int esum,int osum,vector< int > &v)
{
   if(idx==-1)
    {
      if(esum>osum)
        {
            return 1 ;
        }
        else
        {
            return 0 ;
        }
    };
   if(dp[idx][state][esum][osum]!=-1){return dp[idx][state][esum][osum];}
   int  limit = state ==0 ? 9 : v[idx];
   int ret=0;
   for(int i=0;i<=limit;i++)
   {
       int new_state = (i==limit) ? 1 : 0 ;
       if(i%2==0)
       {
           ret+=cal(idx-1,new_state,esum+i,osum,v);
       }
       else
       {
           ret+=cal(idx-1,new_state,esum,osum+i,v);
       }
   }
   dp[idx][state][esum][osum]=ret;
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
    first = cal (digitl.size()-1,1,0,0,digitl);
    memset(dp,-1,sizeof(dp));
    second = cal(digitr.size()-1,1,0,0,digitr);
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
