#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// DSU (Disjoint Set Union) functions
vector<int> parent, sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

// Kruskal's algorithm
void kruskal(vector<pair<int, pair<int, int>>>& edges, int n) {
    int cost = 0;

    sort(edges.begin(), edges.end());
    
    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (find_set(u) != find_set(v)) {
            // order_of_edges_traversed.push_back({u, v}); // Store the edge in the order it's traversed
            cout<<u<<" "<<v<<" "<<weight<<endl;
            cost += weight;
            union_sets(u, v);
        }
    }
    // cout << "Edges traversed in the order they appear in the graph:" << endl;
    // for (auto edge : order_of_edges_traversed) {
    //     cout << edge.first << " " << edge.second << endl;
    // }    
    cout << "Cost of minimum spanning tree: " << cost << endl;;
}

int main() {
    int n, m; // n -> number of vertices, m -> number of edges
    cin >> n >> m;

    // Initializing DSU
    parent.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; ++i)
        make_set(i);

    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

    // Input edges and weights
    // for (int i = 0; i < m; ++i) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     edges.push_back({w, {u, v}});
    // }

    // edges.push_back({2,{0,1}});     
    // edges.push_back({8,{1,2}});
    // edges.push_back({15,{2,3}}); 
    // edges.push_back({6,{3,0}});
    // edges.push_back({3,{0,2}});
    // edges.push_back({1,{1,3}});


    edges.push_back({5,{1,2}});     
    edges.push_back({6,{2,3}});
    edges.push_back({2,{4,3}}); 
    edges.push_back({9,{1,4}});
    edges.push_back({5,{3,5}});
    edges.push_back({10,{5,6}});
    edges.push_back({7,{6,7}});
    edges.push_back({1,{7,8}});
    edges.push_back({1,{8,5}});

//    int minimum_cost = kruskal(edges, n);
	kruskal(edges, n);
//    cout << "Cost of minimum spanning tree: " << minimum_cost << endl;

    return 0;
}