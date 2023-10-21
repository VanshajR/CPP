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
class stack
{
    public:
    node* head;
    stack()
    {
        head=NULL;
    }
    void push(int val) //insbeg
    {
        node* nn = new node(val);
        nn->next=head;
        head=nn;
    }
    void pop() //delbeg
    {
        head=head->next;
    }
    void show()
    {
        node* temp=head;
        while (temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        
    }
};
int main()
{
    stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    s.show();
}