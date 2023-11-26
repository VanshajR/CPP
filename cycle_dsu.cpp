#include <iostream>
#include <vector>
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
bool hascycle(int u,int v){
    if(find_set(u)==find_set(v))
        return true;
    else
        return false;
}

void checkcycle(int u,int v){
    if(find_set(u)==find_set(v))
        cout<<"Cycle detected between"<<u<< "and "<<v<<endl;
    else
        cout<<"No cycle detected"<<endl;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(hascycle(a,b)){
        cout<<"Cycle detected between "<<a<< " and "<<b<<endl;
        return;
    }
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
    }
}

int main() {
    int n, e, x, y;;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; ++i)
        make_set(i);

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }

    cout << "Parent of each node after DSU operations:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << " belongs to set with parent: " << find_set(i) << endl;
    }
    
    cout<<"Enter the nodes to check for cycle"<<endl;
    cin>>x>>y;
    checkcycle(x,y);

    return 0;
}
