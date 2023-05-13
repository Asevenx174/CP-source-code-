#include<iostream>
#include<vector>
/// F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
using namespace std ;
const int k = 3 ; /// 3 terms are to be known
void mul(int A[k][k],int B[k][k])
{
    int C[k][k];
    for(int i=0;i<k;i++){
       for(int j=0;j<k;j++){
        C[i][j]=0;
        for(int r=0;r<k;r++){C[i][j]+=A[i][r]*B[r][j];}}}
    for(int i=0;i<k;i++)
        {for(int j=0;j<k;j++)
           {
               A[i][j]=C[i][j];
           }
        }
}
int power(int F[k][k],int n)
{
    if(n==1){return F[0][0]+F[0][1];}
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
    power(F,n/2);
    mul(F,F);
    if(n%2==1)
    {
        mul(F,M);
    }
    return F[0][0]+F[0][1];
}
int fib(int n)
{
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
    return power(F,n-2);
}
int main()
{
    int n ;
    cin >> n ;
    cout << fib(n) << endl;
    return 0;
}
