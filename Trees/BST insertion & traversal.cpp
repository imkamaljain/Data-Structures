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
void preorder(node *root)
{
    if (root != NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
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
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    node *root=NULL;
    int n,i,val;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    cout<<"preorder traversal: ";
    preorder(root);
    cout<<"\ninorder traversal: ";
    inorder(root);
    cout<<"\npostorder traversal: ";
    postorder(root);
}
