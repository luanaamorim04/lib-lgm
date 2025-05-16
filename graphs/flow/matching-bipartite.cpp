/*
problem: find the maximum number of edges on a bipartite graph, such that no two edges share a vertex 
solution: do max-flow algorithm and check if the reverse edges have flow 
 */

int n, m, a, b, c;
vector<int> grafo[MAXN];
int cap[MAXN][MAXN];

int solve() //reads graph
{_
	int k;
	cin >> n >> m >> k; //boys, girls and pairs
	while (k--)
	{
		cin >> a >> b; //boy, girl
		b += n;
		if (!cap[a][b] && !cap[b][a]) grafo[a].push_back(b);
		if (!cap[a][b] && !cap[b][a]) grafo[b].push_back(a); //add reverse edge
		cap[a][b]++;
	}

	for (int i = 1; i <= n; i++) //create a source
	{
		grafo[0].push_back(i);
		grafo[i].push_back(0);
		cap[0][i] = 1;
	}
	for (int i = n+1; i <= n+m; i++) //create an end
	{
		grafo[n+m+1].push_back(i);
		grafo[i].push_back(n+m+1);
		cap[i][n+m+1] = 1;
	}
	max_flow(0, n+m+1);
	vector<ii> resp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = n+1; j <= m+n; j++)
		{
			if (cap[j][i] > 0) //reversed edge
				resp.push_back({i, j});
		}
	}

	cout << resp.size() << endl;
	for (auto[a, b] : resp)
		cout << a << ' ' << b-n << endl;
	return resp.size();
}
