#include<bits\stdc++.h>
int cost[100],weight[100],CAP=10;

using namespace std ;
func(int i,int w)
{
    if(i==5+1) //Base Case shob product nea shesh
        return 0;
    int profit1,profit2;
 /// ekhane amra 2ta kaj krbo i'th product nia prer product nibe or i'th product na nia pre product nibo
 /// and ei 2 way te profit count krbo jeita bro hoy oita return krbo
    if(w+weight[i]<=CAP)
    {
        /// ager product er cost nia next product nisi ,
        profit1 = cost[i] + func(i + 1,w + weight[i]);
    }
    else
    {
        profit1=0;/// ntun kre profit hoitese na
    }/// ager product er cost na nia nexr product nisi,s0 weight change kri nai
    profit2=func(i+1,w) ;/// weight kintu change kri nai mane ager product ta nei nai
    return max(profit1,profit2);
}
int main()
{
    for(int i=1; i<=5; i++)
    {
        cin >> weight[i] >> cost[i] ;
    }
    cout << func(1,0) << endl;
    /// intially ami 1st product bag a nib0 and bag ag theke 0 tk er product thakbe
    return 0;
}
/* 5 10  // 5 ta product 10 ta capacity
   1 120
   7 400
   4 280
   3 150
   4 200 */
