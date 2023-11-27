#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=arr[i];
    }
    int nsum = (n*(n+1))/2;
    int missing = nsum-sum;
    cout<<"Missing number is "<<missing;
}