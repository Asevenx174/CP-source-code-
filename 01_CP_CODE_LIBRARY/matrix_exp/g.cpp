#include<iostream>
#include<vector>
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std ;
typedef long long ll ;
typedef vector < vector < ll > > matrix ;
const ll mod = 10007,k=4;
ll a,b,c,n;
matrix mul(matrix A,matrix B)
{
    matrix   C (k+1,vector < ll > (k+1)) ;
    rep(i,k)
    {
        rep(j,k)
        {    C[i][j]=0;
            rep(r,k)
            {
                C[i][j]=(C[i][j]+A[i][r]*B[r][j])%mod;
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
ll fib()
{
    if(n<=2){return 0;}
    vector < ll > F(k+1);
    matrix T (k+1,vector<ll>(k+1));
    F[1]=0;F[2]=0;F[3]=0;F[4]=c;
    T[1][1]=0;T[1][2]=1;T[1][3]=0;T[1][4]=0;
    T[2][1]=0;T[2][2]=0;T[2][3]=1;T[2][4]=0;
    T[3][1]=b;T[3][2]=0;T[3][3]=a;T[3][4]=1;
    T[4][1]=0;T[4][2]=0;T[4][3]=0;T[4][4]=1;
    T = power(T,n);
    ll ans=0;
    rep(i,k)
    {
        ans=(ans + T[1][i]*F[i])%mod;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t ;
    rep(i,t)
    {
    cin >> n >> a >> b >> c ;
    cout << "Case " << i << ": " << fib() << endl;
    }
    return 0;
}
