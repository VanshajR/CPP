#include<iostream>
using namespace std;
class snode
{
    public:
    int data;
    snode* next;
    snode(int val)
    {
        data=val;
        next=NULL;
    }
};
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class dll
{
    public:
    node* head;
    dll()
    {
        head=NULL;
    }

    void insbeg(int val)
    {
        node* nn=new node(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=NULL;
            nn->prev=head;
        }
        else
        {
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
    }
    void insend(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
            nn->prev=head;
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
            head->prev=NULL;
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
            node* temp=head;
            head=NULL;
            delete temp;
        }
        else
        {
            node* temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            delete temp->next;
        }
    }
    void insertat(int pos,int val)
    {
        node* nn=new node(val);
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            node* temp=head;
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            temp->next=nn;
            temp->next->prev=nn;

        }
    }
    void deleval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else if(head->data==val)
        {
            node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete temp;
        }
        else
        {
            node* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            temp->next->next->prev=temp;
            temp->next=temp->next->next;
            delete temp->next;
        }
        
    }
    void insertafter(int val,int pos)
    {
        node* nn=new node(val);
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            node* temp=head;
            for(int i=0;i<pos;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            temp->next=nn;
            temp->next->prev=nn;
        }
    }
    void insertbefore(int val,int pos)
    {
        node* nn=new node(val);
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            node* temp=head;
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            temp->next=nn;
            temp->next->prev=nn;
        }
    }
    void insertafterval(int val,int key)
    {
        node* nn=new node(key);
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
            nn->next=temp->next;
            nn->prev=temp;
            temp->next=nn;
            temp->next->prev=nn;
        }
    }
    void insertbeforeval(int val,int key)
    {
        node* nn=new node(key);
        if(head==NULL)
        {
            head=nn;
        }
        else
        {
            node* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            nn->prev=temp;
            temp->next=nn;
            temp->next->prev=nn;
        }
    }
    void display()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class cll{
    snode* head;
    public:
    cll()
    {
        head=NULL;
    }
    void insbeg(int val)
    {
        snode* nn=new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            nn->next=head;
            snode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=nn;
            head=nn;
        }
    }
    void insend(int val)
    {
        snode* nn=new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->next=head;
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
        }
        else
        {
            snode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head->next;
            temp=head;
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
    void insertat(int pos,int val)
    {
        snode* nn=new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void deleval(int val)
    {
        if(head==NULL)
        {
            cout<<"Empty";
        }
        else if(head->data==val)
        {
            snode* temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=head->next;
            temp=head;
            head=head->next;
            delete temp;
        }
        else
        {
            snode* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
            delete temp->next;
        }
        
    }
    void insertafter(int val,int pos)
    {
        snode* nn=new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            for(int i=0;i<pos;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void insertbefore(int val,int pos)
    {
        snode* nn=new snode(val);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            for(int i=0;i<pos-1;i++)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void insertafterval(int val,int key)
    {
        snode* nn=new snode(key);
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
            temp->next=nn;
            nn->next=temp->next;
        }
    }
    void insertbeforeval(int val,int key)
    {
        snode* nn=new snode(key);
        if(head==NULL)
        {
            head=nn;
            nn->next=head;
        }
        else
        {
            snode* temp=head;
            while(temp->next->data!=val)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void display()
    {
        snode* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<temp->data<<" -> ";
        cout<<endl;
    }
};


int main()
{
    dll l;
    l.insend(1);
    l.insend(2);
    l.insend(3);
    l.insend(4);
    l.insend(5);
    
    cll c;
    c.insend(10);
    c.insend(20);
    c.insend(30);
    c.insend(40);
    c.insend(50);

    l.display();
    cout<<endl;
    c.display();

    int ch1,ch2;
    cout<<"1. DLL/n2.CLL\n"<<endl;
    cout<<"Enter choice: ";
    cin>>ch1;
    if(ch1==1)
    {
        cout<<"1. Insert at beginning\n2. Insert at end\n3. Delete at beginning\n4. Delete at end\n5. Insert at position\n6. Delete at position\n7. Insert after value\n8. Insert before value\n9. Delete value\n10. Display\n"<<endl;
        cin>>ch2;
        switch (ch2)
        {
        case 1:
            int val;
            cout<<"Enter value: ";
            cin>>val;
            l.insbeg(val);
            l.display();
            break;
        case 2:
            int val1;
            cout<<"Enter value: ";
            cin>>val1;
            l.insend(val1);
            l.display();
            break;
        case 3:
            l.delbeg();
            l.display();
            break;
        case 4:
            l.delend();
            l.display();
            break;
        case 5:
            int val2,pos;
            cout<<"Enter value: ";
            cin>>val2;
            cout<<"Enter position: ";
            cin>>pos;
            l.insertat(pos,val2);
            l.display();
            break;
        case 6:
            int pos1;
            cout<<"Enter position: ";
            cin>>pos1;
            l.deleval(pos1);
            l.display();
            break;
        case 7:
            int val3,pos2;
            cout<<"Enter value: ";
            cin>>val3;
            cout<<"Enter value after which to insert: ";
            cin>>pos2;
            l.insertafterval(val3,pos2);
            l.display();
            break;
        case 8:
            int val4,pos3;
            cout<<"Enter value: ";
            cin>>val4;
            cout<<"Enter value before which to insert: ";
            cin>>pos3;
            l.insertbeforeval(val4,pos3);
            l.display();
            break;
        case 9:
            int val5;
            cout<<"Enter value to delete: ";
            cin>>val5;
            l.deleval(val5);
            l.display();
            break;
        case 10:
            l.display();
            break;
        }
    }
    else if(ch1==2)
    {
        cout<<"1. Insert at beginning\n2. Insert at end\n3. Delete at beginning\n4. Delete at end\n5. Insert at position\n6. Delete at position\n7. Insert after value\n8. Insert before value\n9. Delete value\n10. Display\n"<<endl;
        cin>>ch2;
        switch (ch2)
        {
        case 1:
            int val;
            cout<<"Enter value: ";
            cin>>val;
            c.insbeg(val);
            c.display();
            break;
        case 2:
            int val1;
            cout<<"Enter value: ";
            cin>>val1;
            c.insend(val1);
            c.display();
            break;
        case 3:
            c.delbeg();
            c.display();
            break;
        case 4:
            c.delend();
            c.display();
            break;
        case 5:
            int val2,pos;
            cout<<"Enter value: ";
            cin>>val2;
            cout<<"Enter position: ";
            cin>>pos;
            c.insertat(pos,val2);
            c.display();
            break;
        case 6:
            int pos1;
            cout<<"Enter position: ";
            cin>>pos1;
            c.deleval(pos1);
            c.display();
            break;
        case 7:
            int val3,pos2;
            cout<<"Enter value: ";
            cin>>val3;
            cout<<"Enter value after which to insert: ";
            cin>>pos2;
            c.insertafterval(val3,pos2);
            c.display();
            break;
        case 8:
            int val4,pos3;
            cout<<"Enter value: ";
            cin>>val4;
            cout<<"Enter value before which to insert: ";
            cin>>pos3;
            c.insertbeforeval(val4,pos3);
            c.display();
            break;
        case 9:
            int val5;
            cout<<"Enter value to delete: ";
            cin>>val5;
            c.deleval(val5);
            c.display();
            break;
        case 10:
            c.display();
            break;
        }
    }
    l.display();
    c.display();

    return 0;
}