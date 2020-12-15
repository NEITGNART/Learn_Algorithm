#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n + 1), rank(n+1, 0) {
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int Find(int x) {
        while (x != parent[x]) x = parent[x];
        return x;
    }
    bool Union(int a, int b) {
        int v = Find(a);
        int u = Find(b);
        if (v == u) return true;
        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) parent[u] = v;
        else parent[v] = u;
        return false;
    }
};

int main(void) {
    DisjointSet Disjoint(10000);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        if (t == 1) Disjoint.Union(a, b);
        else {
            if (Disjoint.Find(a) == Disjoint.Find(b)) cout << "1\n";
            else cout << "0\n";
        }      
    }

    return 0;
}
