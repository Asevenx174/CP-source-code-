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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   char cc = 'a' ; 
   map < char ,int > pq ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      pq[cc++]=idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      int n = s.size() ; 
      idx = 1 ; 
      int sum = 0 ; 
      for(auto c : s )
      {
         ar[idx++] = pq[c] ; 
         sum+=pq[c] ; 
      }
      if(n%2==0)
      {
         cout << "Alice" << " " << sum << endl ; 
         continue ; 
      }
      int a = max(sum-ar[n],sum-ar[1]) ; 
      int b = sum-a ; 
      sum = abs(a-b) ; 
      if(a>b)
      {
         cout << "Alice" << " " << sum << endl ; 
      }
      else
      {
         cout << "Bob" << " " << sum << endl ; 
      }
   }
   return 0 ;
}