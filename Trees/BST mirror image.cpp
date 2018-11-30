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
void mirror(node* n)
{
    if (n==NULL)
        return;
    else
    {
        mirror(n->left);
        mirror(n->right);
        swap(n->left,n->right);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
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
    cout<<"inorder traversal: ";
    inorder(root);
    mirror(root);
    cout<<"\ninorder traversal after mirroring: ";
    inorder(root);
}
