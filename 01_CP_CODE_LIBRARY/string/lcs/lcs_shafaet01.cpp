#include<bits\stdc++.h>
using namespace std ;
#define MAXC 1000
string A,B;
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
int calcLCS(int i,int j)
{
    if(A[i]=='\0' or B[j]=='\0')///base case
        return 0;
    if(visited[i][j])///dp
        return dp[i][j];

    int ans=0;
    if(A[i]==B[j])
        ans=1+calcLCS(i+1,j+1);///1 jog kre next state a chole gelam
    else
    {
        int val1=calcLCS(i+1,j);
        int val2=calcLCS(i,j+1);
        ans=max(val1,val2);///2 ta option er mdde best ta nitesi
    }
    visited[i][j]=1;///visited true kre nilam
    dp[i][j]=ans;
    return dp[i][j];
}
int main()
{
    cin >> A >> B ;
    lenA= A.size();
    lenB=B.size();
    printf("%d\n",calcLCS(0,0));
    return 0;

}
