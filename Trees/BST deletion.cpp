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
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node *inorderSucc(node* n)
{
    node *ptr= n;
    while (ptr->left != NULL)
        ptr=ptr->left;
    return ptr;
}
node* deleteNode(node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *succ =inorderSucc(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right,succ->data);
    }
    return root;
}
int main()
{
    node *root=NULL;
    int n,i,val,del;
    cout<<"Enter no. of nodes: ";
    cin>>n;
    cout<<"Enter values: ";
    for(i=0;i<n;i++)
    {
        cin>>val;
        root=insert(root,val);
    }
    cout<<"Tree : ";
    inorder(root);
    cout<<"\nEnter node to delete: ";
    cin>>del;
    root=deleteNode(root,del);
    cout<<"\nModified tree: ";
    inorder(root);
}
