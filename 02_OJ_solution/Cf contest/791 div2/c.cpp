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
const ll maxx = 1e5+100,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int fx[maxx+10],fy[maxx+10] ; 
int main()
{
   debugMode();
   set < int > r,c ; 
   std::vector< pair < int , pii > > pq ;
   vector < pii > cor ; 
   int n,q ;
   cin >> n >> q ;
   for(int i=1;i<=n+10;i++)
   {
      r.insert(i) ; 
      c.insert(i) ;
   }
   while(q--)
   { 
      int t,x,y,x2,y2 ;
      scanf("%d %d %d",&t,&x,&y) ; 
      if(t==3)
      {
         scanf("%d %d",&x2,&y2) ; 
         cor.push_back({x2,y2}) ; 
      }
      pq.push_back({t,{x,y}}) ; 
   }
   auto temp = cor.begin() ; 
   for(auto xx : pq )
   {
      pii p = xx.ss ; 
      int t = xx.ff ; 
      int x = p.ff ;
      int y = p.ss ; 
      if(t==1)
      {
         if(fx[x]==0)
         {
            r.erase(r.find(x));
         }
         if(fy[y]==0)
         {
            c.erase(c.find(y));
         }
         fx[x]++;
         fy[y]++;
      }
      else if(t==2)
      {
         fx[x]--;
         fy[y]--;
         if(fx[x]==0)
         {
            r.insert(x) ; 
         }
         if(fy[y]==0)
         {
            c.insert(y) ; 
         }
      }
      else
      { 
         p = *temp ; 
         int x2 = p.ff ; 
         int y2 = p.ss ; 
         
         if(x>x2){swap(x,x2);}
         if(y>y2){swap(y,y2);}
         // x..x2 
         int f = 0 ,g = 0 ;
         auto it = r.lower_bound(x) ;
         auto lt = c.lower_bound(y) ; 

         if(*it>x2)
         {
            f = 1 ; 
         }
         else{f=0;}
         
         if(*lt>y2)
         {
            g = 1 ; 
         }
         else{g=0;}

         if(f==1 || g==1)
         {
            printf("Yes\n") ;
         }
         else
         {
            printf("No\n") ;
         }
         temp++ ; 
      }
   }
   return 0 ;
}