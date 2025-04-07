int k, n, m, a, b, vis[MAXN], comp[MAXN];
vector<int> grafo[MAXN], rev[MAXN];
stack<int> pilha;

void f(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) f(v);
	pilha.push(u);
}

void dfs(int u, int k)
{
	comp[u] = k;
	for (int v : rev[u])
		if (!comp[v]) dfs(v, k);
}

int32_t main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) if (!vis[i]) f(i);

	while (!pilha.empty())
	{
		int u = pilha.top(); pilha.pop();
		if (comp[u]) continue;
		comp[u] = ++k; //comp[u] = scc of u
		dfs(u, k);
	}
}
