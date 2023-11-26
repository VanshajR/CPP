#include<iostream>
#include<vector>
using namespace std;
class dllnode
{
    public:
        int data;
        dllnode* next;
        dllnode* prev;
        dllnode(int x)
        {
            data=x;
            next=NULL;
            prev=NULL;
        }
};
class node
{
    public:
        int data;
        node* left;
        node* right;
        node(int x)
        {
            data=x;
            left=NULL;
            right=NULL;
        }
};

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorderelements(node* root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorderelements(root->left,v);
    v.push_back(root->data);
    inorderelements(root->right,v);
}

int main()
{
    node* root1=new node(20);
    node* l1=new node(10);
    node * r1=new node(30);
    node* r1l=new node(25);
    node* r1r=new node(100);

    root1->left=l1;
    root1->right=r1;
    r1->left=r1l;
    r1->right=r1r;

    node* root2=new node(50);
    root2->left=new node(5);
    root2->right=new node(70);

    inorder(root1);
    cout<<endl;
    inorder(root2);
    cout<<endl;

    vector<int> v1,v2;
    inorderelements(root1,v1);
    inorderelements(root2,v2);

    vector<int> result;
    cout<<endl;
    cout<<"v1: ";
    for(int i : v1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"v2: ";
    for(int i : v2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    int i=0,j=0;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            result.push_back(v1[i++]);
        }
        else if(v1[i]>v2[j])
        {
            result.push_back(v2[j++]);
        }
    }
    while(i<v1.size())
    {
        result.push_back(v1[i++]);
    }
    while(j<v2.size())
    {
        result.push_back(v2[j++]);
    }
    for(int i : result)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    dllnode* temp=NULL;
    dllnode* head=NULL;
    for(int i : result)
    {
        dllnode* nn=new dllnode(i);
        if(!head)
        {
            head=nn;
        }
        else
        {
            temp->next=nn;
            nn->prev=temp;
        }
        temp=nn;
    }
    while(head)
    {
        cout<<head->data<<" <-> ";
        head=head->next;
        if(head==NULL)
        {
            cout<<"NULL";
        }
    }
    return 0;
}