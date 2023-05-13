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
const ll maxx = 1e6+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+10] ; 
std::vector< int > v[maxx+10];
int main()
{
   debugMode();
   map < int ,char > ic ; 
   map < char ,int > ci ; 
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      ic[idx]=cc ; 
      ci[cc]=idx ; 
      idx++;
      cc++ ;
   }
   string s ;
   cin >> s ; 
   idx = 1 ; 
   for(auto c : s )
   {
      int temp = 0 ; 
      if(c=='L')
      {
         temp = -mod ; 
      }
      else if(c=='R')
      {
         temp = mod ; 
      }
      else
      {
         temp = ci[c] ;  
      }
      ar[idx++] = temp ; 
   }
   int f=0,pos=1 ; 
   for(int i=1;i<=s.size();i++)
   {
      //cout << ar[i] << endl ;
      //cout << i << " " << pos << endl ;
      
      if(ar[i]==mod)
      {
         pos = min(f+1,pos+1) ; 
      }
      else if(ar[i]==-mod)
      {
         pos = max(1,pos-1) ; 
      }
      else
      {
         v[pos].push_back(ar[i]) ; 
         if(pos<=f)
         {

         }
         else
         {
            pos++ ;
         }
         f++ ;
      }
   }
   string ans = "" ; 
   for(int i=1;i<maxx;i++)
   {
      string temp = "" ; 
      if(v[i].size()==0){continue;}
      char last ; 
      idx = 0 ; 
      for(auto x : v[i] )
      {
         char c = ic[x] ; 
         if(idx==0)
         {
            last = c ; 
         }
         else
         {
            temp+=c ; 
         }
         idx++ ; 
      }
      //reverse(temp.begin(),temp.end()) ; 
      temp+=last ; 
      ans+=temp ; 
   }
   if(ans==""){ return 0 ; }
   cout << ans << endl ;
   return 0 ;
}