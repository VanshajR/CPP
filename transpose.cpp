#include<iostream>
using namespace std;
int count(int arr[6][6])
{
    int c=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(arr[i][j]!=0)
            {
            c++;
            }
        }
    }
    return c;
}
int main()
{
  int a[6][6]={{15,0,0,22,0,-15},{0,11,3,0,0,0},{0,0,0,-6,0,0},{0,0,0,0,0,0},{91,0,0,0,0,0},{0,0,28,0,0,0}};
  int b[6][6];
  cout<<"Matrix:\n";
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        cout<<a[i][j]<<"  ";
    }
    cout<<endl;
  }
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        b[j][i]=a[i][j];
    }
  }
  cout<<"\nTranspose:\n";
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        cout<<b[i][j]<<"  ";
    }
    cout<<endl;
  }
  cout<<"Row Major\n";
  cout<<"Row\tColumn\tValue\n6\t6\t"<<count(a)<<"\n";
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        if(b[i][j]!=0)
        {
            cout<<i<<"\t"<<j<<"\t"<<b[i][j]<<endl;
        }
    }
  }
  cout<<"\n\n\nColumn Major\n";
  cout<<"Row\tColumn\tValue\n6\t6\t8\n";
  for(int j=0;j<6;j++)
  {
    for(int i=0;i<6;i++)
    {
        if(b[i][j]!=0)
        {
            cout<<i<<"\t"<<j<<"\t"<<b[i][j]<<endl;
        }
    }
  }
int c[6][6];
for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        c[i][j]=0;
    }
  }
for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        c[i][j]=a[i][j]+b[i][j];
    }
  }
cout<<"\n\nAddition:\n";
for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        cout<<c[i][j]<<"\t";
    }
    cout<<endl;
  }
cout<<"Row Major\n";
  cout<<"Row\tColumn\tValue\n6\t6\t"<<count(c)<<"\n";
  for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        if(c[i][j]!=0)
        {
            cout<<i<<"\t"<<j<<"\t"<<c[i][j]<<endl;
        }
    }
  }
  cout<<"\n\n\nColumn Major\n";
  cout<<"Row\tColumn\tValue\n6\t6\t"<<count(c)<<"\n";
    for(int i=0;i<6;i++)
  {
    for(int j=0;j<6;j++)
    {
        if(c[i][j]!=0)
        {
            cout<<i<<"\t"<<j<<"\t"<<c[i][j]<<endl;
        }
    }
  }
return 0;

}
