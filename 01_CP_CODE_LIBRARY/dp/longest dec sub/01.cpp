#include<iostream>
#include<climits>
using namespace std ;
int len(int arr[],int n,int i,int prev)
{
    /// for every i'th element of arr[]
    ///there r 2 option
    /// take i'th element if arr[i]<prev elemnt
    /// else recur for rest of the element
    int op1=0,op2=0;
    if(n==i){return 0;}
    op1=len(arr,n,i+1,prev);///i'th element ta nilam na
    if(arr[i]<prev)
    {
        op2=1+len(arr,n,i+1,arr[i]);/// i'th element ta nisi
    }
    return max(op1,op2);
}
int main()
{
    int arr[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << len(arr,n,0,INT_MAX) << endl;
}
