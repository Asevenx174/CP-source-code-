#include<bits/stdc++.h>
using namespace std ;

const int imin = 1e9+100;
const int maxx = 2e6+10,mod=35,qq=1,zz=0;


map < int , char > ic ; 
map < char ,int > ci ; 
string s,t ; 
int sr[maxx+10] ;
int tr[maxx+10] ; 
std::vector < int > g[40] ;
int n ; 
bool valid(int idx)
{
   int p = 0 ; 
   while(idx<=n)
   {
      int x = sr[idx] ;
      auto it = upper_bound(g[x].begin(),g[x].end(),p) ; 
      if(it==g[x].end()){return false;}
      p = *it ; 
      idx+=2 ; 
   }
   return true ; 
}
int main()
{
   //debugMode();
   char ch = 'a' ; 
   int idx = 1 ; 
   while(ch<='z')
   {
      ic[idx] = ch ; 
      ci[ch] = idx ; 
      ch++ ; 
      idx++ ; 
   }
   cin >> s >> t ; 
   n = s.size() ; 
   idx = 1 ; 
   for(auto c : s )
   {
      sr[idx++] = ci[c] ; 
   }
   idx = 1 ; 
   for(auto c : t )
   {
      tr[idx] = ci[c] ;
      g[ tr[idx] ].push_back(idx) ; 
      idx++ ; 
   }
   int f = 0 ; 
   if(valid(1))
   {
      f = 1 ; 
   }
   if(n>1)
   {
      if(valid(2))
      {
         f = 1 ; 
      } 
   }
   if(f)
   {
      cout << "Yes" << endl ;
   }
   else
   {
      cout << "No" << endl ;
   }
   return 0 ;
}