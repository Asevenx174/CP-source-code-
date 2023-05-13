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
const ll maxx = 1e5+10,mod=1e10+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
queue < int > p,q ; 
std::vector < int > u,v ;
void calco()
{
   while(!q.empty()){q.pop();}
   while(!p.empty()){p.pop();}

   int temp = min(5,(int)u.size()) ; 
   for (int i = 0; i < temp ; ++i)
   {
      p.push(u[i]) ; 
   }
   temp = min(5,(int)v.size()) ; 
   for (int i = 0; i < temp ; ++i)
   {
      q.push(v[i]) ; 
   }
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      u.clear() ; 
      v.clear() ; 
      ll ze = 0,ex=1 ; 
      cin >> n ;
      vector < int > pq ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
         pq.push_back(ar[i+1]) ; 
         if(i<5)
         {
            ex = ex*ar[i+1] ; 
         }
         if(ar[i+1]==0){ze=1;continue;}
         if(ar[i+1]>0)
         {
            u.push_back(ar[i+1]) ; 
         }
         else
         {
            v.push_back(-ar[i+1]) ;
         }
      }
      sort(pq.begin(),pq.end(),greater<int>()) ; 
      ll co = 1 ; 
      for (int i = 0; i < 5 ; ++i)
      {
         co = co*pq[i] ; 
      }
      sort(u.begin(),u.end(),greater<int>()) ;
      sort(v.begin(),v.end(),greater<int>()) ;
      calco() ;  
      ll ans = -1e18-10 ; 
      if(p.size()==5)
      {
         ll m = 1 ; 
         while(!p.empty())
         {
            ll x = p.front() ; p.pop() ; 
            m = m*x ; 
         }
         ans = max(ans,m) ; 
      }
      calco() ; 
      if(p.size()>2 && q.size()>1)
      {
         ll temp = 3 ; 
         ll m = 1 ; 
         while(!p.empty() && temp>0)
         {
            ll x = p.front() ; p.pop() ; 
            m = m*x ; 
            temp-- ; 
         }
         temp = 2 ;  
         while(!q.empty() && temp>0)
         {
            ll x = q.front() ; q.pop() ; 
            m = m*x ; 
            temp-- ; 
         }
         ans = max(ans,m) ; 
      }

      calco() ; 
      if(p.size()>0 && q.size()>3)
      {
         ll temp = 1 ; 
         ll m = 1 ; 
         while(!p.empty() && temp>0)
         {
            ll x = p.front() ; p.pop() ; 
            m = m*x ; 
            temp-- ; 
         }
         temp = 4 ;  
         while(!q.empty() && temp>0)
         {
            ll x = q.front() ; q.pop() ; 
            m = m*x ; 
            temp-- ; 
         }
         ans = max(ans,m) ; 
      }
      ans = max(ans,co) ; 
      if(ze==1 && ans<0)
      {
         ans = 0 ; 
      }
      if(n==5)
      {
         ans = ex  ; 
      }
      cout << ans << endl ;
   }
   return 0 ;
}