#include<iostream>
#define maxlen 100
using namespace std;
class queue
{
    // static int maxlen;
    public:
    int front;
    int rear;
    int element[maxlen];
    
    queue()
    {
        front = -1;
        rear = -1;

    }
    int isFull()
    {
        return(rear==maxlen-1);
    }
    int isEmpty()
    {
        
        if(front==-1||front>rear)
        return 1;
        else
        return 0;
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
    void enqueue(int x)
    {
        if(isFull())
        {
            cout<<"full";
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
    void dequeue()
    {
        if(isEmpty())
        cout<<"Empty\n";
        else
        {
            front++;
        }
    }
    void show()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<element[i]<<endl;
        }
    }
};
// int queue::maxlen=100; 
int main()
{
    queue q;
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
            cout<<q.peek();
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