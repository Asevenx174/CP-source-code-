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
int used[maxx] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   { 
      int n ;
      cin >> n ; 
      set < int > p,q ; 
      string s ;
      cin >> s ;
      int idx = 1 ; 
      for(auto c : s )
      {
         if(c=='1')
         {
           p.insert(idx) ; 
         }
         else
         {
           q.insert(idx) ; 
         }
         idx++ ; 
      }
      idx = 1 ; 
      while(!p.empty() || !q.empty())
      {
          int pos = 0 ; 
          auto it = p.begin()  ;
          auto lt = q.begin()  ; 
          if(!p.empty() && !q.empty())
          {
              int x = *it > *lt ? 0 : 1  ; 
              while(1)
              {
                  if(x==1 && !p.empty())
                  {
                     it = p.upper_bound(pos) ; 
                     if(it==p.end()){break;}
                     used[*it] = idx ; 
                     pos = *it ; 
                     p.erase(it) ; 
                  }
                  else if(x==0 && !q.empty())
                  {
                     it = q.upper_bound(pos) ;
                     if(it==q.end()){break;}
                     used[*it] = idx ; 
                     pos = *it ; 
                     q.erase(it) ; 
                  }
                  else { break ; }
                  x = !x ; 
              }
              idx++ ; 
          }
          else if(!p.empty())
          {
             it = p.begin() ; 
             while(it!=p.end())
             {
               used[*it] = idx++ ; 
               it++ ; 
             }
             p.clear() ; 
          }
          else
          {
             it = q.begin() ; 
             while(it!=q.end())
             {
               used[*it] = idx++ ; 
               it++ ; 
             }
             q.clear() ;
          }
      }
      cout << idx-1 << endl ;
      for(int i=1;i<=n;i++)
      {
         if(i!=1){cout << " " ; }
         cout << used[i] ; 
      }
      cout << endl ; 
   } 
 
   return 0 ;
}