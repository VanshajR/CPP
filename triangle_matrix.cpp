#include<iostream>
using namespace std;
int main()
{
	int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int n=4;
//	int b[4][4];
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(i==j)
//			{
//				b[i][j]=a[i];
//			}
//			else
//			{
//				b[i][j]=0;
//			}
//		}
//	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			
			cout<<a[i][j];
			cout<<"    ";
		}
		cout<<endl;
	}
	return 0;
}
