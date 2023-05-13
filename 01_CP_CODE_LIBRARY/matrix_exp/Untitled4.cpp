#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std ;
typedef long long ll ;
const ll k = 6 ;
vector < ll > F,G;
ll a1,a2,b1,b2,c1,c2,mod,q;
typedef vector < vector < ll > > matrix ;
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
void fib(ll n)
{
    matrix T (k+1,vector<ll>(k+1));
    T[0][0]=a1;T[0][1]=0;T[0][2]=0;T[0][3]=0;T[0][4]=0;T[0][5]=0;
    T[1][0]=b1;T[1][1]=a1;T[1][2]=0;T[1][3]=0;T[1][4]=0;T[1][5]=0;
    T[2][0]=0;T[2][1]=b1;T[2][2]=a1;T[2][3]=c1;T[2][4]=0;T[2][5]=0;
    T[3][0]=0;T[3][1]=0;T[3][2]=0;T[3][3]=a2;T[3][4]=0;T[3][5]=0;
    T[4][0]=0;T[4][1]=0;T[4][2]=0;T[4][3]=b2;T[4][4]=a2;T[4][5]=0;
    T[5][0]=c2;T[5][1]=0;T[5][2]=0;T[5][3]=0;T[5][4]=b2;T[5][5]=a2;
    T = power(T,n);
    ll ans=0;
    rep(i,k)
    {
        if(i<=2)
        {ans = (ans + T[0][i]*F[i%3])%mod;}
        else{ans = (ans + T[0][i]*G[i%3])%mod;}
    }
    cout << "f - > " << ans << " " ;
    ans=0;
    rep(i,k)
    {
        if(i<=2)
        {ans = (ans + T[3][i]*F[i%3])%mod;}
        else{ans = (ans + T[3][i]*G[i%3])%mod;}
    }
    cout << "g - > " << ans << " " ;
}
int main()
{
     ll x ;

     cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 ;
     cin >> x ; F[0]=x;
     cin >> x ; F[1]=x;
     cin >> x ; F[2]=x;
     cin >> x ; G[0]=x;
     cin >> x ; G[1]=x;
     cin >> x ; G[2]=x;
     cin >> mod ;
     cin >>  q ;
     rep(i,q)
     {
         ll n ;
         cin >> n ;
        fib(n);
     }
    return 0;
}
