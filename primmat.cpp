#include<iostream>
#include<vector>
using namespace std;
int minindex(vector<int>cost,vector<bool>vis,int n)
{
    int min=32767;
    int minindex;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && cost[i]<min)
        {
            min=cost[i];
            minindex=i;
        }
    }
    return minindex;
}
void primMST_M(int **adjM,int n)
{
	int INF = 1e9;
    int mincost=0;
    vector<int> parent(n,-1);
    vector<int> cost(n,INF);
    vector<bool>vis(n,false);

    parent[0]=-1;
    cost[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int mincostindex=minindex(cost,vis,n);
        vis[mincostindex]=true;
        for(int j=0;j<n;j++)
        {
            if(adjM[mincostindex][j]!=0 && !vis[j] && adjM[mincostindex][j]<cost[j])
            {
                cost[j]=adjM[mincostindex][j];
                parent[j]=mincostindex;
            }
        }
    }
    
    for(int i=1;i<n;i++)
    {
        cout<<"Edge "<<parent[i]<<"->"<<i<<" cost: "<<cost[i]<<endl;
        mincost+=cost[i];
    }
    cout<<"Minimum cost: "<<mincost<<endl;
}
int main()
{
    int n,e;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";    
    cin>>e;
    vector<vector<pair<int, int>>> adjL(n);
    int x,y,w;
    int** adjM = new int*[n];
    for (int i = 0; i < n; i++) {
        adjM[i] = new int[n];
        // Initialize the matrix with zeros
        for (int j = 0; j < n; j++) {
            adjM[i][j]= 0;
        }
    }
    cout<<"Matrix initialized with zeros"<<endl;
    cout<<"Enter the edges from one node to another node and weight: "<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<": "<<endl;
        cin>>x>>y>>w;
        adjM[x][y]=w;
        adjM[y][x]=w;
        cout<<"input taken"<<endl;
    }

    cout<<"Adjacency Matrix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adjM[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Minimum Spanning Tree using Prim's Algorithm: "<<endl;
    cout<<"Using Adjacency Matrix: "<<endl;
    primMST_M(adjM,n);

    return 0;    
}