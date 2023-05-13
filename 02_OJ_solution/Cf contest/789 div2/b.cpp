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
ll ar[maxx+10],br[maxx+10],pa[maxx+10],pb[maxx+10],n ;  
map < int ,int  > temp ; 
bool used[maxx+10],same[maxx+10] ; 
std::vector< pii >  pq ; ;
set < int > sa,sb,p,q ; 
int main()
{
   debugMode();
   cin >> n ; 
   lp(i,1,n)
   {
      cin >> ar[i] ;
      p.insert(ar[i]) ;  
   }
   lp(i,1,n)
   {
      cin >> br[i] ; 
      q.insert(br[i]) ; 
   }
   ll ques ; 
   cin >> ques ; 
   while(ques--)
   {
      ll x,y ;
      cin >> x >> y ; 
      pq.push_back({x,y}) ; 
   }

   int idx = 1 ; 
   for(auto x : p )
   {
      temp[x]=idx++ ; 
   }
   
   lp(i,1,n)
   {
      ar[i] = temp[ ar[i] ] ;  
      sa.insert(ar[i]) ; 
      pa[i]=sa.size() ; 
   }

   idx = 1 ; 
   for(auto x : q )
   {
      temp[x]=idx++ ; 
   }
   
   lp(i,1,n)
   {
      br[i] = temp[ br[i] ] ;  
      sb.insert(br[i]) ; 
      pb[i]=sb.size() ; 
   }
   
   p.clear();
   q.clear() ; 
   sa.clear() ; 
   sb.clear() ; 

   ll i=1,j=1 ; 
   while( min(i,j)<=n )
   {
      if(p.size()>q.size() && j<=n )
      {
         ll b = br[j] ; 
         if(!used[b])
         {
            auto it = sa.find(b) ; 
            if(it==sa.end())
            {
               sb.insert(b) ; 
            } 
            else
            {
               sa.erase(it) ;
               used[b] = true ; 
            }
         }
         q.insert(b) ; 
         j++ ; 
      }
      else
      {   
          ll a = ar[i] ; 
          if(!used[a])
          {
             auto it = sb.find(a) ; 
             if(it==sb.end())
             {
               sa.insert(a) ; 
             } 
             else
             {
               sb.erase(it) ;
               used[a] = true ; 
             }
          }
          p.insert(a) ; 
          i++ ; 
      }
      if(p.size()==q.size() && max(sa.size(),sb.size())==0 )
      {
         same[p.size()] = 1 ; 
      }
   }


   for(auto p : pq )
   {
      ll a = pa[p.ff] ;  
      ll b = pb[p.ss] ;

      if(a==b && same[a]==true)
      {
         cout << "Yes" << endl ;
      }
      else
      {
         cout << "No" << endl ;
      }
   }
   return 0 ;
}