#include<iostream>
#include<vector>
#include<cstring>
using namespace std ;
int dp[25][100][2];
void insert_in_v(int n,vector <int> &digit)
{
    while(n)
    {
      digit.push_back(n%10);
      n/=10;
    }
}
int result(int idx,int sum,int state,vector < int > &v)
{
    if(idx==-1){return sum;}///base case shob digit check kra shesh
    if(dp[idx][sum][state]!=-1 && state==0)///kaj kra hoise plus bounded na
    {
        return dp[idx][sum][state];
    }
    int k = (state == 0) ? 9 : v[idx];
    int ret=0;
    for(int i=0;i<=k;i++)
    {
        int new_state = (v[idx]==i) ? state : 0 ;
        cout << idx-1 << " " << sum+i << " " << state << endl;
        ret+=(result(idx-1,sum+i,new_state,v));
    }
    cout << endl;
    if(state==0){ dp[idx][sum][state]=ret;}
    return ret;
}
int sum_in_range(int a,int b)
{
    int first=0,second=0;
    vector < int > digita,digitb;

    insert_in_v(a-1,digita); ///a-1
    memset(dp,-1,sizeof(dp));
    first= result(digita.size()-1,0,1,digita); /// 0 index er jnno -1

    insert_in_v(b,digitb);///b
   /// memset(dp,-1,sizeof(dp));
    second = result(digitb.size()-1,0,1,digitb);
    return second-first;
}
int main()
{
    /// like a=7,b=10 so ans=7+8+9+1+0
    int a,b;
    cout << "input a and b int" << endl;
    cin >> a >> b ;
    cout <<  sum_in_range(a,b) << endl;;
    return 0;
}
