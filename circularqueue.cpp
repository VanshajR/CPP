#include<iostream>
using namespace std;
#define maxlen 100
class cq
{
    public:
    int front;
    int rear;
    int element[maxlen];
    cq()
    {
        front=-1;
        rear=-1;
    }
    bool isFull()
    {
        return ((rear+1)%maxlen==front);
    }
    bool isEmpty()
    {
        if(front==-1&&rear==-1)
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
        return (rear-front+1);
    }
    void enqueue(int x)
    {
        if(((rear+1)%maxlen==front))
        {
            cout<<"Full";
        }
        else
        {
            if(front==-1)
            {
                front=0;
            }
            rear=(rear+1)%maxlen;
            element[rear]=x;
        }
    }
    void dequeue()
    {
        if(front==-1&&rear==-1)
        {
            cout<<"Empty";
        }
        else
        {
            if(front==rear)
            {
                front=-1;
                rear=-1;
            }
            else
            {
                front=(front+1)%maxlen;
            }
        }
    }
    void peek()
    {
        if(front==-1&&rear==-1)
        {
            cout<<"Empty";
        }
        else
        {
            cout<<element[front];
        }
    }
    void show()
    {
        if(front==-1&&rear==-1)
        {
            cout<<"Empty\n";
        }
        else
        {
            if(rear>=front)
            {
                for(int i=front;i<=rear;i++)
                {
                    cout<<element[i]<<endl;
                }
            }
            else
            {
                for(int i=front;i<maxlen;i++)
                {
                    cout<<element[i]<<endl;
                }
                for(int i=0;i<=rear;i++)
                {
                    cout<<element[i]<<endl;
                }
            }
        }
    }
};
int main()
{
    cq q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    int ch;
    cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Size\n5. Show\n6. Exit\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int x;
            cout<<"Enter element to enqueue: ";
            cin>>x;
            q.enqueue(x);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            q.peek();
            break;
        }
        case 4:
        {
            cout<<q.size();
            break;
        }
        case 5:
        {
            q.show();
            break;
        }
        case 6:
        {
            exit(0);
        }
    }
    return 0;
}