#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int n)
    {
        data=n;
        next=NULL;
    }
};
class stackLL
{
    public:
    node* head;;
    int top;
    stackLL()
    {
        head=NULL;
        top=-1;
    }
    bool isempty()
    {
        if(head==NULL||top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        node* nn = new node(val);
        if(isempty())
        {
            head=nn;
            top++;
        }
        else
        {
            nn->next=head;
            head=nn;
            top++;
        }
    }
    void pop()
    {
        if(head==NULL)
        {
            cout<<"Underflow";
        }
        else
        {
            node* temp=head;
            head=head->next;
            delete temp;
            top--;
        }
    }
    int peek()
    {
        if(isempty())
        {
            return -1;

        }
        else
        {

            return head->data;;
        }
    }
};
int main()
{
    stackLL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    // s.pop();
    // cout<<s.peek();
    return 0;
}

