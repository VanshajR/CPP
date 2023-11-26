#include<iostream>
#include<stack>
using namespace std;
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
node* search_r(node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        return search_r(root->left,key);
    }
    else
    {
        return search_r(root->right,key);
    }
}
node* search_i(node* root,int key)
{
    while(root!=NULL)
    {
        if(root->data==key)
        {
            return root;
        }
        else if(root->data>key)
        {
            return root->left;
        }
        else
        {
            return root->right;
        }
    }
    return NULL;
}

void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

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

void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void insert(node* root,int key)
{
    node* prev=NULL;
    node* nn=new node(key);
    while(root!=NULL)
    {
        prev=root;
        if(root->data==key)
        {
            cout<<"Cannot insert duplicate key"<<endl;
            return;
        }
        else if(root->data<key)
        {
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    if(prev->data<key)
    {
        prev->right=nn;
    }
    else
    {
        prev->left=nn;
    }
}

node* inorderpred(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

node* inordersucc(node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    root=root->right;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* delnode(node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left = delnode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right = delnode(root->right,key);
    }
    else
    {   
        //leaf node or single child
        if(root->left==NULL)
        {
            node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        // using predecessor
        // node* pred = inorderpred(root);
        // root->data=pred->data;
        // root->left=delnode(root->left,pred->data);

        //using successor
        node* succ = inordersucc(root);
        root->data=succ->data;
        root->right=delnode(root->right,succ->data);
        
    }
}

int minval(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}

int maxval(node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}

int maxdeapth(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ldeapth=maxdeapth(root->left);
    int rdeapth=maxdeapth(root->right);
    return max(ldeapth,rdeapth)+1;
}

int mindeapth(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ldeapth=mindeapth(root->left);
    int rdeapth=mindeapth(root->right);
    if(root->left==NULL)
    {
        return rdeapth+1;
    }
    if(root->right==NULL)
    {
        return ldeapth+1;
    }
    return min(ldeapth,rdeapth)+1;
}

void inorderwithoutrecursion(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>s;
    node* temp=root;
    while(temp!=NULL || !s.empty())
    {
        if(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        else
        {
            temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
        }
    }
}

void preorderwithoutrecursion(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            s.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            s.push(temp->right);
        }
    }
}

void postorderwithoutrecursion(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*>s;
    stack<node*>out;  
    s.push(root);
    while(!s.empty())
    {
        node* temp=s.top();
        s.pop();
        out.push(temp);
        if(temp->left!=NULL)
        {
            s.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            s.push(temp->right);
        }
    }
    while(!out.empty())
    {
        node* temp=out.top();
        out.pop();
        cout<<temp->data<<" ";
    }   
}
int search(int inord[],int start,int end,int key)
{
    for(int i=start;i<=end;i++)
    {
        if(inord[i]==key)
        {
            return i;
        }
    }
    return -1;
}
node* makeTreePreIn(int preord[],int inord[], int start, int end)
{
    static int index=0;
    if(start>end)
    {
        return NULL;
    }
    int curr = preord[index];
    index++;
    node* nn = new node(curr);
    if(start==end)
    {
        return nn;
    }
    int pos = search(inord,start,end,curr);
    nn->left = makeTreePreIn(preord,inord,start,pos-1);
    nn->right = makeTreePreIn(preord,inord,pos+1,end);
}
node* makeTreePostIn(int postord[],int inord[], int start, int end,int size)
{
    static int index=size-1;
    if(start>end)
    {
        return NULL;
    }
    int curr = postord[index];
    index--;
    node* nn = new node(curr);
    if(start==end)
    {
        return nn;
    }
    int pos = search(inord,start,end,curr);
    nn->right = makeTreePostIn(postord,inord,pos+1,end,size);
    nn->left = makeTreePostIn(postord,inord,start,pos-1,size);
}
int main()
{
    // node *root = new node(5);
    // node *p1 = new node(3);
    // node *p2 = new node(6);
    // node *p3 = new node(1);
    // node *p4 = new node(4);

    // root->left=p1;
    // root->right=p2;
    // p1->left=p3;
    // p1->right=p4;
    
    // insert(root,7);
    // cout<<root->right->right->data<<endl;
    // inorder(root);
    // cout<<"\n";
    // root=delnode(root,3);
    // root=delnode(root,7);
    // cout<<"Final Preorder:";
    // preorder(root);
    // cout<<"\n";
    // cout<<"Final Inorder:";
    // inorder(root);
    // cout<<"\n";
    // cout<<"Final Postorder:";
    // postorder(root);
    // cout<<"\n";
    // cout<<"Min value:"<<minval(root)<<endl;
    // cout<<"Max value:"<<maxval(root)<<endl;
    // cout<<"Max deapth:"<<maxdeapth(root)<<endl;
    // cout<<"Min deapth:"<<mindeapth(root)<<endl;

    int preord[]={1,2,4,3,5};
    int inord[]={4,2,1,5,3};
    node* root=makeTreePreIn(preord,inord,0,4);
    inorder(root);
    cout<<"\n";
    node* root1=makeTreePostIn(preord,inord,0,4,5);
    inorder(root1);
    return 0;

}