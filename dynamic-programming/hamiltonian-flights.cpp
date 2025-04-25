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

int n, m, a, b, dp[25][MAXN];
vector<int> grafo[MAXN];

int tsp(int u, int mask)
{
	if (__builtin_popcount(mask) == n) return (u == n-1);
	if (dp[u][mask] != -1) return dp[u][mask];
	int resp = 0;
	for (int v : grafo[u])
	{
		if (mask&(1<<v)) continue;
		else resp = (resp + tsp(v, mask|(1<<v))) % MOD;
	}

	return dp[u][mask] = resp;
}

int32_t main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a-1].push_back(b-1);
	}
	memset(dp, -1, sizeof dp);
	cout << tsp(0, 1) << endl;
}
