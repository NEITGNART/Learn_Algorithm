#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define Vi vector<vector<int>>
#define FOR(i, n) for (int i = 0; i < n; ++i)


void ReadFile(Vi &a, ifstream &fin) {
    int n;
    fin >> n;
    a.resize(n);
    int i = 0;
    while (fin.good()){
        int size;
        fin >> size;

        FOR (j, size) {
            int x;
            fin >> x;
            a[i].push_back(x);
        }
        ++i;
    }
    cout << "Adjacency list after read: \n";
    FOR (i, n) {
        cout << i;
        FOR(j , a[i].size()) {
            cout << "->" << a[i][j]; 
        }
        cout << endl;
    }
}

bool isDirected(const Vi& a) {
    int n = a.size();
    FOR(i, n) {

        FOR(j, a[i].size()) {
            int x = a[i][j];
            FOR(k, a[j].size())  {
                int y = a[j][k];
                if (x == y) {
                    return false;
                }
            }
        }
    }
    cout << "Directed Graph\n";
    return true;
}

void AdjacencyMatrix(Vi a) {
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
            if (ok) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << endl;
    }
}

void NumberofEdgeAndVertex(Vi a) {
    int n = a.size();
    cout << "Number of Vertex: " << n << endl;
    cout << "Number of Edges: ";
    int edges = 0;

    FOR(i, n) {
        edges += a[i].size();
    }
    cout << edges << endl;
}

void Degree (Vi a) {
    int degree = 0;
    int n = a.size();

    vector<int> Indegree(n, 0);
    vector<int> Outdegree(n, 0);
    FOR(i, n) {

        Outdegree[i] += a[i].size();

        FOR(j, a[i].size()) {
            Indegree[a[i][j]]++;
        }
    }
    FOR(i, n) {
        cout << "Indegree of vertex "  << i << " : " << Indegree[i] << endl;
        cout << "OUTdegree of vertex "  << i << " : " << Outdegree[i] << endl;
    }
}

void isCircularGraph(Vi a) {
    int n = a.size();
    vector<int> InDegree(n, 0);
    vector<int> OutDegree(n, 0);
    FOR(i, n) {

        OutDegree[i] += a[i].size();

        FOR(j, a[i].size()) {
            InDegree[a[i][j]]++;
        }
    }
    bool ok = true;
    FOR(i, n) {
        if (InDegree[i] != 1 && OutDegree[i] != 1) {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "This is circular graph\n";
    else cout << "This is not circular graph\n";
}

void Bigraph(Vi a) {
    
}

int main(void) {
    Vi a;
    ifstream fin("input.txt");
    if (fin.fail()) {
        cout << "Error occurs when open file. Please try again!";
        return 0;
    } else {
        Vi a;
        ReadFile(a, fin);
        AdjacencyMatrix(a);
        NumberofEdgeAndVertex(a);
        Degree(a);
        isCircularGraph(a);

    }
    return 0;
}
