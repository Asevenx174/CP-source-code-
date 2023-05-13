#include<bits/stdc++.h>
using namespace std ;
int N ;
int calco(int n,int k)
{
   if(n==1){return 1 ;}
   else { int x = (calco(n-1,k)+k-1)%n+1 ;
   cout << n << " " << k << " " << x << endl;
    return x ; }
}
int main()
{
    int n,k;
    cin >> n >> k ;
    cout << calco(n,k) << endl;
    return 0 ;
}
