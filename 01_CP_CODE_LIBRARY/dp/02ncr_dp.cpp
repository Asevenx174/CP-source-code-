#include<bits\stdc++.h>
int store[100][100];
using namespace std ;
int ncr(int n,int r)
{
    if(r==1)
    {
        return n ;
    }
    if(n==r)
    {
        return 1;
    }
    if(store[n][r]!=-1)
    {
        return store[n][r];
    }
    else
    {
        store[n][r]= ncr(n-1,r)+ncr(n-1,r-1);
        return store[n][r];
    }
}
int main()
{
    int n,r;
    cin >> n >> r ;
    memset(store,-1,sizeof(store));
    cout << ncr(n,r) << endl;
    return 0;
}
