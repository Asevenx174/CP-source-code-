#include<iostream>
#include<stdio.h>
#include<vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std ;
typedef long long ll ;
typedef vector < vector < ll > > matrix ;
ll m,k;
vector < ll > a (16+1),f(16+1);
matrix mul(matrix A,matrix B)
{
    matrix   C (k+1,vector < ll > (k+1)) ;
    rep(i,k)
    {
        rep(j,k)
        {    C[i][j]=0;
            rep(r,k)
            {
                C[i][j]=(C[i][j]+A[i][r]*B[r][j])%m;
            }
        }
    }
    return C ;
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
    int temp=2;
    if(n==1){return f[n]%m;}
    matrix T (k+1,vector<ll>(k+1));
    rep(i,k)
    {
        rep(j,k)
        {
            if(i==k){T[i][j]=a[k-j+1];}
            else if (temp==j)
            {
                T[i][j]=1;
            }
            else{T[i][j]=0;}
            ////cout << T[i][j] << " ";
        }
        ///cout << endl;
        temp++;
    }
    T = power(T,n-1);
    ll ans=0;
    rep(i,k)
    {
        ans=(ans + T[1][i]*f[i])%m;
    }
    return ans;
}
int main()
{
    ll n ;
    while(cin >> k >> n >> m )
    {
      if(k==0 && n==0 && m==0){return 0;}
      rep(i,k)
    {
        ll x ; cin >> x ; a[i]=x ;
    }
    for(int i=1;i<=k;i++)
    {
        ll x ; cin >> x ;
        f[i]=x;
    }
    cout << fib(n) << endl;
    }
    return 0;
}
