// n এর position-তম বিটকে 1 সেট করার জন্য
int setBit( int n, int position )
{
    n = n | ( 1 << position );
    return n;
}
// n এর position-তম বিট চেক করার জন্য
bool checkBit( int n, int position )
{
    return n & ( 1 << position );
}
#include<stdio.h>
#include<stdbool.h>
int prime[100/32],n=100;
void main() // n পর্যন্ত প্রাইম বের করব
{
    int x = sqrt( n );
    prime[0] = setBit( prime[0], 0 );
    prime[0] = setBit( prime[0], 1 );
    for( int i = 4; i <= n; i += 2 )
    {
        prime[i/32] = setBit( prime[i/32], i%32 );
    }
    for( int i = 3; i <= x; i += 2 )
    {
        if( !checkBit( prime[i/32], i%32 )
    {
        for( int j = i+i; j <= n; j += i )
            {
                prime[j/32] = setBit( prime[j/32], j%32 );
            }
        }
    }
    return 0;
}
