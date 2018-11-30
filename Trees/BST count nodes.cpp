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
int count(node* n)
{
    int c = 1;
    if (n == NULL)
        return 0;
    else
    {
        c+=count(n->left)+count(n->right);
        return c;
    }
}
int main()
{
    node *root=NULL;
    int n,i,val,min,max;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    n=count(root);
    cout<<"Nodes in tree: "<<n;
}
