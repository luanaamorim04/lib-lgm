vector<array<int, 2> > grafo[MAXN];
int n, m, a, b, c, pos[MAXN];

vector<int> eulerian_path(int s, int n, int m)
{
	vector<int> resp, grau(n+1, 0);
	for (int i = 1; i <= n; i++)
	{
		grau[i] = grafo[i].size();
		if ((grau[i]&1)) return resp;
	}

	stack<int> pilha;
	pilha.push(s);
	while (!pilha.empty())
	{
		int u = pilha.top();
		if (pos[u] >= grafo[u].size())
		{
			pilha.pop();
			resp.push_back(u);
			continue;
		}

		for (; pos[u] < grafo[u].size(); pos[u]++)
		{
			auto &v = grafo[u][pos[u]];
			if (v[1] == -1) continue;
			grafo[v[0]][v[1]][1] = -1;
			grafo[u][pos[u]][1] = -1; 
			pilha.push(v[0]);
			break;
		}
	}

	if (resp.size() != m+1) resp.clear();
	return resp;	
}
 
int32_t main()
{_
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		grafo[a].push_back({b, (int)grafo[b].size()});
		grafo[b].push_back({a, (int)grafo[a].size()-1});
	}

	vector<int> resp = eulerian_path(1, n, m);
	if (resp.size() == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for (int v : resp)
		cout << v << ' ';
	cout << endl;
}

