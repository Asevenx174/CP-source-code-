#include <bits/stdc++.h>
using namespace std ;
const int maxx = 110 ; 
int dp[maxx+5][maxx+5] ; 
int main()
{
	string s1,s2 ;
	cin >> s1 >> s2 ; 
	int n = s1.size() , m = s2.size() ; 
	for (int i = 0; i < n ; ++i)
	{
		for (int j = 0; j < m ; ++j )
		{
			if(s[i]==s[j])
			{
				dp[i+1][j+1] = dp[i][j]+1 ; 
			}
			else
			{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]) ;
			}
		}
	}
	return 0;
}