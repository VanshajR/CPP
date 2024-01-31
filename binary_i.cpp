#include<iostream>
using namespace std;
void BinarySearchIterative(int arr[],int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key)
        {
            cout<<"Element found at index "<<mid<<endl;
            return;
        }
        else if(arr[mid]>key)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<"Element not found"<<endl;
}

void BinarySearchRecursive(int arr[],int n,int key)
{
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    if(low>high)
    {
        cout<<"Element not found"<<endl;
        return;
    }
    if(arr[mid]==key)
    {
        cout<<"Element found at index "<<mid<<endl;
        return;
    }
    else if(arr[mid]>key)
    {
        high=mid-1;
        BinarySearchRecursive(arr,n,key);
    }
    else
    {
        low=mid+1;
        BinarySearchRecursive(arr,n,key);
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=5;
    BinarySearchIterative(arr,n,key);
    BinarySearchRecursive(arr,n,key);
    return 0;
}