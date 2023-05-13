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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,k,ar[maxx+10],br[maxx+10] ; 
std:: queue < int > v[40] ;
set < int > t ; 
string s ; 
void rem(int idx)
{
   int x = ar[idx] ; 
   int ase = v[x].size() ; 
   int p = ase/k ;
   if(ase%k!=0){p++;}
   int need = (p*k)-ase ; 

   while(!v[x].empty())
   {
      int y = v[x].front() ; 
      t.erase(t.find(y)) ; 
      v[x].pop();  
      br[y] = x ; 
   } 

   auto it = t.rbegin();  
   int temp = need ;
   while(temp--)
   {
      int idx = *it ; it++ ; 
      int y = ar[idx] ; 
      v[y].pop();  
      br[idx] = x ; 
   }

   temp = need ;   
   while(temp--)
   {
      auto it = t.rbegin() ;
      int y = *it ; 
      t.erase(t.find(y)) ; 
   }
}
void solve()
{
   for (int i = 0; i < 30 ; ++i)
   {
      while(!v[i].empty())
      {
         v[i].pop() ; 
      }
   }
   cin >> n >> k ; 
   cin >> s ; 
   for (int i = 0; i < n ; ++i)
   {
      int x = (s[i]-'a')+1 ; ar[i+1] = x ; 
      v[x].push(i+1) ; 
      t.insert(i+1) ; 
   }
   if(n%k!=0){cout << "-1" << endl ; return ;}
   while(!t.empty())
   {
      auto it = t.begin() ; 
      int x = *it ; 
     // cout << x << endl ;
      rem(x) ;  
   }
   for (int i = 0; i < n ; ++i)
   {
      char c = 'a'+(br[i+1]-1) ; 
      cout << c ; 
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