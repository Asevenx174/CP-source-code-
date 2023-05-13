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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx] ; 
int main()
{
   debugMode();
   ll n,x,y ;
   cin >> n >> y >> x ; 
   std::vector< int > br ;
   br.push_back(0) ; 
   ll same = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      ll p ;
      cin >> p ; 
      ar[i+1] = p ; 
      if(p>y || p<x){br.push_back(i+1);}
      if(p==x){same++;}
   }
   ll ans = 0 ; 
   if(x==y){ans+=same;}
   br.push_back(n+1) ; 
   for(int i=1;i<br.size();i++)
   {
      ll l = br[i-1]+1 ; 
      ll r = br[i]-1 ; 
      if(l>=r){continue;}
      queue < int > p,q ;
      if(x==y)
      {
         ll pre = l-1 ; 
         for(int i=l;i<=r;i++)
         {
            if(ar[i]==x)
            {
               ll c = i-pre ; 
               ll d = r-i;
               ans+=(c*d) ; 
               pre = i ; 
            }
         }
      }  
      else
      {
         ll pre = l-1 ; 
         for(int i=l;i<=r;i++)
         {
            ll temp = ar[i] ; 
            if(temp==x)
            {
               p.push(i) ;
            }
            else if(temp==y)
            {
               q.push(i) ; 
            }
            while(!p.empty() && !q.empty())
            {
               ll a = p.front();
               ll b = q.front();
               ll c = min(a,b)-pre ; 
               ll d = (r-l+1)-max(a,b)+1 ;
               ans+=(c*d) ; 
               if(a<b)
               {
                  pre = a ; 
                  p.pop();
               }
               else
               {
                  pre = b ; 
                  q.pop();
               }
            }
         }
      }
   }
   cout << ans << endl ;
   return 0 ;
}