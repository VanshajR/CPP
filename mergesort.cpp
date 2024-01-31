#include<iostream>
using namespace std;
void mergeSortIterative(int arr[],int n)
{
    int p,l,u,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            u=i+p-1;
            mid=(l+u)/2;
            int k=l;
            int j=mid+1;
            int temp[n];
            int index=l;
            while(k<=mid && j<=u)
            {
                if(arr[k]<arr[j])
                {
                    temp[index++]=arr[k++];
                }
                else
                {
                    temp[index++]=arr[j++];
                }
            }
            while(k<=mid)
            {
                temp[index++]=arr[k];
                k++;
            }
            while(j<=u)
            {
                temp[index++]=arr[j];
                j++;
            }
            for(int i=l;i<=u;i++)
            {
                arr[i]=temp[i];
            }
        }
    }
    if(p/2<n)
    {
        int temp[n];
        int index=0;
        for(int i=p/2;i<n;i++)
        {
            temp[index++]=arr[i];
        }
        for(int i=0;i<p/2;i++)
        {
            temp[index++]=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            arr[i]=temp[i];
        }
    }
}

void merge(int arr[],int l,int mid,int u)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int temp[u+1];
    while(i<=mid && j<=u)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i];
        i++;
    }
    while (j<=u)
    {
        temp[k++]=arr[j];
        j++;
    }
    for(int i=l;i<=u;i++)
    {
        arr[i]=temp[i];
    }
}
void mergeSortRecursive(int arr[],int l,int u)
{
    if(l<u)
    {
        int mid=(l+u)/2;
        mergeSortRecursive(arr,l,mid);
        mergeSortRecursive(arr,mid+1,u);
        merge(arr,l,mid,u);
    }
}

int main()
{
    int arr[]={8,3,7,4,9,2,6,5,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSortIterative(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSortRecursive(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}