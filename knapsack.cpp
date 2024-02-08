#include<iostream>
#include<algorithm>
using namespace std;
class item
{
    public:
    int weight;
    int value;
};
bool comparison(item a,item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fractionalKnapsack(int W,item arr[],int n)
{
    sort(arr,arr+n,comparison);
    int currentWeight=0;
    double finalValue=0.0;
    for(int i=0;i<n;i++)
    {
        if(currentWeight+arr[i].weight<=W)
        {
            currentWeight+=arr[i].weight;
            finalValue+=arr[i].value;
        }
        else
        {
            int remain=W-currentWeight;
            finalValue+=arr[i].value*((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int W=50;
    item arr[]={{10,60},{20,100},{30,120}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum value we can obtain = "<<fractionalKnapsack(W,arr,n);
    return 0;
}