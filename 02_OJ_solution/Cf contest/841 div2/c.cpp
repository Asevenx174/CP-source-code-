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
const ll maxx = 4e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
std::vector < int > v ;
void precom()
{
   v.push_back(0) ; 
   for (int i = 1 ; i*i < maxx ; ++i)
   {
      v.push_back(i*i) ; 
   }
}
void solve()
{
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   map < int ,int > pq ; 
   pq[0]++ ; 
   int pre = 0,ans=0 ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = ar[i+1] ; 
      pre = pre^x ; 
      for(auto r:v)
      {
         int q = r^pre ; 
         ans+=pq[q] ; 
      }
      pq[pre]++ ; 
   }
   ll temp = (n*(n+qq)) ; 
   temp = temp/tt ; 
   temp = temp-(ll)ans ;
   cout << temp << endl ;   
}
int main()
{
   debugMode();
   precom() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}