#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, m, k, arr[MAXN], a, b, dist[MAXN][12];
vector<ii> grafo[MAXN];
void dijkstra(int s, int n) 
{
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 11; j++)
			dist[i][j] = INF;
	dist[1][0] = 0;
	pq.push({0ll, 0ll, 1ll});

	while (!pq.empty()) 
	{
		auto[d,qtd,u] = pq.top(); pq.pop();
		if (d > dist[u][qtd]) continue;

		for (auto[w, v] : grafo[u]) 
		{
			if (qtd+w>k) continue;
			if (dist[v][qtd+w] > dist[u][qtd] + 1) 
			{
				dist[v][qtd+w] = dist[u][qtd] + 1;
				pq.push({dist[v][qtd+w], qtd+w, v});
			}
		}
	}
}
int32_t main()
{_
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back({arr[a] != arr[b], b});
		grafo[b].push_back({arr[a] != arr[b], a});
	}


	dijkstra(1, n);
	int resp = INF;
	for (int i=0; i<=k; i++) {
		resp = min(resp, dist[n][i]);
	}
	cout << (resp == INF ? -1 : resp)  << endl;
}
