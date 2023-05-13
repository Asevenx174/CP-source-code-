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
#define vv                vector<int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
void solve()
{
   map < vector < int > , int > used ; 
   vector < vector < int > > per ;
   set < vector < int > > st ; 
   int n,m ;
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      vector < int > temp ; 
      for (int i = 0; i < m ; ++i)
      {
         int x ;
         cin >> x ; 
         temp.push_back(x) ; 
      }
      per.push_back(temp) ; 
      used[temp] = 1 ;  
   }
   
   for(auto it=per.begin();it!=per.end();it++)
   {
      for(int i=0;i<(1<<m);i++)
      {
        vector < int > temp = *it ;
        for (int j = 0; j < m ; ++j )
        {
          int mask = 1 << j ; 
          if( (i&mask)!=0 )
          {
            temp[j]=0 ; 
          }
        }
        used[temp] = 1 ; 
      }
   }
   int idx = 0 ; 
   for(auto it=per.begin();it!=per.end();it++ )
   { 
      int ans = 0 ; 
      vector < int > temp = *it , q(m,0) ; 
      for (int i = 0; i < m ; ++i)
      {
         int id = temp[i] ; 
         q[id-1] = i+1 ; 
         if(used[q])
         {
            ans = i+1 ; 
         }
         else{break;}
      }
      if(idx){cout << " ";}
      cout << ans ;
      idx = 1 ; 
   }
   cout << endl ;
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