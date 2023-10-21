#include<iostream>
using namespace std;
int main()
{
    int n=10;
    int size=n;
    int arr[n]={50,32,44,18,7,5,9,1,74,3};
    for(int i=0;i<size;i++)
    {
        int c=0;
        int sum=0;
        for(int j=i;j<size;j++)
        {
            sum+=arr[j];
            c++;
        }
        float avg=((float)sum)/((float)c);
        cout<<"avg: "<<avg<<endl;
        // cout<<"I before "<<i<<endl;
        if(arr[i]>avg)
        {
            for(int k=i;k<size;k++)
            {
                arr[k]=arr[k+1];
                
            }
            size--;
            i--;
        }

    
        // cout<<arr[i]<<endl;
        // cout<<"I after: "<<ik<<endl;
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}