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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],n,k,x ; 
ll getmax()
{
   ll pre=0,sub=0,ans=0 ; 
   for(int i=1;i<=n;i++)
   {
      pre+=br[i] ; 
      ans = max(ans,pre-sub) ; 
      sub = min(sub,pre) ; 
   }
   return ans ;
}
ll sett(ll l,ll r,ll val)
{
   //cout << l << " " << r << " " << val << endl ;
   /*if(si)
   {
      val = -val ; 
   }*/
   for(int i=1;i<=n;i++)
   {
      if(l<i && i<r)
      {
         br[i] = ar[i]-val ; 
      }
      else
      {
         br[i] = ar[i]+val ;
      }
   }
   return getmax() ; 
}
void solve()
{
   cin >> n >> k >> x ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }

   if(x<0)
   {
      //k = n-k ;  
   }
   //ll si = 0 ; 
   //if(x<zz){si=qq;}
   //x = max(x,-x) ; 
   //cout << k << " " << x << endl ;
   ll ans = 0 ; 
   for(int i=0;i<=k;i++)
   {
      ll temp = sett(i,n-(k-i-1),x) ; 
      ans = max(ans,temp) ; 
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}