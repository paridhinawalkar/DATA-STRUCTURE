#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Binarytree
{
public :
    Node* insert(Node* root,int val)
    {
        if(root==nullptr)
        {
            return new Node(val);
        }
        if(val < root->data)
        {
            root->left=insert(root->left, val);
        }
        else
        {
             root->right=insert(root->right,val);
        }
        return root;
    }

    void inorder(Node* root)
    {
        if(root==nullptr)return;
        inorder(root->left);
       cout<<root->data<<"  ";
        inorder(root->right);
    }

    void preorder(Node* root)
    {
         if(root==nullptr)return;
        cout<<root->data<<"  ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root)
    {
         if(root==nullptr)return;
        postorder(root->left);
        postorder(root->right);
       cout<<root->data<<"  ";
    }
};
int main()
{
          Binarytree tree;
          Node* root=nullptr;
          int n,t,i;
          cout<<"Enter no. of Nodes : ";
          cin>>n;
           cout<<"Enter the Nodes : ";
          for(i=0;i<n;i++)
          {
              cin>>t;
              root=tree.insert(root,t);
          }
         cout<<"Inorder traversal : ";
         tree.inorder(root);
         cout<<endl;

         cout<<"Preorder traversal : ";
         tree.preorder(root);
         cout<<endl;

         cout<<"Postorder traversal : ";
         tree.postorder(root);
         cout<<endl;
}
