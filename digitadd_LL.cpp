#include<iostream>
using namespace std;
#include<cmath>
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
            cout<<"Empty\n";
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
    linkl copyLL1 = LL1; // Make a copy of LL1
    linkl copyLL2 = LL2; // Make a copy of LL2
    node* temp_1 = copyLL1.head;
    node* temp_2 = copyLL2.head;
    node* p,*q;
    int c1=0;
    int c2=0;
    int num1=0;
    int num2=0;

    while(temp_1!=NULL)
    {
        c1++;
        temp_1=temp_1->next;
    }
    while(temp_2!=NULL)
    {
        c2++;
        temp_2=temp_2->next;
    }
    int p1=c1-1;
    int p2=c2-1;
    cout<<"p1: "<<p1<<"p2: "<<p2<<endl;
    temp_1 = copyLL1.head;
    temp_2 = copyLL2.head;
    while (temp_1!=NULL)
    {
        cout<<pow(10,p1)<<"  "<<temp_1->data*((pow(10,p1)))<<endl;
        num1+=(temp_1->data)*(pow(10,p1));
        cout<<num1<<endl;
        p1--;
        temp_1=temp_1->next;
    }
    while (temp_2!=NULL)
    {
        num2+=(temp_2->data)*(pow(10,p2));
        cout<<num2<<endl;
        p2--;
        temp_2=temp_2->next;
    }
    int res = num1+num2;
    int c3=0;
    while(res!=0)
    {
        c3++;
        res=res/10;
    }
    

    // int c3=c1>c2?c1:c2;
    cout<<"c3: "<<c3<<endl;
    // cout<<c3<<endl;
    while (c3>0)
    {
        int div=pow(10,(c3-1));
        int pass = res/div;
        LL3.insend(pass);
        res = res % div;
        c3--;
    }
    cout<<"n1: "<<num1<<" num2: "<<num2<<endl;
    cout<<"c3: "<<c3<<endl;
     
}
int main()
{
    linkl l1;
    linkl l2;
    linkl l3;
    
    l1.insend(1);
    l1.insend(2);
    l1.insend(3);
    // l1.insend(4);
    l1.insend(5);
    l1.insend(7);
    

    l2.insend(4);
    l2.insend(5);
    l2.insend(9);
    cout<<"\nLL1\n";
    l1.show();
    cout<<"\nLL2\n";
    l2.show();
    cout<<"\nLL3\n";
    createLL3(l1,l2,l3);
    l3.show();    
    return 0;

}
//YE VS CODE CHUTIYA HAI CODE SAHI HAI!!!!!!!!