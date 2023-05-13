#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265  tan inverse = atan(value)(180PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i = b; i++)
#define pii                pair int,int

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen(input.txt, r, stdin);

freopen(output.txt, w, stdout);

#endif  ONLINE_JUDGE
}
int sub[maxx+10],n ; 
std::vector < int > tree[maxx+10] ;
int dfs(int u, int p)
{
   for (auto v : tree[u])
   {
      if (v != p) 
      {
         sub[u] += dfs(v, u);
      }
   }
   return sub[u] + 1 ;
}

int centroid(int u, int p)
{
   for (auto v : tree[u])
   { 
      if (v != p and sub[v] > n/2) 
      { 
         return centroid(v, u); 
      }
   } 
   return u;
}
void solve()
{

}
int main()
{
   debugMode();
   ll test = 1 ; 
   // cin  test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}