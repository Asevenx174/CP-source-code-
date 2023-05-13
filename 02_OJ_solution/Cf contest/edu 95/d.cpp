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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   int n,ques,best=0 ;
   cin >> n >> ques ;
   set < int > s ; 
   multiset < int > dis ; 
   ll sum = 0 ; 
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      s.insert(ar[i]) ; 
      if(i>1)
      {
         int d = abs(ar[i]-ar[i-1]) ; 
         dis.insert(d) ; 
      }
   } 
   std::vector < pii > pp ; 
   for (int i = 0; i < ques ; ++i)
   {
      int x,y ;
      cin >> x >> y ; 
      pp.push_back({x,y}) ; 
   }
   for(auto x : dis)
   {
      sum+=x ; 
   }
   if(n>2)
   {
      cout << ll(sum-*dis.rbegin()) << endl ;
   }
   else
   {
      cout << "0" << endl ;
   }
   for(auto p : pp )
   {
      int t = p.ff ;
      int x = p.ss ; 
      if(t==0)
      {
         auto it = s.find(x) ; 
         auto lt = it ; 
         lt++ ; 
         int l=0,r=0 ; 
         if(lt!=s.end())
         {
             int d = abs(*lt-*it) ; 
             dis.erase(dis.find(d)) ; 
             if(dis.find(d)==dis.end())
             {
               sum-=d ; 
             }
             r = *lt ; 
         }
         lt = it ;
         if(lt!=s.begin())
         {
            lt-- ; 
            int d = abs(*lt-*it) ; 
            dis.erase(dis.find(d)) ;
            if(dis.find(d)==dis.end())
            {
               sum-=d ; 
            }
            l = *lt ; 
         }
         if(min(l,r)!=0)
         {
            int d = abs(l-r) ; 
            if(dis.find(d)==dis.end())
            {
               sum+=d ; 
            }
            dis.insert(d) ; 
         }
      }
      else
      {
         int l=0,r=0 ;
         auto it = s.upper_bound(x) ; 
         if(it!=s.end())
         {
            r = *it ; 
            int d = abs(x-r) ; 
            if(dis.find(d)==dis.end())
            {
               sum+=d ; 
            }
            dis.insert(d) ; 
         }
         if(it!=s.begin())
         {
            it-- ;
            l = *it ; 
            int d = abs(x-l) ; 
            if(dis.find(d)==dis.end())
            {
               sum+=d ; 
            }
            dis.insert(d) ; 
         }
         if(min(l,r)!=0)
         {
            int d = abs(l-r) ; 
            dis.erase(dis.find(d)) ;
            if(dis.find(d)==dis.end())
            {
               sum-=d ; 
            }
         }
         s.insert(x) ; 
      }
      cout << ll(sum-*dis.rbegin()) << endl ;
   }
   return 0 ;
}