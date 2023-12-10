#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minindex(vector<int>cost,vector<bool>vis,int n)
{
	int min=INT_MAX;
	int index=-1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i]&&cost[i]<min)
		{
			min=cost[i];
			index=i;
		}
	}
	return index;
}

void primMST_L(vector<vector<pair<int,int>>>&adjL,int n)
{
	vector<int>cost(n,INT_MAX);
	vector<int>parent(n,-1);
	vector<bool>vis(n,false);
	int mincost=0;
	parent[0]=-1;
	cost[0]=0;
	for(int i=0;i<n-1;i++)
	{
		int index = minindex(cost,vis,n);
		vis[index]=true;
		for(auto it : adjL[index])
		{
			int travel = it.first;
			int weight = it.second;
			if(!vis[travel]&&weight<cost[travel])
			{
				cost[travel]=weight;
				parent[travel]=index;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		cout<<"Edge: "<<parent[i]<<" -> "<<i<<" Cost: "<<cost[i]<<endl;
		mincost+=cost[i];
	}
	cout<<"Cost Incurred: "<<mincost<<endl;
	
}

void primMST_M(int **adjM,int n)
{
	vector<int>cost(n,INT_MAX);
	vector<int>parent(n,-1);
	vector<bool>vis(n,false);
	int mincost=0;
	parent[0]=-1;
	cost[0]=0;
	for(int i=0;i<n-1;i++)
	{
		int index = minindex(cost,vis,n);
		vis[index]=true;
		for(int j=0;j<n;j++)
		{
			int travel=j;
			int weight=adjM[index][j];
			if(!vis[travel]&&weight!=0&&weight<cost[travel])
			{
				cost[travel]=weight;
				parent[travel]=index;
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		cout<<"Edge: "<<parent[i]<<" -> "<<i<<" Cost: "<<cost[i]<<endl;
		mincost+=cost[i];
	}
	cout<<"Cost Incurred: "<<mincost<<endl;
}

int main()
{
	int n,e;
	cout<<"Vertices: ";
	cin>>n;
	cout<<"Edges: ";
	cin>>e;
	vector<vector<pair<int,int>>>adjL(n);
	int **adjM = new int* [n];
	for(int i=0;i<n;i++)
	{
		adjM[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			adjM[i][j]=0;
		}
	}
	
	int x,y,w;
	for(int i=0;i<e;i++)
	{
		cout<<"Edge "<<i+1<<" and its weight: ";
		cin>>x>>y>>w;
		
		adjL[x].push_back({y,w});
		adjL[y].push_back({x,w});
		
		adjM[x][y]=w;
		adjM[y][x]=w;
	}
	
	cout<<"Adjacency List:\n";
	for(int i=0;i<n;i++)
	{
		cout<<i<<" -> ";
		for(auto it : adjL[i])
		{
			cout<<"("<<it.first<<" , "<<it.second<<") ->";
		}
		cout<<endl;
	}
	
	cout<<"Adjacency Matrix:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<adjM[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Algo with adjL:\n";
	primMST_L(adjL,n);
	cout<<"\nAlgo with adjM:\n";
	primMST_M(adjM,n);
	return 0;
}