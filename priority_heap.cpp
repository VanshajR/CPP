#include<iostream>
#include<algorithm>
using namespace std;
void maxheapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[left]>arr[largest])
    {
        largest = left;
    }
    if(right<n&&arr[right]>arr[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}
void minheapify(int arr[],int n,int i)
{
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[left]<arr[smallest])
    {
        smallest=left;
    }
    if(right<n&&arr[right]<arr[smallest])
    {
        smallest=right;
    }
    if(smallest!=i)
    {
        swap(arr[i],arr[smallest]);
        minheapify(arr,n,smallest);
    }
}
void buildmaxheap(int arr[],int n)
{
    for(int i=n-2-1;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
}
void buildminheap(int arr[],int n)
{
    for(int i=n-2-1;i>=0;i--)
    {
        minheapify(arr,n,i);
    }
}
void disp(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int heapextractmax(int arr[],int n)
{
    if(n<1)
    {
        return -1;
    }
    int max=arr[0];
    arr[0]=arr[n-1];
    n=n-1;
    maxheapify(arr,n,0);
    return max;
}
void insert(int arr[],int &n,int key)
{
    n+=1; //done because we are adding a new element
    arr[n-1]=key;  //done because index-1 is the last element
    int i=n-1;
    while(i>0&&arr[(i-1)/2]<arr[i]) //(i-1)/2 is the parent of i
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapincreasekey(int arr[],int i,int key)
{
    if(key<arr[i])
    {
        return;
    }
    arr[i]=key;
    while(i>0&&arr[(i-1)/2]<arr[i])
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
void heapsortasc(int arr[],int n)
{
    buildmaxheap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
    disp(arr,n);
}
void heapsortdesc(int arr[],int n)
{
    buildminheap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        minheapify(arr,i,0);
    }
    disp(arr,n);
}
void heapsortdescjugad(int arr[],int n)
{
    heapsortasc(arr,n);
    reverse(arr,arr+n);
    disp(arr,n);
}
int main()
{
    int a[]={4,10,3,5,1,7,8,9,2,6};
    int n=sizeof(a)/sizeof(a[0]);
    // disp(a,n);
    // buildmaxheap(a,n);
    // cout<<"\n Max heap:-\n";
    // disp(a,n);
    // cout<<"\n Min heap:-\n";
    // buildminheap(a,n);
    // disp(a,n);
    // cout<<"\nheapsortasc:\n";
    // heapsortasc(a,n);
    // cout<<"\nheapsortdescjugad:\n";
    // heapsortdescjugad(a,n);
    // cout<<"\nheapsortdesc:\n";
    // heapsortdesc(a,n);

    //FOR A PRIORITY QUEUE, WE MAKE A MAX HEAP, INSERT SOMETHING, AND THEN EXTRACT MAX, SIMPLE
    buildmaxheap(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    disp(a,n);
    cout<<"\n";
    insert(a,n,19);
    insert(a,n,15);
    disp(a,n);
    cout<<"\n";
    cout<<heapextractmax(a,n);
    cout<<"\n";
    disp(a,n);
    return 0;
}