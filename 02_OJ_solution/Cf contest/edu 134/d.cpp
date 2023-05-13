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
const ll maxx = 15  ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

string t ;
vector < string > v ;
int n,len,ans ;
bool valid(int l,string s)
{
    int k = s.size() ;
    if(l+k>len){ return false ; }
    int i = 0 ;
    while(k--)
    {
        if(s[i]!=t[l]){return false ;}
        l++ ;
        i++;
    }
    return true ;
}
std::vector < int > fin ;
void calco(int l,int r,int co,vector<int>pt)
{
    if(r==len)
    {
       if(ans>co)
       {
          fin.clear() ; 
          ans = co ; 
          for(auto x : pt )
          {
             fin.push_back(x) ; 
          }
       }
    }
    for(int i=l;i<=r;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            string s = v[j] ;
            int k = s.size() ;
            if(valid(i,s))
            {
                pt.push_back(i) ; 
                calco(i+1,i+k,co+1,pt) ;
                pt.pop_back() ; 
                break ;
            }
        }
    }
}
int main()
{
   debugMode() ; 
   int test ;
   cin >> test ;
   while(test--)
   {
      map < string ,int > pq ; 
      fin.clear() ; 
      v.clear() ;
      cin >> t ;
      len = t.size() ;
      int q ;
      cin >> q ;
      int pos = 1 ; 
      while(q--)
      {
          string s ;
          cin >> s ;
          v.push_back(s) ;
          pq[s]=pos++ ; 
      } 
      sort(v.begin(),v.end(),greater<string>()) ;
      ans = mod ; 
      vector < int > pt ; 
      calco(0,0,0,pt) ;
      if(ans==mod)
      {
         cout << "-1" << endl ; continue ; 
      }
      cout << ans << endl ; 
      fin.push_back(len) ; 
      for(auto x : fin )
      {
         cout << x << endl ;
      }
      for (int idx = 0; idx+1 < ans ; ++idx)
      {
         int i = fin[idx] ; 
         int j = fin[idx+1] ; 
         //cout << i << " " << j-1 << endl ; 
         string temp = "" ; 
         while(i<j)
         {
            temp+=t[i++] ; 
         }
         for(auto x : v )
         {
            if(x==temp)
            {
               cout << pq[x] << " " << i+1 << endl ; 
               break ;  
            }
         }
      }
   }
   return 0 ;
}
