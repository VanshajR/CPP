#include<iostream>
using namespace std;
int q[10];
int front=-1;
int rear=-1;
int n=10;
void enqueue(int val)
{
    if(((rear+1)%n==front))
    {
        cout<<"Full\n";
    }

    else
    {
        if(front==-1)
        {
            front++;
        }
        rear=(rear+1)%n;
        q[rear]=val;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        cout<<"Empty";
    }
    // int d=q[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%n;
    }
    // return d;
}

void show()
{
    if (front == -1 && rear == -1)
    {
        cout << "Empty" << endl;
        return;
    }

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << q[i] << endl;
        }
    }
    else
    {
        for (int i = front; i < n; i++)
        {
            cout << q[i] << endl;
        }

        for (int i = 0; i <= rear; i++)
        {
            cout << q[i] << endl;
        }
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
    dequeue();
    dequeue();
    cout<<"F: "<<front<<endl;
    cout<<"R: "<<rear<<endl;
    show();
    cout<<"after\n";
    enqueue(11);
    enqueue(12);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(11);
    enqueue(12);
    
    show();
}
