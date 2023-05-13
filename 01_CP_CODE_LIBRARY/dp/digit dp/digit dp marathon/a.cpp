#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std ;
int arr[12],ans[12][12];
int e,cap;
int get_count(int idx,int prev)
{
    if(idx==cap){return 1;}
    if(ans[idx][prev]!=-1){return ans[idx][prev];}
    int ret=0;
    for(int i=0;i<e;i++)
    {
        if(prev==0 || abs(prev-arr[i])<=2)
        {
            ret+=get_count(idx+1,arr[i]);
        }
    }
    ans[idx][prev]=ret;
    return ret;
}
int main()
{
    int t;
    cin >> t ;
    for(int j=1;j<=t;j++)
    {
    memset(ans,-1,sizeof(ans));
    cin >> e >> cap ;
    for(int i=0;i<e;i++)
    {
        cin >> arr[i];
    }
    cout << "Case " << j << ": " << get_count(0,0) << endl;
    }
    return 0;
}
