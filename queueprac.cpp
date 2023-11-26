#include<iostream>
#include<vector>    
using namespace std;
#define maxlen 100
class queue
{
    public:
    int front;
    int rear;
    int element[maxlen];
    queue()
    {
        front=-1;
        rear=-1;
    }
    bool isFull()
    {
        return rear==maxlen-1;
    }
    bool isEmpty()
    {
        if(front==-1||front>rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return rear-front+1;
    }
    int peek()
    {
        if(isEmpty())
        {
            return -1;
        }
        else
        {
            return element[front];
        }
    }
    int enqueue(int x)
    {
        if(isFull())
        {
            cout<<"Full";
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
            element[rear]=x;
        }
        else
        {
            rear++;
            element[rear]=x;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Empty";
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
    void show()
    {
        if(isEmpty())
        {
            cout<<"Empty";
        }
        else
        {
            for(int i=front;i<=rear;i++)
            {
                cout<<element[i]<<" ";
            }
        }
    }
};
void interleave(queue &q)
{
    int n=q.size();
    int half=n/2;
    queue q1,q2;
    for(int i=0;i<half;i++)
    {
        q1.enqueue(q.peek());
        q.dequeue();
    }
    for(int i=half;i<n;i++)
    {
        q2.enqueue(q.peek());
        q.dequeue();
    }
    q1.show();
    cout<<endl;
    q2.show();
    cout<<endl;
    int i=0;
    while(!q1.isEmpty()&&!q2.isEmpty())
    {
        if(i%2==0)
        {
            q.enqueue(q1.peek());
            q1.dequeue();
        }
        else
        {
            q.enqueue(q2.peek());
            q2.dequeue();
        }
        i++;
    }
    while(!q1.isEmpty())
    {
        q.enqueue(q1.peek());
        q1.dequeue();
    }
    while(!q2.isEmpty())
    {
        q.enqueue(q2.peek());
        q2.dequeue();
    }
    q.show();

}
int main()
{
    queue q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);
    q.show();
    cout<<endl;
    interleave(q);

    // int ch;
    // cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Size\n5. Show\n6. Exit\n";
    // cin>>ch;
    // switch(ch)
    // {
    //     case 1:
    //     {
    //         int x;
    //         cout<<"Enter element to enqueue: ";
    //         cin>>x;
    //         q.enqueue(x);
    //         break;
    //     }
    //     case 2:
    //     {
    //         q.dequeue();
    //         break;
    //     }
    //     case 3:
    //     {
    //         cout<<q.peek();
    //         break;
    //     }
    //     case 4:
    //     {
    //         cout<<q.size();
    //         break;
    //     }
    //     case 5:
    //     {
    //         q.show();
    //         break;
    //     }
    //     case 6:
    //     {
    //         exit(0);
    //     }
    // }
    return 0;
}
