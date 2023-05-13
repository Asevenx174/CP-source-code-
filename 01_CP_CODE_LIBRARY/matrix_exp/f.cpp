#include<iostream>
#include<vector>
#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
typedef long long ll ;
ll a,b,mod;
const int k = 2;
typedef vector < vector < ll > > matrix ;
matrix mul(matrix A,matrix B)
{
    matrix C(k+1,vector<ll>(k+1));
     rep(i,k) rep(j,k) {
      C[i][j]=0;
      rep(r,k)
      {
         C[i][j]=(C[i][j]+A[i][r]*B[r][j])%mod;
      }}
    return C;
}
matrix power(matrix A,ll n)
{
     if(n==1){return A;}
     if(n%2){return mul(A,power(A,n-1));}
     matrix x = power(A,n/2);
     return mul(x,x);
}
ll fib(ll n)
{
    matrix T (k+1,vector<ll>(k+1));
    T[0][0]=0;T[0][1]=1;T[1][0]=1;T[1][1]=1;
    vector < ll > F1(k+1);
    F1[0]=a;
    F1[1]=b;
    if(n==0 || n==1){return F1[n]%mod;}
    T = power(T,n);
    ll res=0;
    rep(i,k)
         res+=T[0][i]*F1[i];
    return res%mod;
}
int main()
{
    ll n,m,t;
    cin >> t ;
    for(int i=1;i<=t;i++)
    {
    cin >> a >> b >> n >> m ;
    mod=1;
    while(m--){mod*=10;}
    cout << "Case " << i << ": " << fib(n) << endl;
    }
    return 0;
}
