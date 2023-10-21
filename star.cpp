#include<iostream>
using namespace std;
int main()
{
    int n=10;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            // cout<<"*";
            for(int k=0;k<j;k++)
            {
                cout<<" *";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}