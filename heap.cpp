#include<iostream>
using namespace std;
void maxheapify(int arr[],int n,int i)
{
    int largest=i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}

void buildmaxheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
}

// void minheapify(int arr[],int n,int i)
// {
//     int smallest=i;
//     int left = 2*i+1;
//     int right = 2*i+2;
//     if(left<n && arr[left]<arr[smallest])
//     {
//         smallest=left;
//     }
//     if(right<n && arr[right]<arr[smallest])
//     {
//         smallest=right;
//     }
//     if(smallest!=i)
//     {
//         swap(arr[i],arr[smallest]);
//         minheapify(arr,n,smallest);
//     }
// }

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}


void buildminheap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        minHeapify(arr,n,i);
    }
}

void disp(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
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

void insert(int arr[],int n,int key)
{
    n+=1;
    arr[n-1]=key;
    //as far as I understand, this is simply a roundabout way of doing maxheapify on the last element via a while loop, so the comments below make sense(maybe)
    //this is called bubble up or heapify up or percolate up algorithm apparently
    int i=n-1;
    while (i>0 && arr[(i-1)/2]<arr[i])
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
    // maxheapify(arr,n,n-1);
    //or use minHeapify(arr,n,n-1);
}

void increasekey(int arr[],int i,int key)
{
    if (key<arr[i])
    {
        return;
    }
    arr[i]=key;
    //this is called bubble up or heapify up or percolate up algorithm apparently
    while (i>0 && arr[(i-1)/2]<arr[i])
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
    
}

void maxheapsortasc(int arr[],int n)
{
    buildmaxheap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        maxheapify(arr,i,0);
    }
}

int main()
{
    int a[]={4,10,3,5,1,7,8,9,2,6};
    int b[]={4,10,3,5,1,7,8,9,2,6};
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    disp(a,n);
    buildmaxheap(a,n);
    cout<<"\n Max heap:-\n";
    disp(a,n);
    cout<<"\n Min heap:-\n";
    buildminheap(b,m);
    disp(b,m);
}