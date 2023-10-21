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
    int givefront()
    {
        if(isEmpty())
        {
            cout<<"\nEmpty\n";
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
    q.dequeue();    
    q.show();
    return 0;
}