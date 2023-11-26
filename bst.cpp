#include<iostream>
using namespace std;
class node{
	public:
		node* left;
		node* right;
		int data;
		node(int d)
		{
			data=d;
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
    else if(root->data<key)
    {
        return search_r(root->right,key);
    }
    else{
        return search_r(root->left,key);
    }
}

node* search_i(node* root,int key)
{
    while(root!=NULL){
	    if(root->data==key)
	    {
	        return root;
	    }
	    else if(root->data<key)
	    {
	        root=root->right;
	    }
	    else{
	        root=root->left;
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

void inorder(node* root)
{
    node* c=root;
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void insert(node* root,int key)
{
    node* prev=NULL;
	node* nn = new node(key);
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
            cout<<"Cannot insert since "<<key<<" is already in tree";
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
    if(key<prev->data)
    {
        prev->left=nn;
    }
    else
    {
        prev->right=nn;
    }

}

node* inorderpred(node* root)
{
    root=root->left;
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

node* inordersucc(node* root)
{
    root=root->right;
    while (root->left!=NULL)
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
    //search node
    if(key<root->data)
    {
        root->left=delnode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=delnode(root->right,key);
    }
    else //node found
    {
        //if leaf node or single child
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            node* temp=root->left;
            free(root);
            return temp;
        }
        else //if both children exist
        {
            // node* pred=inorderpred(root);
            // root->data=pred->data;
            // root->left=delnode(root->left,pred->data);

            node* succ=inordersucc(root);
            root->data=succ->data;
            root->right=delnode(root->right,succ->data);
        }

    }
}

int main()
{
    node *root = new node(5);
    node *p1 = new node(3);
    node *p2 = new node(6);
    node *p3 = new node(1);
    node *p4 = new node(4);

    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;

    // node* n1 = search_r(root,4);
    // if(n1!=NULL)
    // {
    //     cout<<"Found: "<<n1->data<<endl;
    // }
    // else
    // {
    //     cout<<"element not found\n";
    // }
    
    // node* n2 = search_r(root,8);
    // if(n2!=NULL)
    // {
    //     cout<<"Found: "<<n2->data<<endl;
    // }
    // else
    // {
    //     cout<<"element not found\n";
    // }

    insert(root,7);
    cout<<root->right->right->data<<endl;
    inorder(root);
    cout<<"\n";
    delnode(root,3);
    root=delnode(root,3);
    inorder(root);



}
