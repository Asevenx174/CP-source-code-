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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10],n ; 
std::vector < int > v ;
void calco()
{
   int sum = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = ar[i+1]>0 ? 1 : -1 ; 
      sum+=x ; 
      v.push_back(sum) ; 
   }
}
void solve()
{
   queue < int > p,q ; 
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      ar[i+1] = x ; 
      if(x>0){p.push(x);}else{q.push(x);}
   }
   sort(ar+1,ar+n+1,greater<int>()) ; 
   v.clear() ; 
   calco() ; 
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << v[i] ; 
   }
   cout << endl ;
   int idx = 1 ; 
   int temp = min(p.size(),q.size()) ; 
   while(temp--)
   {
      ar[idx] = p.front() ; 
      ar[idx+1] = q.front() ; 
      p.pop() ;
      q.pop() ; 
      idx+=2 ;  
   } 
   while(!p.empty()){ar[idx++]=p.front();p.pop();}
   while(!q.empty()){ar[idx++]=q.front();q.pop();}
   v.clear() ; 
   calco() ; 
   for (int i = 0; i < n ; ++i)
   {
      if(i>0){cout << " " ;}
      cout << v[i] ; 
   }
   cout << endl ;
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