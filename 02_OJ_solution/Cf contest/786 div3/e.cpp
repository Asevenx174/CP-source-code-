#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
ll ar[maxx+10] ; 
int main()
{
   debugMode();
   std::vector < int > temp ;
   ll n ;
   cin >> n ;
   lp(i,1,n)
   {
      cin >> ar[i] ; 
      temp.push_back(ar[i]) ; 
   }
   sort(temp.begin(),temp.end()) ; 
   auto it = temp.begin() ; 
   int l = *it ;
   it++ ;
   int r = *it ; 
   int ans = (l+1)/2 + (r+1)/2 ; 
   for(int i=1;i+1<n;i++)
   {
      int j = i+2 ; 
      int a = ar[i] ; 
      int b = ar[j] ; 
      int c = min(a,b) ; 
      int sum = c ; 
      a-=c ;
      b-=c ; 
      if(a>0)
      {
         sum+=((a+1)/2) ; 
      }
      else if(b>0)
      {
         sum+=((b+1)/2) ; 
      }
      ans = min(ans,sum) ; 
   }
   lp(i,1,n-1)
   {
      int j = i+1 ; 
      int a = ar[i] ; 
      int b = ar[j] ; 
      int sum = 0 ; 
      while(min(a,b)>0)
      {
         if(a>b){swap(a,b);}
         int h = b/2 ; 
         int add = max(min(a,h/2),1) ; 
         sum+=add ; 
         b-=(2*add) ; 
         a-=add ; 
      }
      a = max(max(a,b),0) ; 
      sum+=((a+1)/2) ; 
      ans = min(ans,sum) ; 
   }
   cout << ans << endl ;
   return 0 ;
}