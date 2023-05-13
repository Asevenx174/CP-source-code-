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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],com[maxx+10],br[maxx+10],f[maxx+10],n,s,pre[maxx+10] ; 
ll p,q ; 
bool valid(ll l,ll r)
{
   if(l==r)
   {
      if( (com[l]+s) < 0 ){ return false ; }
   }
   else
   {
      ll cost = 0 ; 
      if(com[l]<0){cost-=com[l];}
      cost+=(br[r]-br[l]) ; 
      if(cost>s){return false ;}
   }
   return true ; 
}
ll calco(ll idx)
{
   ll l=idx,r=n,ans=0,temp=idx ; 
   while(l<=r)
   {
      ll mid = (l+r)/2LL ;
      if(valid(idx,mid))
      {
         ans = pre[mid]-pre[idx-1] ; 
         temp = mid ; 
         l = mid+1 ; 
      }
      else
      {
         r = mid-1 ; 
      }
   }
   p = idx ; 
   q = temp ;  
   return ans ; 
}
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll idx=0 ;
      cin >> n >> s ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for(int i=1;i<=n;i++)
      {
         if(ar[i]>=0)
         {
            ll sum = ar[i],add=1 ; 
            while(i+1<=n && sum+ar[i+1]>=0)
            {
               sum+=ar[i+1] ; 
               i++ ; 
               add++ ; 
            }
            com[++idx] = sum ; 
            f[idx] =  add ; 
         }
         else
         { 
            com[++idx] = ar[i] ; 
            f[idx] = 1 ;  
         }
      }
      n = idx ; 
      ll sum = 0 , ps = 0 ; 
      for(int i=1;i<=n;i++)
      {
          if(com[i]<0 && com[i-1]>=0)
          {
             ll add = com[i]+com[i-1] ; 
             sum-=add ; 
          }
          else if(com[i]<0)
          {
             sum-=com[i] ; 
          }
          br[i] = sum ;  
          ps+=f[i] ; 
          pre[i] = ps ; 
      }
      ll ans = 0 ,l=0,r=0 ; 
      for(int i=1;i<=n;i++)
      {
         ll temp = calco(i) ; 
         if(temp>ans)
         {
            l = p ; 
            r = q ; 
            ans = temp ; 
         }
      }
      if(l==0)
      {
         cout << "-1" << endl ;
      }
      else
      {
         ll a = pre[l-1] ; 
         l = a+1 ; 
         r = pre[r] ; 
         cout << l << " " << r << endl ;
      }
   }
   return 0 ;
}