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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,h,ar[maxx+10],a,b ; 
std::vector < int > u,v ;
int calco(int k)
{
   //if(k!=3){return 0;}
   int ans = 0 ; 
   auto it = lower_bound(u.begin(),u.end(),k) ;
   int add = a-(it-u.begin()) ;
  // cout << k << " " << add << endl ;   
   ans+=add ; 
   auto lt = upper_bound(v.begin(),v.end(),h-k) ;
   add = b-(lt-v.begin()) ;
  // cout << k << " " << add << endl ;
   ans+=add ; 
   return ans ; 
}
void solve()
{
   cin >> n >> h ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ; 
      if(i%2==0)
      {
         u.push_back(x) ;
      }
      else
      {
         v.push_back(x); 
      }
   }
   a = u.size() ; 
   b = v.size() ;
   sort(u.begin(),u.end()) ; 
   sort(v.begin(),v.end()) ;
   int f = mod ; 
   int ans = 0 ;
   map < int ,int > pq ;  
   for(int i=1;i<=h;i++)
   {
      int temp = calco(i) ; 
     // cout << i << " " << temp << endl ;
      if(temp<=f)
      {
         pq[temp]++ ; 
         f = temp ; 
         //cout << f << " ?? " << i << endl ;
      }
   }
   cout << f << " " << pq[f] << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}