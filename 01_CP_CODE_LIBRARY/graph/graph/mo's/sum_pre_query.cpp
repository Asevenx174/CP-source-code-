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
const ll maxx = 1e5+10,mod=1e9+7,imax=1e18+10,k=3;/// k = 320 = root of 1e5
ll ans [maxx],arr[maxx],sum;
struct query
{
    int l,r,id ;
}
v[maxx];

bool com(query &a,query &b)
{
    ll x = a.l/k , y = b.l/k ;
    if(x==y)///same block
    {
        return a.r<b.r ; /// right value , ascending
    }
    else
    {
        return x<y ; /// block num , ascending
    }
}
void add(int idx){sum+=arr[idx];}
void dlt(int idx){sum-=arr[idx];}
int main()
{
   ll n,q ;
   cin >> n >> q ;
   for(int i=0;i<n;i++)
   {
       cin >> arr[i] ;
   }
   for(int i=0;i<q;i++)
   {
       cin >> v[i].l >> v[i].r ;
       v[i].id = i ;
   }
   sort(v,v+q,com);
   int l=0,r=-1;
   for(int i=0;i<q;i++)
   {
       int x = v[i].l , y = v[i].r , who = v[i].id ;
       while(r<y){r++;add(r);}
       while(y<r){dlt(r);r--;}
       while(l<x){dlt(l);l++;}
       while(x<l){l--;add(l);}
       ans[who]=sum ;
   }
   for(int i=0;i<q;i++)
   {
       if(i!=0){cout << " " ;}
       cout << ans[i] ;
   }
   cout << endl;
   return 0 ;
}
