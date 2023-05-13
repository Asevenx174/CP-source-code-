#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pi                pair < string , string >

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 15 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
map < int ,char > ic ; 
map < char ,int > ci ; 
string t,sr[maxx+5] ; 
int n ; 
std::vector < pi > pq[30+10] ;
bool valid(int pos,pi p)
{
   string pre = p.ff ; 
   string suf = p.ss ; 
   int a = pre.size() ; 
   int b = suf.size() ; 
   int temp = b ; 
   int idx = pos ; 
   int i = 0 ; 
   int x = 0 ;
   int y = 0 ;  
   while(temp-- && idx<t.size())
   {
      if(suf[i]==t[idx]){x++;}else{return false;}
      idx++ ;
      temp-- ;
      i++ ;
   }
   temp = a ; 
   idx = pos-1 ; 
   while(temp-- && idx>=0)
   {
      if(pre[temp]==t[idx]){y++;}else{return false;}
      idx-- ; 
   } 
   if(x==a && y==b){return true ;}
   return false ; 
}

int dp[maxx+10][maxx+10] ; 
int calco(int prev,int idx)
{
   if(dp[prev][idx]!=-1){return dp[prev][idx];}
   if(idx>=t.size()){return 0;}
   char c = t[idx] ;
   int k  = ci[c]  ;
   int ans = mod ; 
   for(auto p : pq[k])
   {
      if(valid(idx,p))
      {
         int temp = calco(idx,idx+p.ss.size())+1 ;
         ans = min(ans,temp) ; 
         temp = calco(idx,idx+1)+1 ;
         ans = min(ans,temp) ; 
      }
   }
   return dp[prev][idx] = ans ;   
}
int main()
{
   debugMode();
   char cc = 'a' ; 
   int idx = 1 ; 
   while(cc<='z')
   {
      ic[idx]=cc ; 
      ci[cc]=idx ;
      idx++ ; 
      cc++ ; 
   }
   int test ;
   cin >> test ;
   while(test--)
   {
      for (int i = 0; i < 32 ; ++i)
      {
         pq[i].clear() ; 
      }
      memset(dp,-1,sizeof(dp)) ; 
      cin >> t ; 
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> sr[i] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         string s = sr[i],pre="",suf="" ;
         for(int j=0;j<s.size();j++)
         {
            suf="" ; 
            for(int k=j;k<s.size();k++)
            {
               suf+=s[k] ; 
            }
            if(j>0){pre+=s[j-1];} 
            int temp = ci[suf[0]] ; 
            pq[temp].push_back({pre,suf}) ; 
            cout << temp << " " << pre << " " << suf << endl ;
         } 
      }
      int ans = calco(0,0) ; 
      if(ans==mod){ans=-1;}
      cout << ans << endl ;
   }
   return 0 ;
}