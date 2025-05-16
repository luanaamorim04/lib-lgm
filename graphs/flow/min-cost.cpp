/*
problem: find the minimum cut of the graph 
solution: edmonds-karp O(V[E^2]) + dfs
*/

int n, m, a, b, c;
vector<int> grafo[MAXN];
int grupo[MAXN], cap[MAXN][MAXN], original[MAXN][MAXN];

void dfs(int u)
{
	grupo[u] = 1; //is reachable from s = 1
	for (int v : grafo[u])
	{
		if (cap[u][v] > 0 && !grupo[v])
			dfs(v);
	}
}

vector<ii> min_cut() //vector with all min-cut edges 
{
	int resp = max_flow(1, n); //max-flow and sets capacities
	dfs(1);
	vector<ii> arr;
	//passes through all pairs of vertices
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
			if ((original[j][i] || original[i][j]) && grupo[i] != grupo[j])
				arr.push_back({i, j}); //diferent groups and have an edge
	return arr;
}

void solve() //reads graph
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		if (!cap[a][b] && !cap[b][a]) grafo[a].push_back(b);
		if (!cap[a][b] && !cap[b][a]) grafo[b].push_back(a); //add reverse edge
		cap[a][b]++;
		cap[b][a]++; //undirected no weights
		original[a][b]++; //has an edge
	}

	vector<ii> resp = min_cut();
}
