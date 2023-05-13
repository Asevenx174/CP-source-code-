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
ll ar[maxx+10],x,y,n ; 
vector < pii > pq ; 
void calco(ll l,ll r)
{
   pq.clear() ; 
   ll lastx = l-1 ; 
   ll lasty = l-1 ; 
   queue < ll > xx,yy ; 
   while(l<=r)
   {
      ll temp = ar[l],a,b ; 
      if(temp==x)
      {
         xx.push(l) ; 
      }
      else if(temp==y)
      {
         yy.push(l) ; 
      }
      if(xx.empty() || yy.empty()){l++;continue;}
      ll f = 1 ; 
      if(xx.size()==1 && yy.size()==1 &&  yy.front()>xx.front()){f=0;}
      if(xx.size()==1 && f==1)
      {
         b = l-1 ; 
         a = lastx+1 ; 
         while(!yy.empty())
         {
            lasty = yy.front() ; yy.pop() ; 
         } 
      }
      else
      {
         b = l-1 ; 
         a = lasty+1 ; 
         while(!xx.empty())
         {
            lastx = xx.front() ; xx.pop() ; 
         }
      }
      l++ ;
      pq.push_back({a,b}) ; 
   }
   ll a,b=r ; 
   if(!xx.empty())
   {
      a = lasty+1 ; 
   }
   else if(!yy.empty())
   {
      a = lastx+1 ;
   }
   else{return ;}
   pq.push_back({a,b}) ;
}
ll gen(ll l,ll r)
{
   ll len = r-l+1 ; 
   ll ans = len*(len+1) ; 
   ans = ans/2LL ; 
   return ans ; 
}
int main()
{
   debugMode();
   std::vector < ll > br,s ;
   cin >> n >> x >> y  ;
   br.push_back(0) ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      if(ar[i+1]>x || ar[i+1]<y){br.push_back(i+1);}
      if(ar[i+1]==x){s.push_back(i+1);}
   }
   if(x==y)
   {
      ll p = 0 , ans = 0  ; 
      for(auto temp : s )
      {
         ll l = temp-p ; 
         ll r = n-temp+1 ; 
         ans+=(l*r) ; 
         p = temp ;  
      }
      cout << ans << endl ; 
      return 0 ; 
   }
   br.push_back(n+1) ; 
   ll ans = 0 ; 
   for(int i=1;i<br.size();i++)
   {
      ll l = br[i-1]+1 ; 
      ll r = br[i]-1 ; 
      calco(l,r) ; 
      if(pq.empty()){continue;}
      auto it = pq.begin() ; 
      pii p = *it,q ;
      ll sum = 0 ;  
      sum+=gen(p.ff,p.ss) ;
      q = p ;
      for(int i=1;i<pq.size();i++)
      {
         p = pq[i] ; 
         sum+=gen(p.ff,p.ss) ;
         if(q.ss>=p.ff)
         {
            sum-=gen(p.ff,q.ss);
         }
         q = p ;
      }
      ans+=(gen(l,r)-sum) ; 
   }
   cout << ans << endl ;
   return 0 ;
}