#include<iostream>
using namespace std;
int top=-1;
int stack[100];
void push(int val)
{
    stack[++top]=val;
}
/// @brief 
/// @return 
int top_stack()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top];
    }
}
int pop()
{
    return stack[top--];
}
bool isempty()
{
    return top==-1;
}
int size()
{
    return top+1;
}
int main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    for(int i=0;i<size();i++)
    {
        cout<<stack[i]<<endl;
    }
    cout<<"pop\n";
    
    int p=pop();
    
    cout<<p<<endl;
    for(int i=0;i<size();i++)
    {
        cout<<stack[i]<<endl;
    }


    return 0;
}