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
int sr[maxx+10],n ; 
string s ; 
void calco()
{
   std::vector < int > v ;
   map < int ,int > pq ; 
   for(int i=1;i<=n/2;++)
   {
      int j = n-i+1 ; 
      if(sr[i]==sr[j])
      { 
         pq[ sr[i] ]++ ; 
      }
      else
      {
         v.push_back(i) ; 
      }
   }
   priority_queue < pii > p ; 
   for(int i=1;i<=26;i++)
   {
      p.push({pq[i],i}) ; 
   }
   while(p.size()>1)
   {
      int a = p.top().ff ; p.pop() ; 
      int b = p.top().ff ; p.pop() ; 
      
   }
}
void solve()
{
   cin >> n ;
   cin >> s ; 
   if(n%2==1)
   {
      cout << "-1" << endl ; return ;
   }
   int idx = 1 ; 
   for(auto c : s)
   {
      sr[idx++] = (c-'a')+1 ; 
   }
   calco() ; 
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