#include<iostream>
#include<vector>
#include<stdio.h>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std ;
typedef long long ll ;
const int k = 2 ;
typedef vector< vector < ll > > matrix ;
ll mod=1;
matrix mul(matrix A,matrix B)
{
    matrix C (k+1,vector<ll>(k+1)) ;
    rep(i,k)
        rep(j,k)
         {C[i][j]=0;
          rep(r,k)
             {C[i][j]+=A[i][r]*B[r][j];}}
    return C ;
}
matrix power(matrix T,ll n)
{
    if(n==1){return T;}
    if(n%2==1)
    {
        return mul(T,power(T,n-1));
    }
    matrix x = power(T,n/2);
    return mul(x,x);
}
ll fib(ll n)
{
    matrix T (k+1,vector<ll>(k+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;
    vector < ll > F1(k+1);
    F1[1]=1;
    F1[2]=1;
    if(n==0){return 0;}
    if(n==1 || n==2){return F1[n];}
    T = power(T,n-1);
    ll res=0;
    rep(r,k)
        res+= T[1][r]*F1[r];
    return res;
}
int main()
{
    ll n ;
    cin >> n ;
    cout << fib(n) << endl;
    return 0;
}
