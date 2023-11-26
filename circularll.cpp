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
        else
        {
            snode* temp=head;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
            snode* temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
        }
        
    }
    void delval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else
        {
            snode* temp = head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            snode* temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
        }
    }
    void search(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        snode* temp = head;
        while(temp->next!=head)
        {
            if(temp->data==val)
            {
                cout<<"Found";
                return;
            }
            temp=temp->next;
        }
        
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        snode* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }
    void checks()
    {
        int flag=0;
        snode* temp=head;
        while(temp!=NULL)
        {
            if(temp->next==head)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if (flag==1)
        {
            cout<<"Circular Linked List";
        }
        else if (flag==0)
        {
            cout<<"Not a Circular Linked List";
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
    void insbeg(int val)
    {
        dnode* nn = new dnode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
            nn->prev=head;
        }
        else
        {
            dnode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            nn->next=head;
            nn->prev=head->prev;
            temp->next=nn;
            head->prev=nn;
            head=nn;
        }
    }
    void insend(int val)
    {
        dnode* nn = new dnode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
            nn->prev=head;
        }
        else
        {
            dnode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            nn->next=head;
            nn->prev=temp;
            temp->next=nn;
            head->prev=nn;
        }
    }
    void insafterval(int val)
    {
        dnode* nn = new dnode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
            nn->prev=head;
        }
        else
        {
            dnode* temp=head;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            temp->next->next->prev=nn;
        }
    }
    void delbeg()
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
            dnode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head->next;
            head->next->prev=temp;
            delete head;
            head=temp->next;
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
            dnode* temp = head;
            while(temp->next->next!=head)
            {
                temp=temp->next;
            }
            dnode* temp1=temp->next;
            temp->next=head;
            head->prev=temp;
            delete temp1;
        }
    }
    void delafterval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else
        {
            dnode* temp=head;
            while(temp->data!=val)
            {
                temp=temp->next;
            }
            dnode* temp1=temp->next;
            temp->next=temp->next->next;
            temp->next->prev=temp;
            delete temp1;
        }
    }
    void delval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else
        {
            dnode* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            // temp->next->next->prev=temp;
            dnode* temp1=temp->next;
            temp->next=temp->next->next;
            temp->next->prev=temp;
            delete temp1;
        }
    }
    void search(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        dnode* temp = head;
        while(temp->next!=head)
        {
            if(temp->data==val)
            {
                cout<<"Found";
                return;
            }
            temp=temp->next;
        }
        
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        dnode* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }
    void checkd()
    {
        int flag=0;
        dnode* temp=head;
        while(temp!=NULL)
        {
            if(temp->next==head)
            {
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if (flag==1)
        {
            cout<<"Circular Linked List";
        }
        else if (flag==0)
        {
            cout<<"Not a Circular Linked List";
        }
    }
    

};


int main()
{
    sclinkl s;
    s.insend(1);
    s.insend(2);
    s.insend(3);
    dclinkl d;
    d.insend(1);
    d.insend(2);
    d.insend(3);
    s.checks();
    d.checkd();
    return 0;
}