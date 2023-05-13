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
int c[maxx+10],in[maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(in,0) ; 
      ms(c,0) ; 
      int n ;
      cin >> n ;
      for(int i=2;i<=n;i++)
      {
         int p ;
         cin >> p ;
         c[p]++ ; 
      }
      c[0]++ ; 
      std::vector < pii > v ;
      for(int i=0;i<=n;i++)
      {
         if(c[i]==0){continue;}
         v.push_back({c[i],i}) ; 
      }
      sort(v.begin(),v.end(),greater<pii>()) ; 
      priority_queue < pii > pq ; 


      
      int t=0 ; 
      for(auto p : v ) 
      {
        t++ ; 
        in[p.ss]=t ; 
      }
      for(auto p : v )
      {
         int m=p.ff,b=p.ss ; 
         int sub = min(m,t-in[b]+1) ;
         m-=sub ; 
         if(m>0)
         {
            pq.push({m,b});
         }  
         in[b]=t ; 
      }
      while(!pq.empty())
      {
         pii p = pq.top() ; pq.pop() ; 
         int m = p.ff , b = p.ss ;
         int f = t-in[b] ; 
         int sub = min(m,f) ; 
         m-=sub ; 
         if(m>0)
         {
            in[b]+=f ; 
            sub = min(m,2) ; 
            m-=sub ; 
            in[b]++ ; 
            t++ ; 
            if(m>0)
            {
               pq.push({m,b}) ;
            }
         }
      }
      cout << t << endl ;

   }
   return 0 ;
}