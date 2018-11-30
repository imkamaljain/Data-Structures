#include <iostream>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
};
node *newNode(int val)
{
    node *ptr=new node;
    ptr->data=val;
    ptr->left =NULL;
    ptr->right = NULL;
    return ptr;
}
node* insert(node* node, int val)
{
    if (node == NULL)
      return newNode(val);
    if (val< node->data)
      node->left  = insert(node->left,val);
    else
      node->right = insert(node->right,val);
    return node;
}
int in_count(node* n)
{
  if (n==NULL || (n->left == NULL &&  n->right == NULL))
      return 0;
  return in_count(n->left) + in_count(n->right) + 1;
}
int ex_count(node* n)
{
  if(n==NULL)
      return 0;
  if(n->left == NULL && n->right==NULL)
      return 1;
  else
      return ex_count(n->left)+ ex_count(n->right);
}
int main()
{
    node *root=NULL;
    int n,i,val,in,ex;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    in=in_count(root);
    cout<<"Internal Nodes in tree: "<<in<<endl;
    ex=ex_count(root);
    cout<<"External Nodes in tree: "<<ex;
}
