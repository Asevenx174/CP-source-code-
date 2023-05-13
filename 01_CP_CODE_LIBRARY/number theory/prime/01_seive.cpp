#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

using namespace std ;
typedef long long ll ;
const int imin = 1e9+100;
const ll maxx = 1010,mod=1e9+7,imax=1e18+10,qq=1;

vector < int > prime ;
ll arr[maxx+10];
void seive(ll lim)
{
    for(int i=4;i<=lim;i+=2){arr[i]=1;}
    for(int i=3;(ll)i*i<=lim;i+=2)
    {
        if(!arr[i])
        {
            for(int j=i+i;j<=lim;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    for(int i=2;i<=lim;i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
        }
    }
}
int main()
{
   seive(maxx);

   return 0 ;
}
