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
ll arr[25],n,sum=0,ans=imax;
int dp[22][1<<21];
int sett(int x,int pos)
{
    x = x | (1<< (pos-1)) ;
    return x ;
}
bool check(int x,int pos)
{
    if(x&(1<<(pos-1))){return true;}else{return false;}
}
void calco(int idx,int mask)
{
    if(dp[idx][mask]!=-1){return ;}
    if(idx>n)
    {
        ll i = 0 , s=0 ;
        while( (1<<i)<=mask )
        {
            if(check(mask,i+1))
            {
                s+=arr[i+1];
            }
            i++;
        }
        dp[idx][mask]=1 ;
        if(sum==s){return ;}
        ans = min(ans,abs(2LL*s-sum));
        return ;
    }
    calco(idx+1,mask);
    calco(idx+1,sett(mask,idx));
    dp[idx][mask]=1;
}
int main()
{
   ms(dp,-1);
   cin >> n ;
   for(int i=1;i<=n;i++)
   {
       ll x ;
       cin >> x ;
       sum+=x ;
       arr[i]=x ;
   }
   calco(1,0);
   cout << ans << endl;
   return 0 ;
}
