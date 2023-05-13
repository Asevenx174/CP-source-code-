#include<iostream>
using namespace std ;
int binary(int arr[],int n,int findd)
{
    int left,right,mid;
    left=0;
    right= n-1;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(findd==arr[mid])
        {
            return mid ;
        }
        else if(findd>arr[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return -1 ;
}
int main()
{
    int arr[10000],n,findd;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i] ;
    }
    cin >> findd;
    int result = binary(arr,n,findd);
    if(result==-1)
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        cout << " found = " << result << endl;
    }
    return 0;
}
