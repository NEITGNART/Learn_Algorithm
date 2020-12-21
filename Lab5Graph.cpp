#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <fstream>
#include <cstring>


using namespace std;

#define Vi vector<vector<int> >
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define vii vector<pair<int, int> >

void ReadFile(Vi &a, ifstream &fin) {
    fin.open("/Users/macbookpro/Desktop/PrepareGraph/PrepareGraph/input.txt");
    int n;
    fin >> n;
    a.resize(n);
    int i = 0;
    while (fin.good()) {
        int siz;
        fin >> siz;
        FOR(j, siz) {
            int x;
            fin >> x;
            a[i].push_back(x);
        }
        ++i;
    }
}

void PrintMaTrixList(Vi &a) {
    int n = a.size();
    
    FOR(i, n) {
        FOR(j, n) {
            bool ok = false;
            FOR(k, a[i].size()) {
                if (j == a[i][k]) {
                    ok = true;
                    break;
                }
            }
            if (ok) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

bool isDirected(Vi &a) {
    int n = a.size();
    FOR(i, n) {
        FOR(j, a[i].size()) {
            int x = a[i][j];
            FOR(k, a[x].size()) {
                if (i == a[x][k]) return false;
            }
        }
    }
    return true;
}
void PrintAdjacencyList(Vi a) {
    int n = a.size();
    FOR(i, n) {
        cout << i;
        FOR(j, a[i].size()) {
            cout << "->" << a[i][j];
        }
        cout << endl;
    }
}
pair<int, int> NumberOfEdgesAndVerTex(Vi a) {
    pair<int, int> VE;
    VE.first = (int)a.size();
    
    // sum of degree = 2e (in which undirected graph)
    int n = a.size();
    int sum = 0;
    
    FOR(i, n) {
        sum += a[i].size();
    }
    
    if (isDirected(a)) VE.second = sum;
    else VE.second = sum / 2;
    
    return VE;
}

void Degree(Vi a) {
    int n = a.size();
    vector<int> Indegree(a.size());
    vector<int> Outdegree(a.size());
    FOR(i, n) {
        Outdegree[i] += a[i].size();
        FOR(j, a[i].size()) {
            Indegree[a[i][j]]++;
        }
    }
    FOR(i, n) {
        cout << "Indegree of vertex " << i
        << " : " << Indegree[i] << endl;
        cout << "Outdegree of vertex " << i
        << " : " << Outdegree[i] << endl;
    }
}

void IsolatedAndLeafNode(Vi a) {
    int n = a.size();
    int isolated = 0;
    int leaf = 0;
    FOR(i, n) {
        if (a[i].size() == 0) ++leaf;
        else if (a[i].size() == 1) ++isolated;
    }
    cout << "Number of Isolated: " << isolated << endl;
    cout << "Number of Leaf: " << leaf << endl;
}

bool CompleteGraph(Vi a) {
    int n = a.size();
    int degree = a[0].size();
    FOR(i, n) {
        if (a[i].size() != degree) return false;
    }
    return true;
}

bool CircularGraph(Vi a) {
    int n = a.size();
    vector<int> Indegree(a.size());
    vector<int> Outdegree(a.size());
    FOR(i, n) {
        Outdegree[i] += a[i].size();
        FOR(j, a[i].size()) {
            Indegree[a[i][j]]++;
        }
    }
    FOR(i, n) {
        if (Indegree[i] != 1 && Outdegree[i] != 1) return false;
    }
    return true;
    
}

vector<int> ans;
bool visited[100];
int pre[100];
void DFS(Vi a, int u) {
    visited[u] = true;
    
    FOR(i, a[u].size()) {
        if (!visited[a[u][i]]) {
            pre[a[u][i]] = u;
            ans.push_back(a[u][i]);
            DFS(a, a[u][i]);
        }
    }
}

vector<int> trace;

void Trace(int u, int v) {
    
    if (!visited[v])  {
        cout << "No path\n";
        return;
    }
    cout << "Path: ";
    while (u != v) {
        trace.push_back(v);
        v = pre[v];
    }
    trace.push_back(u);
    reverse(trace.begin(), trace.end());
    
    for(auto x : trace) cout << x << " ";
    cout << endl;
}

int dist[100];
bool mark[1000];
int Pre[1000];
void BFS(Vi a, int u) {
    
    dist[u] = 0;
    mark[u] = true;
    queue<int> que;
    que.push(u);
    
    while (!que.empty()) {
        int v = que.front(); que.pop();
        cout << v << " ";
        FOR(i, a[v].size()) {
            if (mark[a[v][i]]) continue;
            dist[a[v][i]] = dist[v] + 1;
            mark[a[v][i]] = true;
            Pre[a[v][i]] = v;
            que.push(a[v][i]);
        }
        
    }
}

vector<int> tracebfs;

void TraceBFS(int u, int v) {
    if (!mark[v]) {
        cout << "No path\n";
        return;
    }
    
    while (u != v) {
        tracebfs.push_back(v);
        v = Pre[v];
    }
    tracebfs.push_back(u);
    
    reverse(tracebfs.begin(), tracebfs.end());
    for(auto x : tracebfs) {
        cout << x << " ";
    }
    cout << endl;

}

void ComponentConnective(Vi a) {
    cout << "Number    of component connective: ";
    int res = 0;
    int n = a.size();
    FOR(i, n) {
        if (!visited[i]) {
            ++res;
            DFS(a, i);
        }
    }
    cout << res << endl;
}

bool isBipartite(Vi &graph) {
    int n = graph.size();
    if (n <= 0) return true;
    
    bool ans = true;
    
    for (int i = 0; i < n; ++i) {
        bool visited[105];
        memset(visited, false, sizeof(visited));
        queue<int> q;
        int u = i;
        visited[u] = true;
        bool color[105];
        memset(color, 0, sizeof(color));
        q.push(u);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            
            for(auto x : graph[v]) {
                if (!visited[x]) {
                    visited[x] = true;
                    color[x] = !color[v];
                    q.push(x);
                }
                else {
                    if (color[x] == color[v]) return false;
                }
            }
            
        }
        
    }
    return true;
}


vector<bool> Mark(100, 0);

void dfs(Vi a, int u){
    Mark[u] = true;
    for(auto x : a[u]) {
        if (!Mark[x]) {
            dfs(a, x);
        }
    }
};

void CutVertices(Vi a) {
    
    int n = a.size();
    int start = 0;
    FOR(i, n) {
        if (!Mark[i]) {
            dfs(a, i);
            ++start;
        }
    }
    
    int res = 0;
    
    FOR(i, n) {
        fill(Mark.begin(), Mark.end(), 0);
        Mark[i] = true;
        int ans = 0;
        FOR(j, n) {
            if (!Mark[j]) {
                dfs(a, j);
                ans++;
            }
        }
       
        if (ans > start){ ++res;
             cout << "Vertex after cut increasing number of component connective: " << i << endl;
        }
    }
    cout << "Number of cut vertex: " << res << endl;
}

Vi BaseUndirectedGraph(Vi a) {
    int n = a.size();
    Vi res;
    res.resize(n);
    
    FOR(i, n) {
        FOR(j, a[i].size()) {
            int x = a[i][j];
            res[i].push_back(x);
            res[x].push_back(i);
        }
    }
    PrintMaTrixList(res);
    return res;
}

Vi Complement(Vi a) {
    Vi res;
    int n = a.size();
    res.resize(n);
    FOR(i, n) {
        vector<int> mark(n, false);
        
        FOR(j, a[i].size()) {
            mark[a[i][j]] = true;
        }
        FOR(k, n) {
            if (k != i && mark[k] == false){
                res[i].push_back(k);
            }
        }
    }
    return res;
}

Vi Converse(Vi a) {
    Vi res;
    int n = a.size();
    res.resize(n);
    FOR(i, n) {
        FOR(j, a[i].size()) {
            res[a[i][j]].push_back(i);
        }
    }
    return res;
}

vii Edge(Vi a) {
    int n = a.size();
    vector<pair<int, int>> list;
    vector<vector<bool> > M;
    M.resize(n);
    FOR(i, n) M[i].resize(n);
    FOR(i, n) FOR(j, n) M[i][j] = false;
    FOR(i, n) {
        FOR(j, a[i].size()) {
            
            if (!M[i][a[i][j]]) {
                list.push_back({i, a[i][j]});
                M[a[i][j]][i] = true;
            }
                
        }
    }
    return list;
}

void Bridge(Vi a) { // passing base graph
    vii list = Edge(a);
    // Try all edges
    int n = a.size();
    int start = 0;
    for(auto x : Mark) x = false; // init
    FOR(i, n) {
        if (!Mark[i]) {
            dfs(a, i);
            ++start;
        }
    }
    int res = 0;
    cout << "Start: " << start << endl;
    for(auto u : list) {
        for(auto x : Mark) x = false; // init
        Mark[u.first] = true;
        Mark[u.second] = true;
        int cnt = 0;
        FOR(j, n) {
            if (!Mark[j]) {
                dfs(a, j);
                ++cnt;
            }
        }
        if (cnt > start) {
            ++res;
            cout << "Delete: " << u.first << " " << u.second  << endl;
        }
    }
    cout << "Number of bridge: " << res << endl;
}

int main(void) {
    
    ifstream fin;
    Vi a;
    ReadFile(a, fin);
    PrintMaTrixList(a);
    bool directed = isDirected(a);
    if (directed) cout << "This graph is directed\n";
    else  cout << "This graph is NOT directed\n";
    auto VE = NumberOfEdgesAndVerTex(a);
    cout << "Number of Vertex: " << VE.first;
    cout << "\nNumber of Edges: " << VE.second << endl;
    Degree(a);
    IsolatedAndLeafNode(a);
    
    ans.push_back(0);

    DFS(a, 3);
    
    cout << "DFS: ";
    
    FOR(i, ans.size()) {
        cout << ans[i] << " ";
        
    }
    Trace(3, 7);
    cout << "\nBFS: ";
    BFS(a, 0);
    cout << endl << endl;
    cout << "Trace BFS: ";
    TraceBFS(0, 8);
    ComponentConnective(a);
    cout << "Cut vertex: " << endl;
    Vi base = BaseUndirectedGraph(a);
    if (isDirected(base)) cout << "False\n";
    else cout << "True\n";
    CutVertices(base);
    cout << "Base represent in adjacency list:\n";
    PrintAdjacencyList(base);
    cout << endl << endl;
    Vi complement = Complement(a);
    PrintAdjacencyList(complement);
    cout << "Converser: \n";
    Vi converse = Converse(a);
    PrintAdjacencyList(converse);
    Bridge(base);
    
    return 0;
}
