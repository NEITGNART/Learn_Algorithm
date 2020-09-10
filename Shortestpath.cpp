
void Bellman_Ford(int x){

	for (int i = 1; i <= n; ++i){
		distance[i] = INF;
	}		 
	distance[x] = 0;
	
	for (int i = 1; i <= n-1; ++i){
		for (auto e : edges){
			int a, b, w;
			tie(a, b, w) = e;
			distance[b] = min(distance[b], distance[a] + w)
		}
	}
	
}


priority_queue<pair<int, int>> q;

void Dijkstra(int x) {
	
	for (int i = 1; i <= n; ++i){
		distance[i] = INF;
	}
	distance[x] = 0;
	q.push({0, x});
	
	while (!q.empty()){
		int a = q.top().second; q.pop();
		if(processed[a]) continue;
		processed[a] = true;
		for (auto u : adj[a]){
			int b = u.first, w = u.second;
			if(distance[a]+w < distance[b]){
				distance[b] = distance[a] + w;
				q.push({-distance[b], b});
			}
		}
	}
}






