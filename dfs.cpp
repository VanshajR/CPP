#include <iostream>
#include<vector>
#include<stack>
using namespace std;
// void dfs(int start,vector<int>adj[],bool vis[])
// {
//     vis[start]=true;
//     cout<<start<<" ";
//     vector<int>::iterator it;
//     for(it=adj[start].begin();it!=adj[start].end();it++)
//     {
//         if(!vis[*it])
//         {
//             dfs(*it,adj,vis);
//         }
//     }
// }
int main()
{
    int n,e,start;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";    
    cin>>e;
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
    }
    cout<<"Enter the starting node: ";
    cin>>start;
    stack<int>s;
    s.push(start);
    vis[start]=true;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        cout<<node<<" ";
        vector<int>::reverse_iterator it;
        // vector<int>::iterator it;
        for(it=adj[node].rbegin();it!=adj[node].rend();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=true;
                s.push(*it);
            }
        }
    }
    // dfs(start,adj,vis);
    return 0;    
}