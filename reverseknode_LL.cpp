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
node* revk(node* &h,int k)
{
    int c=0;
    node* prev=NULL;
    node* next;
    node* temp=h;
    while (temp!=NULL&&c<k)
    {
        c++;
        temp=temp->next;
    }
    if(c>=k)
    {
        c=0;
        temp=h;
        while(temp!=NULL&&c<k)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
            c++;
        }
        if(next!=NULL)
        {
            h->next = revk(next,k);
        }
        return prev;
    }
    else
    {
        return h;
    }
}
node* reverse(node* &h)
{
    node* prev=NULL;
    node* next;
    node* temp=h;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    if(next!=NULL)
    {
        h->next = reverse(next);
    }
    return prev;
}
    // int pass=c/k;
    // for(int i=0;i<pass;i++)
    // {
    //     node* vals[k];
    //     for(int j=0;j<k;j++)
    //     {
    //         cout<<"In j loop\n";
    //         vals[j]=temp1;
    //         cout<<vals[j]->data<<endl;
    //         temp1=temp1->next;
    //     }
    //     node* current=vals[0];
    //     for(int p=1;p<=k;p++)
    //     {   
            
    //         cout<<"In p loop";
    //         // next=current->next;
    //         next=vals[p];
    //         current->next=prev;
    //         prev=current;
    //         current=next;
    //         // current=vals[p];
    //     }

    // }

// }
int main()
{
    linkl l1;
    
    l1.insend(1);
    l1.insend(2);
    l1.insend(3);
    l1.insend(4);
    l1.insend(5);
    l1.insend(6);
    l1.insend(7);
    l1.insend(8);
    
    
    cout<<"\nLL1\n";
    l1.show();
    cout<<"After\n\n";
    node* par=l1.head;
    node* res = reverse(par);
    while (res != NULL)
    {
        cout << res->data;
        if (res->next != NULL)
        {
            cout << "->";
        }
        res = res->next;
    }

    // while(res!=NULL)
    // {
    //     cout<<res->data<<endl;
    // }
    // l1.show();
    return 0;

}
