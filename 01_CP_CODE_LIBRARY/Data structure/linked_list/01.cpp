#include<bits\stdc++.h>
using namespace std ;
struct linked_list
{
    int number ;
    linked_list *next ;
};
typedef struct linked_list node ;
void create(node *linked_list)
{
    cout << "input node value , to end type 99999" << endl;
    cin >> linked_list->number;
    if(linked_list->number==99999)
    {
        linked_list->next=NULL;
    }
    else
    {
        linked_list->next= (node *)malloc(sizeof(node));
        create(linked_list->next);
    }
}
void print(node *head)
{
    cout << head->number << " " ;
    if(head->next==NULL){return ;}
    print(head->next);
}
int freq(node *head)
{
    if(head->next==NULL){return 0;}
    return (1+freq(head->next));
}
int main()
{
    node *head;
    head = (node *)malloc(sizeof(node));
    create(head);
   // print(head);
    //cout << freq(head) << endl;
    return 0;
}
