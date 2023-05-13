#include<iostream>
#include<vector>
#include<stdio.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
const int k = 2 ;
typedef unsigned long long ll ;
ll s,m;
typedef vector < vector < ll > > matrix ;
matrix mul(matrix A,matrix B)
{
    matrix C(k+1,vector<ll>(k+1));
    rep(i,k)
    {
        rep(j,k)
        {    C[i][j]=0;
            rep(r,k)
            {
                C[i][j]+=A[i][r]*B[r][j];
            }
        }
    }
  return C ;
}
matrix power(matrix A,ll p)
   {
    if(p==1){return A;}
    if(p%2)
    {
        return mul(A,power(A,p-1));
    }
    matrix X = power(A,p/2) ;
    return mul(X,X);
}
ll fib(ll p)
{
    matrix T (k+1,vector<ll>(k+1));
    vector < ll >  F (k+1);
    F[0]=s;
    F[1]=2;
    if(p<=1){return F[!p];}
    T[0][0]=s;T[0][1]=-m;
    T[1][0]=1;T[1][1]=0;
    T = power(T,p-1);
    ll ans=0;
    rep(i,k)
    {
       ans +=T[0][i]*F[i];
    }
    return ans ;
}
int main()
{
    int test ; cin >> test ;
    ll p ;
    rep(i,test)
    {cin >> s >> m >> p ;
    cout << "Case " << i+1 << ": " << fib(p) << endl;}
    return 0;
}
