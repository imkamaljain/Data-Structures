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
int height(node *root)
{
    if(root==NULL)
       return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if(leftHeight>rightHeight)
      return leftHeight+1;
    else
      return rightHeight+1;
}
int main()
{
    node *root=NULL;
    int n,i,val,h;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    h=height(root);
    cout<<"Height of tree: "<<h;
}
