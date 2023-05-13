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
const ll maxx = 105 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
string t ; 
int len,n,ans ; 
std::vector < string > sr ;
std::vector< int > fin ;
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
bool dp[maxx][maxx][maxx] ;
void calco(int l,int r,int co,vector<int>pt )
{
   if(dp[l][r][co]){return;}
   if(r==len)
   {
      if(co<ans)
      {
         ans = co ; 
         fin.clear() ; 
         for(auto x : pt )
         {
            fin.push_back(x) ; 
         }
         return ;  
      }
   }
   for(int i=l;i<=r;i++)
   {
        for(int j=0;j<sr.size();j++)
        {
            string s = sr[j] ;
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
   dp[l][r][co] = true ; 
   return  ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      sr.clear() ; 
      memset(dp,false,sizeof(dp)) ; 
      ans = mod ; 
      map < string ,int > pq ; 
      cin >> t ; 
      len = t.size() ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         sr.push_back(s) ; 
         pq[s] = i+1 ; 
      }
      sort(sr.begin(),sr.end(),greater<string>()) ; 
      std::vector < int > pt ;
      calco(0,0,0,pt) ; 
      if(ans==mod)
      {
         cout << "-1" << endl ; continue ; 
      }
      cout << ans << endl ;
      fin.push_back(len) ; 
      for (int i = 0; i+1 < fin.size() ; ++i)
      {
         int l = fin[i] ; 
         int r = fin[i+1]-1 ; 
         int idx = 0 ; 
         int siz = fin[i+1]-fin[i] ; 
         for(auto s : sr )
         {
            if(s.size()<siz){continue;}
            if(valid(l,s))
            {
               idx = pq[s] ; break ;  
            }
         }
         //cout << l << " " << r << " " << idx << endl ;
         cout << idx << " " << l+1 << endl ; 
      }
   }
   return 0 ;
}