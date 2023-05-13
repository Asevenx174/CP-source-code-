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


using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 4e4+5,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
//ll dp[10][maxx+5] ; 

ll dp[maxx+10] ; 
std::vector < int > p ;
int getint(string s)
{
   int len = s.size(),sum=0,idx=1 ; 
   while(len--)
   {
      int x = s[len]-'0' ; 
      sum+=(x*idx) ; 
      idx = idx*10 ; 
   }
   return sum ;
}
int main()
{
   debugMode();
   for (int i = 0; i+1< 10 ; ++i)
   {
      int j = i+1 ; 
      int k = j+j*10 ; 
      p.push_back(j) ; 
      p.push_back(k) ; 
   }
   std::vector< string > str ;
   for (int i = 0; i <10 ; ++i)
   {
       string s = "" ; 
       char a = i+'0' ;
       s+=a ;  
       str.push_back(s) ; 
       for (int j = 0; j < 10 ; ++j)
       {
           char b = j+'0' ; 
           string x = s+b ;  
           if(a==b){str.push_back(x);}
           for (int k = 0; k < 10 ; ++k)
           {
              char c = k+'0' ; 
              string y = x+c ;  
              if(a==c){str.push_back(y) ;}
           }
       }
   }
   char cc = '1' ; 
   while(cc<='9')
   {
      for(auto s : str )
      {
          string temp = cc+s+cc ; 
          int pq = getint(temp) ; 
          if(pq>maxx){continue;}
          p.push_back(pq) ; 
      }
      cc++ ; 
   }
   sort(p.begin(),p.end()) ; 
   

   dp[0] = 1 ; 
   for(auto y : p)
   {
       for(int i=1;i<=maxx;i++)
       {
           if(i-y>=0)
           {
               dp[i]=(dp[i]+dp[i-y]+mod)%mod;
           }
       }
   }




   int len = p.size() ; 
   int test ;
   cin >> test ;
   while(test--)
   {
      int x ;
      cin >> x ;
      cout << dp[x] << endl ;
   } 
   return 0 ;
}