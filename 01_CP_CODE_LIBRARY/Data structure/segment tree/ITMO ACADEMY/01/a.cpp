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
const ll maxx = 5e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
   int test ; 
   cin >> test ;
   while(test--)
   {
      char cc ; 
      map < char , bool > used ; 
      string s,ans="",last="" ;
      cin >> s ; 
      string temp = s ; 
      reverse(s.begin(),s.end()) ; 
      set < char > k ; 
      int idx = 0 ,f = 0 ,len = s.size()-1,saved=0,flag=0   ; 
      for(auto c : s )
      {
         if(!used[c])
         {
            if(f==0)
            {
               k.insert(c) ; 
               f = 1 ; 
               last+=c ; 
            }
            else
            {
               last+=c ; 
               saved = len ; 
               cc = 'a' ; 
               while(cc<='z')
               {
                  if(used[cc] && k.find(cc)==k.end()){flag=-1;}
                  cc++ ; 
               } 
               k.clear() ;
               k.insert(c) ;  
            }
            used[c] = true ; 
         }
         else
         {
            k.insert(c) ; 
         }
         len-- ; 
      }
      for (int i = 0; i < len ; ++i)
      {
         k.insert(temp[i]) ; 
      }
      cc = 'a' ; 
      while(cc<='z')
      {
         if(used[cc] && k.find(cc)==k.end()){flag=-1;}
         cc++ ; 
      } 
      if(flag==-1)
      {
         cout << flag << endl ; continue ; 
      }
      reverse(last.begin(),last.end()) ; 
      s = "" ; 
      for (int i = 0; i <= saved ; ++i)
      {
         s+=temp[i] ; 
      }
      cout << s << " " << last << endl ; 
   }
   return 0 ;
}