#include "bits/stdc++.h"

using namespace std;

vector<int> parent;
vector<int> size;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    int a_root = find_set(a);
    int b_root = find_set(b);
    if (a_root != b_root) {
        if (size[a_root] < size[b_root])
            swap(a_root, b_root);
        parent[b_root] = a_root;
        size[a_root] += size[b_root];
    }
}

int main() {
    int n, e, u, v, w;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++)
        make_set(i);

    vector<vector<int>> edges;
    edges.push_back({1, 2, 5});
    edges.push_back({2, 3, 6});
    edges.push_back({4, 3, 2});
    edges.push_back({1, 4, 9});
    edges.push_back({3, 5, 5});
    edges.push_back({5, 6, 10});
    edges.push_back({6, 7, 7});
    edges.push_back({7, 8, 1});
    edges.push_back({8, 5, 1});
//     // for (auto i : edges) {
//     //     int b=1;
//     //     int w = i[0];
//     //     int u = i[1];
//     //     int v = i[2];
//     //     cout<<u<<" "<<v<<" "<<w<<"  "<<b<<endl;
//     //     b++;
//     // }
//     sort(edges.begin(), edges.end());
//     // cout<<"After sorting"<<endl;
//     // edges.push_back({8, 5, 1});
//     // for (auto i : edges) {
//     //     int w = i[0];
//     //     int u = i[1];
//     //     int v = i[2];
//     //     cout<<u<<" "<<v<<" "<<w<<"  "<<endl;
        
//     // }

//     int cost = 0;
//     vector<int>::iterator it;
//     for (size_t i = 0; i < edges.size(); i++) {
//         int w = edges[i][0];
//         int u = edges[i][1];
//         int v = edges[i][2];
//         cout<<"before if\n";
//         cout<<u<<" "<<v<<" "<<w<<"  "<<endl;
//         int x = find_set(u);
//         int y = find_set(v);
//         if (x != y) {
//             cout<<"Inside if"<<endl;
//             cout << u << " " << v << endl;
//             cost += w;
//             union_set(u, v);
//         }
//         cout<<"Outside and after if"<<endl;
//     }

//     cout << "Cost of MST: " << cost << endl;

//     return 0;
// }
// Your previous code...

// Iterate through the sorted edges and print them
sort(edges.begin(), edges.end());
cout << "After sorting" << endl;
for (size_t i = 0; i < edges.size(); ++i) {
    int w = edges[i][0];
    int u = edges[i][1];
    int v = edges[i][2];
    cout << u << " " << v << " " << w << "  " << endl;
}

// Debug prints to isolate the issue
cout << "Before loop through edges for MST construction" << endl;

// Iterate through edges for MST construction
int cost = 0;
for (size_t i = 0; i < edges.size(); i++) {
    cout << "Inside loop iteration: " << i << endl; // Debug print
    int w = edges[i][0];
    int u = edges[i][1];
    int v = edges[i][2];
    cout << "before if" << endl;
    int x = find_set(u);
    int y = find_set(v);
    if (x != y) {
        cout << "Inside if" << endl;
        cout << u << " " << v << endl;
        cost += w;
        union_set(u, v);
    }
    cout << "After if" << endl;
}

cout << "Cost of MST: " << cost << endl;

// Debug print after the loop
cout << "After loop through edges for MST construction" << endl;

return 0;
}