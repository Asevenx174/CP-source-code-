#include<bits\stdc++.h>
using namespace std ;
int arr[100]={1,2,3,4,5},k=3,num[100],n=5,used[100];
void combi(int idx,int last)
{
    if(idx==k)
    {
        for(int i=0;i<k;i++){cout << num[i] << " ";}
        cout << endl; return ;
    }
    for(int i=last+1;i<=n-k+idx+1;i++)
    {
        num[idx]=i;
        combi(idx+1,i);
    }
}
int main()
{
    combi(0,0);
    return 0;
}
