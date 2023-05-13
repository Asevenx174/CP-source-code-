#include<bits\stdc++.h>
using namespace std ;
int arr[100]={1,2,3,4,5},n=5,k=3,num[100];
void combi(int idx,int left)
{
    if(n-idx<left)
    {
        return ;
    }
    if(idx==n)
    {
        for(int i=0;i<k;i++){cout << num[i] << " ";}
        cout << endl ;
        return ;
    }
    if(left)
    {
        num[k-left]=arr[idx];
        combi(idx+1,left-1);
    }
    combi(idx+1,left);
}
int main()
{
    combi(0,k);
    return 0;
}
