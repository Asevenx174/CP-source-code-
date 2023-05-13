#include<iostream>
#include<math.h>
#define MAX 5000000
using namespace std ;
int arr[MAX];
/// like idx=32 ,pos=3
/// mane 4th bit ta change krte hbe
/// 1 er bin 00001 ek 3 ghor bame nei 1 << 3 ,so now 00001000 , ie value sathe 32 er
/// binary or krlei idx er index er pos th bit 1 hoy a jabe
int setbit(int idx,int pos) /// idx index er pos th bit k 1 krbe
{
    int n = idx | ( 1 << pos ) ; /// idx value matter krtese na
    return n ;
}
bool checkbit(int idx,int pos)
{
    int n = idx & ( 1 << pos ) ; ///1<< pos value matter krtese na
    return n ;
}
void seive()
{
    int x = sqrt(MAX);
    arr[0]=setbit(arr[0],0);/// arr[0]->     ......01010011
    arr[0]=setbit(arr[0],1);
    for(int i=4;i<=MAX;i+=2)
    {
        arr[i/32]=setbit(arr[i/32],i%32);
    }
    for(int i=3;i<=x;i+=2)
    {
        if(!checkbit(arr[i/32],i%32))
        {
            for(int j=i+i;j<=MAX;j=j+i)
            {
                arr[j/32]=setbit(arr[j/32],j%32);
            }
        }
    }
}
int main()
{
    seive();
    for(int i=0;i<=MAX;i++)
    {
        if(!checkbit(arr[i/32],i%32))
        {
            cout << i << endl;
        }
    }
    return 0;
}
