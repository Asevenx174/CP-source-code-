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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,m,k,ar[maxx+10] ; 
void solve()
{
   queue < int > q ; 
   set < int > s ; 
   cin >> n >> m >> k ;
   for (int i = 0; i < k ; ++i)
   {
      int x ;
      cin >> x ; 
      q.push(x) ; 
   }
   int lim = n*m-4 ; 
   int idx = k ; 
   while(idx>0)
   {
      auto it = s.find(idx) ; 
      if(it==s.end())
      {
         while(!q.empty() && q.front()!=idx)
         {
            s.insert(q.front()) ; q.pop() ; 
         }
         q.pop() ; 
      }
      else
      {
         s.erase(it) ; 
      }
      if(s.size()>lim){break;}
      idx-- ; 
   }
   if(idx!=0)
   {
      cout << "TIDAK" << endl ;
   }
   else
   {
      cout << "YA" << endl ;
   }
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