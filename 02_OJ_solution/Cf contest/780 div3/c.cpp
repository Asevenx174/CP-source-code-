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
const ll maxx = 2e5+10,mod=26,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int used[maxx] ; 
int arr[maxx] ; 
vector < pair < int ,pii > > ans ; 
int main()
{
   debugMode();
   map < char ,int > pq ; 
   char c = 'a' ; 
   int idx = 1 ; 
   while(c<='z')
   {
      pq[c]=idx ; 
      c++ ;
      idx++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      ans.clear() ; 
      ms(used,0) ; 
      std::vector< int > v[30] ;
      string s ;
      cin >> s ;
      int n = s.size() ; 
      idx = 1 ; 
      for(auto c : s ) 
      {
         int x = pq[c] ; 
         //cout << x << " " << idx << endl ;
         arr[idx] = x ; 
         v[x].push_back(idx) ; 
         idx++ ;  
      }
      for(int i=1;i<=mod;i++)
      {
         if(v[i].size()<2){continue;}
         auto it = v[i].begin() ; 
         for(int j=1;j<v[i].size();j++)
         {
            int x = *it ; 
            it++ ; 
            int y = *it ; 
            ans.push_back({y-x,{x,y}}) ; 
         }
      }
      set < int > sk ; 
      sort(ans.begin(),ans.end()) ; 
      for(auto x : ans )
      {
          int d = x.ff ; 
          pii p = x.ss ; 
          int l = p.ff , r = p.ss ; 
          auto it = sk.lower_bound(l) ; 
          if(it!=sk.end())
          {
             
             if(*it>r)
             {
                used[l] = 2 ; 
                used[r] = 2 ; 
                int temp = l ; 
                while(temp<=r)
                {
                  sk.insert(temp++) ;
                }
             }
          }
          else
          { 
             
                used[l] = 2 ; 
                used[r] = 2 ; 
                int temp = l ; 
                while(temp<=r)
                {
                  sk.insert(temp++) ;
                }
          }
      }
      int f = n ; 
      for(int i=1;i<=n;i++)
      {
         if(used[i]==2){f--;}
      }
      cout << f << endl ;
   }
   return 0 ;
}