#include<iostream>
using namespace std;
void pyramid(int stars,int spaces)
{
    if(stars==0)
    {
        return;
    }
    else
    {
        for(int i=0;i<spaces;i++)
        {
            cout<<" ";
        }
        for(int i=0;i<stars;i++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void printpyramid(int n)
{
    if(n==0)
    {
        return;
    }
    else
    {  
        int spaces=n-1;
        int stars=1;
        pyramid(stars,spaces);
        stars++;
        spaces--;
        printpyramid(n-1);
    }
}
int main()
{
    int n;
    cin>>n;
    printpyramid(n);
}