#include<iostream>
#include<vector>
using namespace std ;
typedef long long ll ;
typedef vector < vector < ll > > matrix ;
ll k,mod;
matrix mul(matrix A,matrix B)
{
    matrix C(k+1,vector<ll>(k+1));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            C[i][j]=0;
            for(int r=1;r<=k;r++)
            {
                C[i][j]=(C[i][j]+A[i][r]*B[r][j])%mod;
            }
        }
    }
    return C;
}
matrix power(matrix T,ll n)
{
    if(n==1){return T;}
    if(n%2){return mul(T,power(T,n-1));}
    matrix x = power(T,n/2);
    return mul(x,x);
}
ll fib(ll n,vector < ll > &a,vector < ll > &F)
{
   ll temp=k;
   if(n==1){return F[n]%mod;}
   matrix T (k+1,vector<ll>(k+1));
   for(int i=1;i<=k;i++)
   {
       for(int j=1;j<=k;j++)
       {
            if(j<=temp){T[i][j]=a[j];}
            else{T[i][j]=0;}
       }
       temp--;
   }
   T = power(T,n-2);
   ll res=0;
   for(int i=1;i<=k;i++)
   {
       res+=T[1][i]*F[i];
   }
   return res%mod;
}
int main()
{
    ll n ;
    while(cin >> k >> n >> mod )
    {
        if(k==0 && n==0 && mod==0){return 0;}
        vector < ll > a(k+1),F(k+1);
    for(int i=k;i>0;i--){ll x ; cin >> x ; a[i]=x;}
    for(int i=k;i>0;i--){ll x ; cin >> x ; F[i]=x;}
    cout << fib(n,a,F) << endl;
    }
    return 0;
}
