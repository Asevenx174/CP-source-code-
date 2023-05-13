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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   priority_queue < int , vector < int > , greater < int > > pq ; 
   map < int ,int > m ; 
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      m[x]++ ; 
      pq.push(x) ; 
   }
   int ans = 0 ; 
   while(1)
   {
     // vector < int > v ; 
      int s = 0 ; 
      while(!pq.empty())
      {
         int x = pq.top() ; pq.pop() ; 
         if(m[x]==0){continue;}
         s = x ; break ; 
      }
      if(s==0){break;}
      m[s]-- ; 
      int add = 1 ; 
      while(m[s+add]>0)
      {
         m[s+add]-- ; 
         add++ ; 
      }
      ans++ ; 
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}