#include<bits\stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
void same(int n,int k,int arr[])
{
    int res=0,s=0,ans;
    if(k>n){cout << "not psb" << endl;return ;}
    sort(arr,arr+n);
    rep(i,n)
    {
        if(i<k-1){s+=arr[k-1]-arr[i];}
        if(i+1==k){res=s;ans=s;}
        if(i>=k)
        {
            res=res-(arr[i-1]-arr[i-k])+(arr[i]-arr[i-1])*(k-1) ;
            ans=min(ans,res);
        }
    }
    cout << ans << endl;
}
int main()
{
    int n,arr[100],k;
    cin >> n >> k ;
    rep(i,n)
    {
        cin >> arr[i] ;
    }
    same(n,k,arr);
    return 0 ;
}
