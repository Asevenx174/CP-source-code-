#include<iostream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds ;
using namespace std ;
typedef tree < int , null_type , less <int> , rb_tree_tag , tree_order_statistics_node_update > ordered_set ;
int main()
{
   ordered_set os ;
   os.insert(12);
   os.erase(12);
   if(os.empty()){cout << "YES" << endl;}
  // int ans = os.count() ; /// set er 0/1
   os.clear();///delete all elements
   cout << os.size() << endl; /// size or distinct number
   cout << *os.begin() << endl;/// smallest element
   cout << *os.rbegin() << endl;/// biggest element
   if(os.find(5)==os.end()){cout << "not found" << endl;}
   cout << os.order_of_key(7) << endl;/// 7 er theke chot koeta value ase
   int val = *os.find_by_order(2) ;
   cout << val << endl;/// 2th position a k ase ?? zero base index
   os.erase(val);/// dlt the kth number
   /// erase function value iterator 2 ta send kra jae ,iterator send krle oi position er value dlt hye jabe
   /// 1 2 5 ,7 8
   cout << *os.lower_bound(5) << endl; /// 5 or 5 er boro jto value ase tader mdde smallest ta print kr
   cout << *os.upper_bound(5) << endl; /// 5 er immediate boro value prunt kro
   return 0 ;
}
