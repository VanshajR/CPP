#include "bits/stdc++.h"
using namespace std;

vector<int> parent;
vector<int> sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
// bool hascycle(int u,int v){
//     if(find_set(u)==find_set(v))
//         return true;
//     else
//         return false;
// }

// void checkcycle(int u,int v){
//     if(find_set(u)==find_set(v))
//         cout<<"Cycle detected between"<<u<< "and "<<v<<endl;
//     else
//         cout<<"No cycle detected"<<endl;
// }

void union_set(int a, int b) {
    int na = find_set(a);
    int nb = find_set(b);
    if(na==nb){                                                   //these three lines detect cycle
        cout<<"Cycle detected between"<<a<< "and "<<b<<endl;    //and print it
        // return;                                                //and return nothing because cycle not included
    }
    if (na != nb) {
        if (sz[na] < sz[nb])
            swap(na, nb);
        parent[nb] = na;
        sz[na]+=sz[nb];
    }
}

int main() {
    int n, e, u, v, w;;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    parent.resize(n);
    sz.resize(n);

    for (int i = 0; i < n; i++)
        make_set(i);
    
    vector<pair<int,pair<int,int>>> edges;
    // for(int i=0;i<e;i++)
    // {
    //     cout<<"Edge "<<i+1<<" and its weight: "<<endl;
    //     cin>>u>>v>>w;
    //     edges.push_back({w,{u,v});
        
    // }
    edges.push_back({5,{1,2}});     
    edges.push_back({6,{2,3}});
    edges.push_back({2,{4,3}}); 
    edges.push_back({9,{1,4}});
    edges.push_back({5,{3,5}});
    edges.push_back({10,{5,6}});
    edges.push_back({7,{6,7}});
    edges.push_back({1,{7,8}});
    edges.push_back({1,{8,5}});
    sort(edges.begin(),edges.end());
    int cost = 0;
    for(auto i : edges)
    {
        int w = i.first;
        int u = i.second.first;
        int v = i.second.second;
        int x = find_set(u);
        int y = find_set(v);
        // if(x==y)
        //     continue;
        if(x!=y)
        {
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_set(u,v);
        }
    }
    cout<<"Cost of MST: "<<cost<<endl;

    return 0;
}
