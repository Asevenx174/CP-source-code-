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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,q,ans=0,pr[maxx+5][40],val[maxx+10],best=0 ; 
ll getxor(ll l,ll r)
{
   ll ans = 0 ; 
   for (ll i = 0; i < 35 ; ++i)
   {
      ll temp = qq << i ; 
      ll f = pr[r][i]-pr[l-1][i] ; 
      f = f%2LL ; 
      if(f)
      {
         ans+=temp ; 
      }
   }
   return ans ; 
}
ll getsum(ll l,ll r)
{
   ll add = val[r]-val[l-1] ; 
   return add ;  
}
ll calco(ll l,ll r)
{
   ll k = l ; 
   ll ans = 0 ; 
   while(l<=r)
   {
      ll m = (l+r)/2LL ; 
      ll temp = getsum(k,m)-getxor(k,m) ;
      if(temp<best)
      {
         l = m+1 ; 
      }
      else if(temp==best)
      {
         ans = m ; 
         r = m-1 ; 
      }
      else
      {
         r = m-1 ; 
      }
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      std::vector < int > f(50,0) ;
      cin >> n >> q ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      ll xo=0,add=0 ; 
      ll l,r ;
      cin >> l >> r ; 
      for(int i=l;i<=r;i++)
      {
         ll x = ar[i] ; 
         add+=x ; 
         ll idx = 0 ;
         while(1)
         {
            ll temp = qq << idx ; 
            if(temp>x){break;}
            if( (temp&x)!=zz )
            {
               //cout << i << " " << idx << endl ; 
               f[idx]++ ; 
            }
            idx++ ; 
         }
         for (int j = 0; j < 35 ; ++j)
         {
            pr[i][j] = f[j] ; 
         }
         val[i] = add ; 
      }
      best = getsum(l,r)-getxor(l,r) ; 
      //cout << getsum(l,r) << " " << getxor(l,r) << endl ;
      ll k = mod ; 
      ll p=l,q=r ; 
      for(int i=l;i<=r;i++)
      {
         ll temp = getsum(i,r)-getxor(i,r) ;
         if(temp<best){break;}
         ll a = i ; 
         ll b = calco(i,r) ;  
         ll len = b-a+1 ; 
         if(len<k)
         {
            k = len ; 
            p = a ; 
            q = b ; 
         }
      }
      cout << p << " " << q << endl ; 
   }
   return 0 ;
}