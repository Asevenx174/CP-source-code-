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
std::vector < int> v ;
int n,f ; 
map < pii , bool > pq ; 
void calco(int x,int op)
{
   if(pq[{x,op}]){return;}
   if(f){return;}
   if(op>40){return;}
   if(x==n)
   { 
     f = 1 ; 
     cout << v.size() << endl ;
     for (int i = 0; i < v.size() ; ++i)
     {
        if(i>0){cout << " " ;}
        cout << v[i] ; 
     }
     cout << endl ;
     return ;
   }

   v.push_back(2) ; 
   calco(2*x+1,op+1);
   v.pop_back() ; 

   v.push_back(1) ; 
   calco(2*x-1,op+1);
   v.pop_back();
   pq[{x,op}] = true ; 
}
void solve()
{
   pq.clear() ; 
   f=0 ; 
   cin >> n ; 
   calco(1,1) ; 
   if(f==0)
   {
      cout << "-1" << endl ;
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