

** Breath First Search

queue<int> q;
bool visited[N];
int distance[N];

void BFS(int x){
	visited[x] = true;
	distance[x] = 0;
	q.push(x);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		for (auto u : adj[s]){
			if (visited[u]) continue;
			visited[u] = true;
			distance[u] = distance[x] + 1;
			q.push(u); 
		}
	}
} 

** Depth Frist Search

bool visited[N];

void dfs(int s){
	if (visited[s]) return;
	visited[s] = true;
	for (auto u : adj[s]){
		dfs(u);
	}
}

** Binary Search


int k = 0;

for (int b = n/2; b >= 1; b /= 2){
	while (k + b < n && array[k+b] <= x) k += b;
} 

if (array[k] == x){
	// x found at index k
}

