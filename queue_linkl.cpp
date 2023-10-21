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
class queue
{
    public:
    int front;
    int rear;
    node* head;
    queue()
    {
        head=NULL;
    }
    void enqueue(int val) //insend
    {
        node* nn = new node(val); 
        node* temp=head;
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            
        }
    }
    void dequeue() //delbeg
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
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.show();
}
