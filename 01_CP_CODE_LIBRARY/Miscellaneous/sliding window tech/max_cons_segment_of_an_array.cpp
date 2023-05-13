#include<bits\stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int max_sum(int n,int k,int arr[])
{
    int maxx=0,s=0,last=0;
    if(k>n){cout << "invalid" << endl;return 0;}
    rep(i,n)
    {
        if(i<k){s+=arr[i];}
        if(i+1==k){maxx=s;}
        if(i>=k)
        {
            s=s+arr[i]-arr[i-k];
            maxx=max(maxx,s);
        }
    }
    return maxx ;
}
int main()
{
    int n ,arr[100] , k;
    cin >> n >> k ;
    rep(i,n)
    {
       int x ;
       cin >>  x ; arr[i] = x ;
    }
    cout << max_sum(n,k,arr) << endl;
    return 0;
}
