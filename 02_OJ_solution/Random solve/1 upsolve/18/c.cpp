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
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      priority_queue < ll > p,q ; 
      ll n,ze=0 ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ;
         cin >> x ;
         if(x==0)
         {
            ze=1 ; 
            continue ; 
         }
         if(x>zz)
         {
            p.push(x) ; 
         }
         else
         {
            q.push(-x) ; 
         }
      }
      std::vector < ll > k ;
      ll temp = 5 ; 
      while(temp--)
      {
         if(!p.empty() && !q.empty())
         {
            ll a = p.top() ; 
            ll b = q.top() ; 
            if(a>b)
            {
               k.push_back(a) ; 
               p.pop() ; 
            }
            else
            {
               k.push_back(-b) ; 
               q.pop() ; 
            }
         }
         else if(!p.empty())
         {
            ll a = p.top() ; k.push_back(a) ; p.pop() ; 
         }
         else if(!q.empty())
         {
            ll b = q.top() ; k.push_back(-b) ; q.pop() ; 
         }
      }
      if(!p.empty())
      {
         k.push_back(p.top()) ; 
      }
      if(!q.empty())
      {
         k.push_back(-q.top()) ; 
      }


      ll mul = 1 ; 
      for(auto x : k)
      {
         if(k.size()>5LL){break;}
         mul = mul*x ; 
      }
      if(k.size()==5)
      {
         if(ze==qq && mul<zz)
         {
            mul = 0 ; 
         }
         cout << mul << endl ; continue ; 
      }
      else if(k.size()<5LL)
      {
         if(ze){mul=0;}
         cout << mul << endl ;
         continue ; 
      }

      ll ans = -1e18-10 ; 
      if(k.size()==6)
      {
         for (int i = 0; i < 6 ; ++i)
         {
            ll m = 1 ; 
            for (int j = 0; j < 6 ; ++j )
            {
                if(i==j){continue;}
                m = m*k[j] ; 
            }
            ans = max(ans,m) ; 
         }
      }
      else
      {
         for (int i = 0; i < 7 ; ++i)
         {
            for (int j = i+1 ; j < 7 ; ++j )
            {
               ll m = 1 ; 
               for (int p = 0; p < 7 ; ++p )
               {
                  if(p==i || p==j){continue;}
                  m = (ll)m*k[p] ; 
               }
               ans = max(m,ans) ; 
            }
         }
      }
      if(ze==1 && ans<zz)
      {
         ans = 0 ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}