#include<iostream>
using namespace std;
void insert(int a[],int n)
{ 
    int temp;
    for(int i = 0; i<n; i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
int main()
{
    int arr[5]={5,2,4,3,1};
    insert(arr,5);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;


}