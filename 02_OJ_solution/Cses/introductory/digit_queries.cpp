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
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10;
ll arr[50];
int main()
{
   arr[1]=1;
   for(int i=2;i<20;i++)
   {
       arr[i]=arr[i-1]*10 ;
   }
   ll q ;
   cin >> q ;
   while(q--)
   {
       ll k,ten=10;
       cin >> k ;
       ll sum=0,p=1,s=9;
       while(sum+(s*p)<=k)
       {
           sum+=(s*p);
           s = s*ten ;
           p++;
       }
       k = k-sum ;
       ll r = k/p ;
       ll rem = k%p ;
       ll d = arr[p]+(r-1);
       if(rem==0)
       {
           cout << d%ten << endl;
       }
       else
       {
           d++;
           vector < int > dig ;
           while(d>9)
           {
               dig.push_back(d%ten);
               d = d/ten ;
           }
           dig.push_back(d);
           reverse(dig.begin(),dig.end());
           cout << dig[rem-1] << endl;
       }
   }
   return 0 ;
}
