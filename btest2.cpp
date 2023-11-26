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
node* makeTree(int preord[],int inord[], int start, int end)
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
    nn->left = makeTree(preord,inord,start,pos-1);
    nn->right = makeTree(preord,inord,pos+1,end);
}
int main(){
    int preord[]={1,2,3,4,5};
    int inord[]={4,2,1,5,3};
    node* root=makeTree(preord,inord,0,4);
    inorder(root);
    return 0;

}