#include<bits/stdc++.h>
using namespace std ;
#define PI 3.14159265
int main()
{
    int test ;
    cin >> test ;
    while(test--)
    {
    int n ;
    cin >> n ;
    n = 2*n ;
    double param = (double)90/n;
    double ans = (double)2*sin (param*PI/180);
    ans = (double)1/ans ;
    printf("%.10f\n",ans);
    }
    return 0 ;
}
