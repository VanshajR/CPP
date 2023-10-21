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
        node* nn= new node(val);
        nn->next=head;
        head=nn;

    }
    void insend(int val)
    {
        node* nn = new node(val);
        if(head==NULL)
        {
            head=nn;
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
    void delbeg()
    {
        if(head==NULL)
        cout<<"Empty"; 
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
        cout<<"Empty";
        else if(head->next==NULL)
        {
            delete head;
            head=NULL;
        }
        else
        {
            node* temp=head;
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;

        }
    }
    void insafterval(int key, int val)
    {
        node* nn= new node(val);
        if(head==NULL)
        {
            insbeg(val);
            cout<<"Empty list, inserted at beginning";
        }
        else
        {
            node* temp=head;
            while(temp->next!=NULL&&temp->data!=key)
            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"Element not found";
            }
            else
            {
                nn->next=temp->next;
                temp->next = nn ;
            }
        }
    }
    //     void delafterval(int key)
    // {
    //     if(head==NULL)
    //     {
    //         cout<<"Empty list";
    //     }
    //     else
    //     {
    //         node* temp=head;
    //         node* store=NULL;
    //         while(temp->next!=NULL&&temp->data!=key)
    //         {
    //             store=temp;
    //             temp=temp->next;
    //         }
    //         if(temp==NULL)
    //         {
    //             cout<<"Element not found";
    //         }
    //         else if (temp->next==NULL)
    //         {
    //             store->next=NULL;
    //         }
            
    //         else
    //         {
    //             store->next=temp->next;
    //         }
    //     }
    // }
    void insafternode(node* nn)
    {
        if(head==NULL)
        {
            head=nn;
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
    void show()
    {
        node* temp=head;
        if (temp==NULL)
        {
            cout<<"Empty";
        }
        else
        {
        
        while (temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL)
            {cout<<"->";}
            
            
        }
        
        }
        
    }
};
void createLL3(linkl& LL1, linkl& LL2, linkl& LL3) {
    node* temp_1 = LL1.head;
    node* temp_2 = LL2.head;
    node* p,*q;
    p=temp_1;
    q=temp_2;
    
    while (temp_1 != NULL && temp_2 != NULL) {
        if (temp_1->data == temp_2->data) {
            LL3.insend(temp_1->data);
            LL3.insend(temp_2->data);
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
            p->next=p->next->next;
            q->next=q->next->next;
        }
        if (temp_1->data < temp_2->data) {
            temp_1 = temp_1->next;
        }
        else {
            temp_2 = temp_2->next;
        }
    }
}
int main()
{
    linkl l1;
    linkl l2;
    linkl l3;
    l1.insend(1);
    l1.insend(3);
    l1.insend(4);
    l1.insend(5);
    l1.insend(6);
    l1.insend(7);
    
    l2.insend(2);
    l2.insend(4);
    l2.insend(6);
    l2.insend(8);

    node* temp_1 = l1.head;
    node* temp_2 = l2.head;
    cout<<temp_1->data<<"t1\n";
    cout<<temp_2->data<<"t2\n";
    if(temp_1->next!=NULL)
    cout<<"t1 valid\n";
    if(temp_2->next!=NULL)
    cout<<"t2 valid\n";
    // while(temp_1->next!=NULL&&temp_2->next!=NULL)
    // {
    //     l3.show();
        
    //     cout<<"In while\n";
    //     if(temp_1->data==temp_2->data)
    //     {
    //         cout<<"In and before\n";
    //         l3.insafternode(temp_1);
    //         cout<<"In and after t1\n";
    //         l3.insafternode(temp_2);
    //         cout<<"In and after t2\n";
            
    //         temp_1->next=temp_1->next->next;
    //         temp_2->next=temp_2->next->next;
    //         cout<<"After link forwarding\n";
    //     }
    //     if(temp_1->next!=NULL)
    //     temp_1=temp_1->next;
    //     if(temp_2->next!=NULL)
    //     temp_2=temp_2->next;
    //     l3.show();
        
    // }
    createLL3(l1,l2,l3);
    cout<<"\nLL1\n";
    l1.show();
    cout<<"\nLL2\n";
    l2.show();
    cout<<"\nLL3\n";
    l3.show();

    return 0;

}
