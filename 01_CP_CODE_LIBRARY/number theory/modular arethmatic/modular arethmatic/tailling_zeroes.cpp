#include<bits\stdc++.h>
using namespace std ;
///i was asked to find number of 0 in !n
///!5=2*2*2*3*5 here ans is 1 because product of 2*5 count 1 zero
///num of 2 >= number of 5 ,so we need count num of 5
/// 25/5=5 but 28/5=6 ?? 28/5+28/25 = 6
int find_trailing_zeros(int n)
{
    int co=0;
    for(int i=5;(n/i)>=1;i*=5)
    {
        co+=floor(n/i);
    }
    return co;
}
int main()
{
    int n ;
    cin >> n ;
    int x = find_trailing_zeros(n);
    cout << x << endl;
    return 0 ;
}
