#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n,e,start;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";    
    cin>>e;
    int adjM[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            adjM[i][j]=0;
            adjM[j][i]=0;
        }
    }
    bool vis[n];
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        vis[i]=false;
    }
    int x,y;
    cout<<"Enter the edges from one node to another node: "<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<<i+1<<": "<<endl;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        adjM[x][y]=1;
        adjM[y][x]=1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adjM[i][j]<<" ";
        
        }
        cout<<endl;
    }
    cout<<"Enter the starting node: ";
    cin>>start;
    queue<int>q;
    q.push(start);
    vis[start]=true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        vector<int>::iterator it;
        for(it=adj[node].begin();it!=adj[node].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=true;
                q.push(*it);
            }
        }
    }
    return 0;    
}