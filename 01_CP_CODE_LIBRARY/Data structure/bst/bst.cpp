#include<bits\stdc++.h>
using namespace std ;
typedef struct tree ///  tree  struct er name
{
    int num;
    struct tree *left;
    struct tree *right;
} node ;
/// tree num er structure hlo node
node *root=NULL;///just pointer declare kra hoise ,memory allocate kra hoy nai
void insert_node(int value)
{
    node *temp_node ;
    node *parent_node;
    node *current_node;
    temp_node= (node *)malloc(sizeof(node)) ;
    temp_node->num=value;
    temp_node->left=NULL;
    temp_node->right=NULL;
    if(root==NULL)
    {
        root=temp_node; /// root er kintu age mem allocated kra chilo na
    }
    else
    {
          current_node=root;///ekdom root theke shuru krbo
          parent_node=NULL;/// root er parent node to null hbei
          while(1)
          {
              parent_node=current_node;
              if(value<=parent_node->num)
              {
                  current_node=current_node->left;///current node change hoche
                  if(current_node==NULL)
                  {
                      parent_node->left=temp_node;
                      return ;
                  }
              }
              else
              {
                  current_node=current_node->right;
                  if(current_node==NULL)
                  {
                      parent_node->right=temp_node;
                      return  ;
                  }
              }
          }
    }
}
void in_order(node *root_node)
{
    if(root_node==NULL){return;}
    in_order(root_node->left);
    cout << root_node->num << " " ;
    in_order(root_node->right);
}
void pre_order(node *root_node)
{
    if(root_node==NULL){return ;}
    cout << root_node->num << " ";
    pre_order(root_node->left);
    pre_order(root_node->right);
}
void post_order(node *root_node)
{
    if(root_node==NULL){return;}
    post_order(root_node->left);
    post_order(root_node->right);
    cout << root_node->num << " ";
}
void search_tree(int value)
{
    node *current_node=root;
    int flag=0;
    while(1)
    {
        if(value==current_node->num)
        {
            flag=1;
            break;
        }
        else if(value<=current_node->num)
        {
            current_node=current_node->left;
        }
        else
        {
            current_node=current_node->right;
        }
        if(current_node==NULL){break;}
    }
    if(flag==1){cout << "found" << endl;}
    else{cout << "Not found" << endl;}
}
node * maxx(node *root_node)
{
    if(root_node->right==NULL)
    {
        return root_node ;
    }
    maxx(root_node->right);
}
node * minn(node *root_node)
{
    if(root_node==NULL){return root_node;}
    while(root_node->right!=NULL)
    {
        root_node=root_node->left;
    }
    return root_node;
}
int main()
{
    cout << "Number of nodes?" << endl;
    int n;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        int x ;
        cin >> x ;
        insert_node(x);
    }
  /*  cout << "number of query" << endl;
    int q ;
    cin >> q ;
    for(int i=0;i<q;i++)
    {
        int x;
        cin >> x ;
        search_tree(x);
    }
    */
    //pre_order(root);
    node *temp=minn(root);
    cout << temp->num << endl;
    return 0;
}
