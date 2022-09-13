#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * left, * right;
    Node()
    {
        left = NULL; right = NULL;
    }
    Node(int x)
    {
        data = x; left = NULL; right = NULL;
    }
};
Node * maxp(Node* root)
{
    if(root->right==NULL)
    return root;
    else
    return maxp(root->right);
}
class BST
{
    public:
    Node * insert(Node* root,int data)
    {
        if(!root)
        return new Node(data);
        else if(data<root->data)
        root->left = insert(root->left,data);
        else
        root->right = insert(root->right,data);
	   return root;
    }
    void search(Node * root,int data)
    {
        if (root->data == data) 
            cout<<"found";
        else if(root ==NULL)
            cout<<"Not found";
        else if (root->data < data) 
            search(root->right, data); 
        else search(root->left, data); 
    }
    void inorder(Node* root)
    {
        if(root)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    Node* Deletion(Node * root, int data)
    {
        Node * temp;
        if(root==NULL)
        cout<<"Not found";
        else if(data>root->data)
        root->right = Deletion(root->right,data);
        else if(data < root->data)
        root->left = Deletion(root->left,data);
        else if(root->left && root->right)
        {
            temp = maxp(root->left);
            root->data= temp->data;
            root->left = Deletion(root->left,temp->data);
        }
        else
        {
            temp = root;
            if(root->left){
            root=root->left; delete temp;}
            else if(root->right){
            root = root->right; delete temp;}
            else
            {
                delete temp;
                return NULL;
            }
        }
        return root;
    }
    int height(Node* root)
    {
        int l=-1,r=-1;
        if(root->left)
        l = height(root->left);
        if(root->right)
        r = height(root->right);
        return max(l,r)+1;
    }
    // makeAVL(Node* root)
    // {
        
    // }
};
int main()
{
    Node * root,*r;
    BST creater;
    root = creater.insert(root,5);
    creater.insert(root,20);
    creater.insert(root,3);
    creater.insert(root,9);
    creater.insert(root,18);
    creater.insert(root,15);creater.insert(root,10);
    creater.inorder(root); cout<<endl;
    root = creater.Deletion(root,18);
    creater.inorder(root);
    
}

