// n এর position-তম বিটকে 1 সেট করার জন্য
// here n means index like prime[0] and position means bit's position
// setbit func kaj hbe etto tomo index er etto tomo bit er value 1 boshano
int setBit( int n, int position )
{
    n =  n | ( 1 << position ); // n n0n zero value so return krbe 1 always
    return n;
}
// n এর position-তম বিট চেক করার জন্য
bool checkBit( int n, int position )
{
    return n & ( 1 << position );
    // here 1<<p always non 0 value hbe so return value 0/1 nirvor krbe n er upr
    // jehetu agei non prime gula k set func dia alada krsi so prb hbe na
}

#include<iostream>
#include<cmath>
using namespace std ;

int prime[100/32];// protiti array 32 ta bit flag hishebe use krbo
// ager tulonae 32 gun kom jaega lagbe
int primeGenerator( int n ) // n পর্যন্ত প্রাইম বের করব
{
    int x = sqrt( n ); // seive era
    prime[0] = setBit( prime[0], 0 );
    prime[0] = setBit( prime[0], 1 );
    for( int i = 4; i <= n; i += 2 )
        prime[i/32] = setBit( prime[i/32], i%32 );// non prime value 1 set krtesi
    for( int i = 3; i <= x; i += 2 )
    {
        if( !checkBit( prime[i/32], i%32) ) // prime 0 return krbe r !0 mane 1
        {
            for( int j = i+i; j <= n; j += i )
                prime[j/32] = setBit( prime[j/32], j%32 ); //gunitok non prime value 1 set krtesi
        }
    }
    for(int i=3; i<=n; i+=2)
    {
        if(!checkBit( prime[i/32], i%32))
        {
            cout << i << '\t' ;
        }
    }
    return 0;
}
int main()
{
    int n=100;// 1 theke 100 mdde prime gula ber krbo
    primeGenerator(n);// prime gula print kre dibe
}
