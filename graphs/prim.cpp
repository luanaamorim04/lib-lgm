int prim(int n) // n = number of vertices in mst
{
	int resp = 0, qtd = 0;
	vector<int> d(MAXN, INF); //d[u] = smallest distance that u is reachable from vertices in mst 
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({0ll, 1});
	while (!pq.empty())
	{
		auto[val, u] = pq.top(); pq.pop();
		if (d[u] == -INF) continue;
		qtd++, resp += val, d[u] = -INF;
		for (auto[v, w] : grafo[u])
			if (d[v] > w)
			{
				d[v] = w;
				pq.push({d[v], v});
			}
	}

	return (qtd==n?resp:-1);
}
