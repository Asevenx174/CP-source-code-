#include<bits\stdc++.h>
using namespace std ;
int count_set_bits(int n)
{
    int ans = 0 ;
    while(n)
    {
        ans++;
        n=n&(n-1);
    }
    return ans ;
}
int main()
{
    int n  ;
    cin >> n ;
    cout << count_set_bits(n) << endl;
    ///cout << __builtin_popcount(12) << endl;
}
