#include<iostream>
#define maxlen 100
using namespace std;
class stack
{
    public:
    int top;
    char element[maxlen];
    stack()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(top==maxlen-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int x)
    {
        if(isFull())
        {
            cout<<"Overflow";
        }
        else
        {
            top++;
            element[top]=x;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
        }
        else
        {
            top--;
        }
    }
    void gettop()
    {
        if(isEmpty())
        {
            cout<<"Empty";
        }
        else
        {
            cout<<element[top];
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
            for(int i=top;i>=0;i--)
            {
                cout<<element[i];
            }
        }
    }
    int size()
    {
        return top+1;
    }
    void reverse()
    {
        while(!isEmpty())
        {
            cout<<element[top];
            pop();
        }
    }
};
void balancedparentheses(string &st)
{
    stack s;
    int count=0;
    for(char c : st)
    {
        if(c=='(')
        {
            s.push(c);
        }
        else if(c==')'&&!s.isEmpty()&&s.element[s.top]=='(')
        {
            s.pop();
            count++;
        }
    }
    cout<<"Balanced Parentheses: "<<count;
}
int main()
{
    stack s;
    string word="Data() (() (Structures";
    for(int i=0;i<word.length();i++)
    {
        s.push(word[i]);
    }
    // s.push(1);
    // s.push(2);
    // s.push(3);
    s.show();
    cout<<endl;
    s.reverse();
    cout<<endl;
    balancedparentheses(word);
    
    return 0;
}
