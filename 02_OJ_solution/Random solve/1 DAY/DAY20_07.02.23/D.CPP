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
ll pr[maxx+10],n,qr[maxx+10],pos[maxx+10],lr[maxx+10],rr[maxx+10],l,r,fre=0 ; 
ll lx,rx,res=0 ;
void range(ll m)
{ 
   lx = 0 ; 
   rx = 0 ; 
   l = lr[m] ; 
   r = rr[m] ; 
   cout << m << " " << l << " " << r << endl ;
   ll add = 2*m-(r-l+qq) ; 
   ll idx = qr[m] ;
   if(l<=idx && idx<=r){return ;}
   fre = 0 ; 
   if(idx<l)
   {
     ll a = 0 ;
     lx+=(l-idx-qq) ; 
     rx+=(n-r) ;
     do
     {
       ll b = add-a ; 
       res+=(b+qq) ; 
       a++ ; 
     }
     while (a<=lx); 
   }
   else
   {
     lx+=(l-1) ; 
     rx+=(idx-r-qq) ; 

     ll b = 0 ;
     lx+=(l-idx-qq) ; 
     rx+=(n-r) ;
     do
     {
       ll a = add-b ; 
       res+=(a+qq) ; 
       b++ ; 
     }
     while (b<=rx);
   }
}

void solve()
{
   cin >> n ; 
   for (ll i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      pr[i+1] = x ; 
      qr[x] = i+qq ; 
   }
   ll a = mod ; 
   ll b = 0  ; 
   for(ll i=1;i<=n;i++)
   {
      pos[i] = qr[i-qq] ; 
      a = min(a,pos[i]) ; 
      b = max(b,pos[i]) ; 
      lr[i] = a ; 
      rr[i] = b ; 
   }
   res = 0 ; 
   for (int i = 0; i< n ; ++i)
   {
      range(i+1) ; 
   }
   cout << res << endl ;
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