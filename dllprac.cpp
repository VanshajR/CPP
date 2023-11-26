#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int n)
    {
        data=n;
        next=NULL;
        prev=NULL;
    }
};
class dlinkl
{
    public:
    node* head;
    dlinkl()
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
        head->prev=nn;
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
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        nn->prev=temp;
        temp->next=nn;
    }
    void insafterval(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
            return;
        }
        node* temp=head;
        while(temp->data!=val)
        {
            temp=temp->next;
        }
        nn->prev=temp;
        temp->next=nn;

    }
    void delbeg()
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
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
            temp->next->next->prev=temp;
            node* temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
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
                temp->next->next->prev=temp;
                node* temp1=temp->next;
                temp->next=temp->next->next;
                delete temp1;
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
    void forwardtravel(vector<int> &v)
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        node* temp=head;
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp=temp->next;
        }
    }
    void reversetravel(vector<int> &v)
    {
        if(head==NULL)
        {
            cout<<"Empty";
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            v.push_back(temp->data);
            temp=temp->prev;
        }
    }
};
int main()
{
    dlinkl l;
    l.insend(1);
    l.insend(2);
    l.insend(3);
    l.insend(2);
    l.insend(1);

    vector<int> v1;
    vector<int> v2;
    l.forwardtravel(v1);
    l.reversetravel(v2);
    int i=0,j=0,flag=1;
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i]==v2[j])
        {
            i++;
            j++;
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not a Palindrome";
    }
    return 0;
}