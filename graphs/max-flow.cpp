/*
problem: find the maximum flow of the graph 
solution: edmonds-karp O(V[E^2])
 */

int n, m, a, b, c;
vector<int> grafo[MAXN];
int cap[MAXN][MAXN];

int bfs(int s, int t, vector<int> &parent)
{
	fill(all(parent), -1);
	parent[s] = 0;
	queue<ii> fila;
	fila.push({s, INF}); // vertice, flow
	while (!fila.empty()) //bfs
	{
		auto[u, flow] = fila.front(); fila.pop();
		if (u == t) return flow;
		for (int v : grafo[u])
		{
			if (parent[v] == -1 && cap[u][v])
			{
				parent[v] = u;
				int new_flow = min(cap[u][v], flow);
				fila.push({v, new_flow});
			}
		}
	}

	return 0;
}

int max_flow(int s, int t)
{
	vector<int> parent(MAXN);
	int flow = 0, new_flow;
	while ((new_flow = bfs(s, t, parent))) //while there is augmenting path
	{
		flow += new_flow;
		int u = t;
		while (u != s) //traverse path 
		{
			int p = parent[u];
			cap[u][p] += new_flow;
			cap[p][u] -= new_flow;
			u = p;
		}
	}

	return flow;
}

int solve() //reads graph
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		if (!cap[a][b] && !cap[b][a]) grafo[a].push_back(b);
		if (!cap[a][b] && !cap[b][a]) grafo[b].push_back(a); //add reverse edge
		cap[a][b] += c;
	}

	return max_flow(1, n);
}
