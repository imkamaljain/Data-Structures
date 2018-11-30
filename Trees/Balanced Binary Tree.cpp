#include <iostream>
using namespace std;
struct node
{
    node *left,*right;
    int data;
};
node *createnode(int val)
{
    node *n=new node;
    n->left=NULL;
    n->right=NULL;
    n->data=val;
    return n;
}
node *insert(int arr[], int start, int end)
{
    if(start>end)
	    return NULL;
	int mid=(start+end)/2;
	node *root=createnode(arr[mid]);
	root->left=insert(arr,start,mid-1);
	root->right=insert(arr,mid+1,end);
	return root;
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int height(node *root)
{
    if(root==NULL)
        return -1;
    int l=height(root->left);
    int r=height(root->right);
    if(l>r)
        return l+1;
    else
        return r+1;
}
int main()
{
    node *root=NULL;
    int n,i,val;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    root=insert(arr,0,n-1);
    preorder(root);
    cout<<"\nHeight: "<<height(root);
}
