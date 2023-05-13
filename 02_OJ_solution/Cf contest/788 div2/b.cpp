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
   debugMode() ;

   map < char ,int > pq ; 
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      pq[cc++]=idx++ ; 
   }

   int test ;
   cin >> test ;
   while(test--)
   {
      std::vector< bool > used(50,false) ;
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      idx = 1 ; 
      for(auto c : s )
      {
         ar[idx++]=pq[c] ; 
      }
      int k ;
      cin >> k ;
      lp(i,1,k)
      {
         cin >> cc ; 
         used[ pq[cc] ] = true ; 
      }
      queue < pii > p,q ; 
      int last = 0,ans=0 ,f=1 ; 
      for(int i=2;i<=n;i++)
      {
         if( used[ ar[i] ] )
         {
            int l = i ; 
            int r = i ; 
            while(i+1<=n && used[ ar[i+1] ] )
            {
               r++ ;
               i++;
            }
            ans = max(l-f,ans) ; 
            f = r ; 
            last = r ; 
            
         }
      }
      cout << ans << endl ;
   }
   return 0 ;
}