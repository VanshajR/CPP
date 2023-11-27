#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int ismin=0,ismat=0,islist=0;
int minindex(vector<int>cost,vector<bool>vis,int n)
{
    int min=32767;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && cost[i]<min)
        {
            min=cost[i];
            index=i;
        }
    }
    ismin++;
    return index;
}

void primMST_L(vector<vector<pair<int,int>>>&adjL,int n)
{
    vector<int> parent(n,-1);
    vector<int> cost(n,INT_MAX);
    vector<bool>vis(n,false);
    int mincost=0;
    parent[0]=-1;
    cost[0]=0;
    for(int i=0;i<n-1;i++)
    {
        islist++;
        int mincostindex=minindex(cost,vis,n);
        vis[mincostindex]=true;
        for(auto it:adjL[mincostindex])
        {
            int travel=it.first;
            int weight=it.second;
            if(!vis[travel] && weight<cost[travel])
            {
                cost[travel]=weight;
                parent[travel]=mincostindex;
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



void primMST_M(int **adjM,int n)
{
    int mincost=0;
    vector<int> parent(n,-1);
    vector<int> cost(n,INT_MAX);
    vector<bool>vis(n,false);

    parent[0]=-1;
    cost[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int mincostindex=minindex(cost,vis,n);
        vis[mincostindex]=true;
        for(int j=0;j<n;j++)
        {
            int travel=j;
            int weight=adjM[mincostindex][j];
            ismat++;
            if(weight!=0 && !vis[travel] && weight<cost[travel])
            {
                cost[travel]=weight;
                parent[travel]=mincostindex;
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
    vector<vector<pair<int,int>>>adjL(n);
    int x,y,w;
    int** adjM = new int*[n];
    for (int i = 0; i < n; ++i) {
        adjM[i] = new int[n];
        // Initialize the matrix with zeros
        for (int j = 0; j < n; ++j) {
            adjM[i][j] = 0;
        }
    }
    cout<<"Enter the edges from one node to another node and weight: "<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<": "<<endl;
        cin>>x>>y>>w;

        adjL[x].push_back({y,w});
        adjL[y].push_back({x,w});

        adjM[x][y]=w;
        adjM[y][x]=w;
    }
    cout<<"Input taken successfully"<<endl;
    if(ismin)
    {
        cout<<"Min is used "<<ismin<<" times"<<endl;
    }
    if(ismat)
    {
        cout<<"Matrix is used "<<ismat<<" times"<<endl;
    }
    if(islist)
    {
        cout<<"List is used "<<islist<<" times"<<endl;
    }

    cout<<"Adjacency List: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<"->";
        for(auto it:adjL[i])
        {
            cout<<"("<<it.first<<","<<it.second<<")"<<"->";
        }
        cout<<endl;
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
    cout<<"Using Adjacency List: "<<endl;
    primMST_L(adjL,n);
    cout<<"Using Adjacency Matrix: "<<endl;
    primMST_M(adjM,n);
    delete[] adjM;
    return 0;    
}