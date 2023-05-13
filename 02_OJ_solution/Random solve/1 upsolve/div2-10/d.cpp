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

#define SL(a)              scanf("%I64d",&a)
#define SLL(a,b)           scanf("%I64d %I64d",&a,&b)
#define PL(x) printf("%I64d\n",(x))
#define PLL(x,y) printf("%I64d %I64d\n",x,y)

#define S(a)              scanf("%d",&a)
#define SS(a,b)           scanf("%d %d",&a,&b)
#define P(x) printf("%d\n",(x))
#define PP(x,y) printf("%d %d\n",x,y)

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e3+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int parent[maxx+5],sized[maxx+5];
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
map < int , pii > ip ; 
map < pii ,int > pi ; 
int fx[10] = {1,1,0,-1,-1,0} ;
int fy[10] = {0,1,1,0,-1,-1} ; 
bool valid(int x,int y)
{
   pii p = ip[x] ; 
   pii q = ip[y] ; 
   for (int i = 0; i < 6 ; ++i)
   {
      pii temp = {p.ff+fx[i],p.ss+fy[i]} ; 
      if(temp==q){return true ; }
   }
   return false ; 
}
int main()
{
   debugMode();
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x,y ; 
      cin >> x >> y ; 
      pii p = {x,y} ;
      pi[p] = i+1 ; 
      ip[i+1] = p ; 
      make_set(i+1) ; 
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=i+1;j<=n;j++)
      {
         if(valid(i,j))
         {
            union_sets(i,j) ; 
         }
      }
   }
   set < int > ans ;
   for (int i = 0; i < n ; ++i)
   { 
      int temp = find_set(i+1) ; 
      ans.insert(temp) ; 
   }
   cout << ans.size() << endl ;
   return 0 ;
}