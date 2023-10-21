#include<iostream>
using namespace std;
int q[10];
int front=-1;
int rear=-1;
int n=10;
void enqueue(int val)
{
    if((front==0&&rear==n-1)||((rear+1)%n==front))
    {
        cout<<"Full";
    }
    else if(front==-1)
    {
        front++;
        rear++;
        q[rear]=val;
       
    }
    else if(rear==n-1&&front!=0)
    {
        rear=0;
        q[rear]=val;
    }
    else
    {
        q[++rear]=val;
    }
}
int dequeue()
{
    if(front==-1&&rear==-1)
    {
        cout<<"Empty";
    }
    int d=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front=n-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
    return d;
}
void show()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<q[i]<<endl;
    }
}
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    int p=dequeue();
    int q=dequeue();
    show();
    cout<<front<<endl;
    cout<<"rear"<<rear;
}
