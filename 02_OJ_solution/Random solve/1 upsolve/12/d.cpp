#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n,k ; 
vector < int > store ; 
bool valid(int g)
{
   for(int i=1;i<n;i++)
   {
      int f = 1 ; 
      int temp = min((int)store.size(),6) ; 
      multiset < int > s ; 
      while(temp--)
      {
         s.insert(store[temp]) ; 
      }
      int have = k ; 
      int j = i ; 
      while(j<=i+1)
      {
         if(ar[j]<g)
         {
           if(have==0){f=0;break;}
           have-- ; 
           auto it = s.find(ar[j]) ; 
           if(it!=s.end())
           {
             s.erase(it) ; 
             s.insert(mod) ; 
           }
         }
         j++ ; 
      }
      if(f==0){continue;}
      auto it = s.begin() ; 
      while((2LL*(*it))<(ll)g && have>0)
      {
         it++ ; 
         have-- ; 
      }
      if((2LL*(*it))<(ll)g)
      {
         continue ;
      }
      return true ; 
   }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< pii > v ;
      scanf("%d %d",&n,&k) ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         scanf("%d",&x) ; 
         v.push_back({x,i+1}) ; 
      }
      sort(v.begin(),v.end()) ; 
      int temp = max(0,k-3) ; 
      k-=temp ; 
      store.clear() ; 
      for(int i=1;i<=n;i++)
      {
         pii p = v[i-1] ; 
         int x = p.ff ; 
         int idx = p.ss ;
         if(temp>0)
         {
            x = mod ; temp-- ; 
         }
         ar[idx] = x ; 
         store.push_back(x) ; 
      }
      sort(store.begin(),store.end()) ; 
      ll l=1,r=mod,ans=0 ; 
      while(l<=r)
      {
         int m = (l+r)/2 ;
         if(valid(m))
         {
            ans = m ; 
            l = m+1 ; 
         }
         else
         {
            r = m-1 ; 
         }
      }
      printf("%d\n",ans) ; 
   }
   return 0 ;
}