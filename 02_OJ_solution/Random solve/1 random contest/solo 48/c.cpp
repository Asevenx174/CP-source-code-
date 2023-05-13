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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int main()
{
   debugMode();
   std::vector< int > v,q ;
   int n ;
   cin >> n ;
   for (int i = 0; i < n ; ++i)
   {
      int x ;
      cin >> x ;
      v.push_back(x) ; 
   }
   sort(v.begin(),v.end()) ; 
   int i = 0 ; 
   while(i<n)
   {
      int j = i ; 
      while(j+1<n && v[j+1]-v[j]==1)
      {
         j++;
      }
      if(i>0)
      {
         q.push_back(-1) ; 
      }
      if(i==j)
      {
         q.push_back(v[i]) ; 
         i++ ; 
      }
      else if(j-i>1)
      {
         q.push_back(v[i]) ; 
         q.push_back(0) ; 
         q.push_back(v[j]) ; 
         i = j+1 ; 
      }
      else
      {
         q.push_back(v[i]) ; 
         i++ ; 
      } 
   }
   for(auto x : q)
   {
      int val = 0 ; 
      if(x==0)
      {
         cout << "-" ; 
      }
      else if(x==-1)
      {
         cout << " " ; 
      }
      else
      {
         cout << x ; 
      }
   }
   cout << endl ;
   return 0 ;
}