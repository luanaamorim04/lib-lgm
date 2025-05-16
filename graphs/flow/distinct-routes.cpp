/*
problem: distinct routes - find the number of disjoint paths from 1 to n 
solution: edmonds-karp O(V[E^2])
 */

int n, m, a, b, c;
vector<int> grafo[MAXN], vis(MAXN);
int pai[MAXN], cap[MAXN][MAXN], original[MAXN][MAXN];

void dfs(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
	{
		if (original[u][v] && cap[v][u] && !vis[v]) 
		{
			pai[v] = u;
			dfs(v);
		}
	}
}

int solve() 
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		if (!cap[a][b] && !cap[b][a]) grafo[a].push_back(b);
		if (!cap[a][b] && !cap[b][a]) grafo[b].push_back(a); //add reverse edge
		cap[a][b] = 1;
		original[a][b] = 1;
	}

	int resp = max_flow(1, n);
	cout << resp << endl;
	while (resp--)
	{
		vector<int> path;
		fill(all(vis), 0);
		dfs(1);
		int u = n;
		while (u != 1)
		{
			path.push_back(u);
			cap[u][pai[u]] = 0;
			u = pai[u];
		}
		path.push_back(1);
		reverse(all(path));
		cout << path.size() << endl;
		for (int u : path) cout << u << ' ';
		cout << endl;
	}
	return 0;
}
