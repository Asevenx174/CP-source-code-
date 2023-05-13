#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
int parent[30],sized[30];
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
int main()
{
   debugMode();
   map < int ,char > ic ; 
   map < char ,int > ci ; 
   int idx = 1 ; 
   char ch = 'a' ; 
   while(ch<='z')
   {
      ci[ch] = idx ; 
      ic[idx] = ch ; 
      ch++ ; 
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      int n ;
      cin >> n ;
      string s ;
      cin >> s ;
      idx = 1 ; 
      for(auto c : s)
      {
         ar[idx++] = ci[c] ; 
      }
      std::vector < int > ass(30,0) ;
      priority_queue < int , vector < int > , greater < int > > pq ; 
      for(int i=1;i<=26;i++)
      {
         pq.push(i) ; 
         make_set(i) ;
      }
      for(int i=1;i<=n;i++)
      {
         int x = ar[i] ; 
         if(ass[x]!=0){continue;}
         vector < int > temp ; 
         while(!pq.empty())
         {
            int y = pq.top() ; 
            if(find_set(x)==find_set(y) || x==y)
            {
               pq.pop() ; 
               temp.push_back(y) ; 
               continue ; 
            }
            union_sets(x,y) ; 
            ass[x] = y ; 
            pq.pop() ; 
            break ; 
         }
         for(auto y : temp )
         {
            pq.push(y) ; 
         }
      }
      for(int i=1;i<=n;i++)
      {
         int x = ar[i] ; 
         int y = ass[x] ; 
         if(y==0)
         { 
            y = pq.top() ; 
         }
         cout << ic[y] ; 
      }
      cout << endl ;
   }
   return 0 ;
}