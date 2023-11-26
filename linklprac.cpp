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
class linkl
{
    public:
    node* head;
    linkl()
    {
        head=NULL;
    }
    void insbeg(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
            return;
        }
        nn->next=head;
        head=nn;
    }
    void insend(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
            return;
        }
        else
        {
            node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
    void insafterval(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            node* temp=head;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
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
            node* temp=head;
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
        else if(head->next==NULL)
        {
            head=NULL;
            delete head;
        }
        else
        {
            node* temp =head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            delete temp->next;
        }
    }
    void delval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else if(head->data==val)
        {
            node* temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            node* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        
    }
    void search(int val)
    {
        int count=0;
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==val)
            {
                count++;
            }
            temp=temp->next;
        }
        if(count==0)
        {
            cout<<"Not found";
        }
        else
        {
            cout<<"Found at "<<count<<" position";
        }

    }
    void countdel(int val)
    {
        int count=0;
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        if(head->data==val)
        {
            node* temp=head;
            head=head->next;
            delete temp;
        }
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->next->data==val)
            {
                count++;
                temp->next=temp->next->next;
            }
            temp=temp->next;
        }
        cout<<"Deleted "<<count<<"occurences\n";
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
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