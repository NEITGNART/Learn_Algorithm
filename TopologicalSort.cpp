#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

#define Vii vector<vector<int>>
#define FOR(i, n) for (int i = 0; i < n; ++i)

vector<bool> visited;
vector<int> ans;
Vii adj;
int n;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << " ";
    }

}

int main(void) {

    cin >> n;
    adj.resize(n);

    FOR(i, n){
        FOR(j, n) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].push_back(j);
            }
        }
    }
    
    cout << "Adjacency list: \n";
    FOR (i, n)  {
        cout << i;
        FOR(j, adj[i].size()){
            cout << "->" << adj[i][j];
        }
        cout << endl;
    }
    cout << "Topological Sort: \n";
    topological_sort();

}
