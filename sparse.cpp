#include<iostream>
using namespace std;
class element
{
    public:
    int i;
    int j;
    int val;
};
class sparse
{
    public:
    int r;
    int c;
    int num_nz;
    element* e;
    sparse(int rows,int cols, int num)
    {
        r=rows;
        c=cols;
        num_nz=num;
        e = new element [num_nz];
    }
    ~sparse()
    {
        delete [] e;
    }
    void create()
    {
        for(int i=0;i<num_nz;i++)
        {
            cout<<"Enter row,col and value: ";
            cin>>e[i].i>>e[i].j>>e[i].val;
        }
    }
    void disp()
    {
        int k=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(e[k].i==i&&e[k].j==j)
                {
                    cout<<e[k++].val<<"  ";

                }
                else
                {
                    cout<<"0  ";
                }
            }
            cout<<endl;
        }
    }
};
sparse add(sparse &s1,sparse &s2)
{
    int i,j,k;
    if(s1.r!=s2.r||s1.c!=s2.c)
    {
        cout<<"Cant be added\n";
        sparse *sum = new sparse(0,0,0);
        return *sum;
    }
    sparse *sum = new sparse(s1.r,s1.c,s1.num_nz+s2.num_nz);
    i=j=k=0;
    while (i<s1.num_nz&&j<s2.num_nz)
    {
        if(s1.e[i].i<s2.e[j].i)
        {
            sum->e[k++]=s1.e[i++];
        }
        else if(s1.e[i].i>s2.e[j].i)
        {
            sum->e[k++]=s2.e[j++];
        }
        else
        {
            if(s1.e[i].j<s2.e[j].j)
            {
                sum->e[k++]=s1.e[i++];
            }
            else if(s1.e[i].j>s2.e[j].j)
            {
                sum->e[k++]=s2.e[j++];
            }
            else
            {
                sum->e[k]=s1.e[i];
                sum->e[k++].val=s1.e[i++].val+s2.e[j++].val;
            }
        }
        
    }
    for(;i<s1.num_nz;i++)
        sum->e[k++]=s1.e[i];
    for(;j<s2.num_nz;j++)
        sum->e[k++]=s2.e[j];
    sum->num_nz=k;
    return *sum;
    
}
sparse tran(sparse s)
{
    int i=0;
    sparse *res = new sparse(s.c,s.r,s.num_nz);
    while(i<s.num_nz)
    {
        res->e[i].i=s.e[i].j;
        res->e[i].j=s.e[i].i;
        res->e[i].val=s.e[i].val;

    }
    return *res;
}
int main()
{
    sparse s1(5,5,5);
    sparse s2(5,5,5);
    s1.create();
    s1.disp();
    cout<<"\n\n";
    s2.create();
    s2.disp();
    cout<<"\n\n";
    // sparse s3=add(s1,s2);
    sparse s3=tran(s1);
    s3.disp();
    cout<<s3.num_nz;
    return 0;

}