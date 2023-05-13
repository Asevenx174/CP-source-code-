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
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}
ll n,cr[maxx+10] ; 
int main()
{
   debugMode();
   cin >> n ;
   ll best = mod ; 
   ll idx = 0 ; 
   for (int i = 0; i < 9  ; ++i)
   {
      cin >> cr[i+1] ; 
      if(cr[i+1]<=best)
      {
         best = cr[i+1] ; 
         idx = i+1 ; 
      }
   }
   ll m = n/best ; 
   ll r = n%best ; 
   if(m==0)
   {
      cout << "0" << endl ; return 0 ; 
   }
   m-- ; 
   ll ex = r+best ; 
   ll last = 0 ; 
   for(int i=9;i>0;i--)
   {
       if(cr[i]<=ex)
       {
         last = i ; 
         break ; 
       }
   } 
   string ans = "" ; 
   for(int i=1;i<=m;i++)
   {
      char c = idx+'0' ; 
      ans+=c ; 
   }
   
   char c = last+'0' ; 
   string add = "" ;
   add+=c ;  
   for (int i = 0; i < m ; ++i)
   {
      add+='0' ; 
   }
   string final = findSum(ans,add) ;
   cout << final << endl ;
   return 0 ;
}