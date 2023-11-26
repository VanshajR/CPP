#include<iostream>
using namespace std;
class snode
{
    public:
    int data;
    snode* next;
    snode(int n)
    {
        data=n;
        next=NULL;
    }
};

class dnode
{
    public:
    int data;
    dnode* next;
    dnode* prev;
    dnode(int n)
    {
        data=n;
        next=NULL;
        prev=NULL;
    }
};

class sclinkl
{
    public:
    snode* head;
    sclinkl()
    {
        head=NULL;
    }
    void insbeg(int val)
    {
        snode* nn = new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        snode* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        nn->next=head;
        temp->next=nn;
        head=nn;
    }
    void insend(int val)
    {
        snode* nn = new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        snode* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->next=head;
    }
    void insafterval(int val)
    {
        snode* nn = new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void delbeg()
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else
        {
            snode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head->next;
            head=head->next;
            delete temp;
        }
    
    }
    void delend()
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else if(head->next==head)
        {
            delete head;
            head=NULL;
        }
        else
        {
            snode* temp=head;
            while(temp->next->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head;
            delete temp->next;
        }
    }
    void delafterval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        
    }
    
};

class dclinkl
{
    public:
    dnode* head;
    dclinkl()
    {
        head=NULL;
    }
};
int main()
{
    linkl l;
    l.insend(1);
    l.insend(2);
    l.insend(1);
    l.insend(2);
    l.insend(1);
    l.insend(3);
    l.insend(1);

    l.countdel(1);
    l.display();
}