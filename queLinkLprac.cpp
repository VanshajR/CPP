#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
class queueLL
{
    public:
    node* front;
    node* rear;
    node* head;
    queueLL()
    {
        front=NULL;
        rear=NULL;
        head=NULL;
    }
    bool isempty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
            front=nn;
            rear=nn;
        }
        else
        {
            rear->next=nn;
            rear=nn;
        }
    }
    void dequeue()
    {
        if(head==NULL)
        {
            cout<<"Underflow";
        }
        else
        {
            node* temp = head;
            head=head->next;
            front=head;
            delete temp;
        }
    }
    int first()
    {
        if(head==NULL)
        {
            cout<<"Underflow";
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    int last()
    {
        if(head==NULL)
        {
            cout<<"Underflow";
            return -1;
        }
        else
        {
            return rear->data;
        }
    }

};