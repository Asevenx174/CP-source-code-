#include<bits\stdc++.h>
using namespace std ;
bool status [1000000];
void seive(int n)
{
    int x = sqrt(n);
    for(int i=4; i<=n; i=i+2)
    {
        status[i] = 1 ;
    }
    for(int i=3; i<=x; i++)
    {
        if(status[i]==0)
        {
            for(int j=i*2; j<=n; j=j+i)
            {
                status[j]=1;
            }
        }
    }
    status[1]=1;
}
int main()
{
    int n ;
    cin >> n ;
    seive(n) ;
    for(int i=1; i<=n; i++)
    {
        if(status[i]==0)
        {
            cout << i << " " ;
        }
    }
    return 0;
}
