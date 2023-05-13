#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
int main()
{
   debugMode();
   map < string ,int > pq ; 
   std::vector< string > v ;
   for(char i='a';i<='z';i++)
   {
      for(char j='a';j<='z';j++)
      {
          if(i==j){continue;}
          string s = "" ;
          s+=i ;
          s+=j ;  
          v.push_back(s) ; 
      }
   }
   sort(v.begin(),v.end()) ; 
   int idx = 1 ; 
   for(auto s : v )
   {
      pq[s] = idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      cout << pq[s] << endl  ;
   }
   return 0 ;
}