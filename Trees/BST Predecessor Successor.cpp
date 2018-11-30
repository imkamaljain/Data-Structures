#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
struct node *newnode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root,int data)
{
    if(root == NULL)
        return(newnode(data));
    else if(data < root->data)
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);
    return root;
}
void findpresuc(node *root,node *&pre,node *&suc,int key)
{
    if(root == NULL)
        return;
    if(root->data == key)
    {
        if(root->left != NULL)
        {
            node *temp = root->left;
            while(temp->right)
            temp = temp->right;
            pre = temp;
        }
        if(root->right != NULL)
        {
            node *temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }
    if(root->data < key)
    {
        pre = root;
        findpresuc(root->right,pre,suc,key);
    }
    else
    {
        suc = root;
        findpresuc(root->left,pre,suc,key);
    }
}
int main()
{
    struct node *root = NULL,*pre = NULL,*suc = NULL;
    int n,x,key;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>x;
        root = insert(root,x);
    }
    cin>>key;
    findpresuc(root,pre,suc,key);
    if(pre != NULL)
        cout<<"predecessor :"<<pre->data<<endl;
    else
        cout<<"No predecessor"<<endl;
    if(suc != NULL)
        cout<<"successor :"<<suc->data<<endl;
    else
        cout<<"No successor"<<endl;
}
