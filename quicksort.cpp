#include<iostream>
using namespace std;
int partition(int arr[],int l,int u)
{
    int pivot=arr[l];
    int count=0;
    for(int i=l+1;i<=u;i++)
    {
        if(arr[i]<pivot)
        {
            count++;
        }
    }
    int pivotIndex=l+count;
    swap(arr[l],arr[pivotIndex]);
    int i=l,j=u;
    while(i<pivotIndex && j>pivotIndex)
    {
        if(arr[i]<pivot)
        {
            i++;
        }
        else if(arr[j]>=pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
    
}

void quickSortIterative(int arr[],int n)
{
    int stack[n];
    int top=-1;
    stack[++top]=0;
    stack[++top]=n-1;
    while(top>=0)
    {
        int high=stack[top--];
        int low=stack[top--];
        int pivot=partition(arr,low,high);
        if(pivot-1>low)
        {
            stack[++top]=low;
            stack[++top]=pivot-1;
        }
        if(pivot+1<high)
        {
            stack[++top]=pivot+1;
            stack[++top]=high;
        }
    }
}

void quickSortRecusrive(int arr[],int l,int u)
{
    if(l<u)
    {
        int pivot=partition(arr,l,u);
        quickSortRecusrive(arr,l,pivot-1);
        quickSortRecusrive(arr,pivot+1,u);
    }
}