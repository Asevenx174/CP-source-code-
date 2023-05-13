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
int parent[maxx+5],sized[maxx+5],pr[maxx+10],n ;
void make_set(int v)
{
    parent[v] = v;
    sized[v]=1;
}
int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sized[a] < sized[b])
        swap(a, b);
        parent[b] = a;
        sized[a] += sized[b];
    }
}
void solve()
{
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      make_set(i+1) ; 
   } 
   for (int i = 0; i < n ; ++i)
   {
      cin >> pr[i+1] ; 
      int a = i+1 ; 
      int b = pr[i+1] ; 
      union_sets(a,b) ; 
   }
   set < int > s ; 
   for(int i=1;i<=n;i++)
   {
      parent[i] = find_set(i) ; 
      s.insert(parent[i]) ; 
      //cout << i << " ?? " << parent[i] << endl ; 
   }
   int c = s.size() ; 
   //cout << c << "??" << endl ; 
   int ans = mod ; 
  // find_set(1) ; 
   for(int i=1;i<n;i++)
   {
      int cc = c ; 
      //find_set(i+1) ; 
      if(parent[i]==parent[i+1])
      {
         cc++ ; 
      }
      else
      {
         cc-- ; 
      }
      ans = min(ans,n-cc) ; 
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