#include<iostream>
using namespace std ;
#define MAX 105
int dp[MAX][MAX],saved[MAX][MAX],row[MAX],col[MAX];
int min_scaler_product(int beg,int last)
{
    if(beg>=last){return 0;}
    if(saved[beg][last]!=0){return dp[beg][last];}
    int ans = 1<<30;
    for(int mid=beg;mid<last;mid++)
    {
        int o = min_scaler_product(beg,mid);
        int t = min_scaler_product(mid+1,last);
        int extra = row[beg]*col[mid]*col[last]; /// extra hlo o and t er product er scaler product number
        int total=o+t+extra;
        ans=min(total,ans);
    }
    saved[beg][last]=1;
    dp[beg][last]=ans;
    return dp[beg][last];
}
int main()
{
    int n ;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        int r,c;
        cin >> r >> c ;
        row[i]=r;
        col[i]=c;
    }
    cout << min_scaler_product(0,n-1) << endl;
    return 0;
}
