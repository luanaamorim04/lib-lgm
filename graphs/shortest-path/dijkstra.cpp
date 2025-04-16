//complexity: mlog(n)
vector<int> dijkstra(int s, int n) 
{
	vector<int> dist(MAXN);
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
	pq.push({0ll, s});

	while (pq.size()) 
	{
		auto[d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;

		for (auto[v, w] : grafo[u]) 
			if (dist[v] > dist[u] + w) 
			{
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
	}

	return dist;
}
