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
void print_vector(vector<int> v)
{ 
   //cout << "yes" << endl ;
    for(int i=0; i<(int)v.size(); i++)
        std::cout << '\t' << v[i]; 
    std::cout << "\n"; 
    
}
void solve()
{
   std::vector < vector < int > > per ; 
   set < vector < int > > st ; 
   int n,m ; 
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      vector < int > temp ; 
      for (int j = 0; j < m ; ++j)
      {
         int x ;
         cin >> x ; 
         temp.push_back(x) ; 
      }
      per.push_back(temp) ; 
      st.insert(temp) ; 
   }
   for(auto v : per)
   {
      for (int i = 0 ; i < (1<<m) ; ++i)
      {
         vector < int > temp ; 
         for(auto x : per[i])
         {
            temp.push_back(x) ; 
         } 
         for (int j = 0; j < m ; ++j )
         {
            int mask = 1 << j ; 
            if( (i&mask)!=0 )
            {
               temp[j]=0 ; 
            }
         }
         st.insert(temp) ; 
      }
   }
   cout << st.size() << endl ;
   for(auto it = st.begin();it!=st.end();it++)
   {
      print_vector(*it) ; 
   }
   return ; 
   for (auto it=per.begin();it!=per.end();it++)
   {
      vector < int > p ; 
      print_vector(*it) ; 
      break ; 
      vector < int > temp(m,0) ; 
      int idx = 1,ans=0 ; 
      for(auto x : p)
      {
        temp[x-1] = idx ; 
        if(st.find(temp)==st.end())
        {
           break ; 
        }
        else
        {
           ans = idx ; 
        }
        idx++ ; 
      }
      cout << ans << endl ;
   }
}
int main()
{
   debugMode();
   ll test = 1 ; 
  // cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}