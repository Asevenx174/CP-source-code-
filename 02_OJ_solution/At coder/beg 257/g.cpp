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
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 3e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,br[maxx+10] ; 
bool used[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ms(br,0) ; 
      ms(used,false) ;
      ll l,r ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         ll x ; 
         scanf("%I64d",&x) ; 
         ar[i+1] = x ;  
         if(ar[i+1]==1)
         {
            l = i+1 ; 
         }
         else if(ar[i+1]==n)
         {
            r = i+1 ;
         }
      }
      if(n==1)
      {
         cout << "0" << endl ; 
         continue ; 
      }
      ll temp = 0 ; 
      if(l>r)
      {
         temp = !temp ; 
         swap(l,r) ; 
      }
      int c = temp ; 
      std::vector < int > v ; 
      for(int i=1;i<l;i++)
      {
         v.push_back(ar[i]) ; 
      } 
      sort(v.begin(),v.end()) ; 
      deque < int > dq ; 
      for(auto x : v )
      {
         dq.push_back(x) ; 
      }
      br[l] = 1 ; 
      while(l>1)
      {
         l-- ; 
         if( (dq.front()==ar[l] && c==1) || (dq.back()==ar[l] && c==0) )
         {
             br[l] = 1 ; 
             c = !c ; 
         }
         used[ ar[l] ] = true ; 
         if(!dq.empty())
         {
            while(used[dq.front()])
            {
               dq.pop_front() ; 
               if(dq.empty()){break;}
            }
         }
         if(!dq.empty())
         {
            while(used[dq.back()])
            {
               dq.pop_back() ; 
               if(dq.empty()){break;}
            }
         }
      }
      v.clear() ; 
      for(int i=r+1;i<=n;i++)
      {
          v.push_back(ar[i]) ; 
      }
      sort(v.begin(),v.end()) ; 
      for(auto x : v )
      {
         dq.push_back(x) ; 
      }

      br[r] = 1 ; 
      c = !temp ; 
      while(r<n)
      {
         r++ ;  
         if( (dq.front()==ar[r] && c==1) || (dq.back()==ar[r] && c==0) )
         {
             br[r] = 1 ; 
             c = !c ; 
         }
         used[ ar[r] ] = true ; 
         if(!dq.empty())
         {
            while(used[dq.front()])
            {
               dq.pop_front() ; 
               if(dq.empty()){break;}
            }
         }
         if(!dq.empty())
         {
            while(used[dq.back()])
            {
               dq.pop_back() ; 
               if(dq.empty()){break;}
            }
         }
      }
      ll ans = 0 ;
      for(int i=1;i<=n;i++)
      {
         ans+=br[i] ; 
      }
      ans-- ;
      cout << ans << endl ;
   }
   return 0 ;
}