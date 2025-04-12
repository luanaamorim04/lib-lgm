#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(2e6 + 10)
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
 
string s, p;
vector<int> grafo[MAXN];
int t, n, kmp[MAXN], vis[MAXN], resp, freq[MAXN], tin[MAXN], tout[MAXN];

void dfs(int u)
{
	tin[u] = ++t;
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) dfs(v);
	tout[u] = ++t;
}

int is_anc(int a, int b)
{
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
int32_t main()
{_
	cin >> s;
	n = s.size();
	kmp[0] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		int j = kmp[i-1];
		while (j > 0 && s[i] != s[j])
			j = kmp[j-1];
		if (s[i] == s[j])
			j++;
		kmp[i] = j;
	}

	for (int i = 1; i < s.size(); i++)
	{
		int j = kmp[i];
		while (!vis[j] && j > 0)
		{
			grafo[kmp[j-1]].push_back(j);
			vis[j] = 1;
			j = kmp[j-1];
		}
	}

	memset(vis, 0, sizeof vis);
	for (int i = 1; i < s.size(); i++)
		if (!vis[i]) dfs(i);

//	for (int i = 1; i < s.size(); i++)
//		cout << i << ' ' << tin[i] << ' ' << tout[i] << endl;
 
	tout[0] = INF;
	int resp = 0;
	for (int tam = 1; tam <= n; tam++)
	{
		int i, ok = 1;
		for (i = 2*tam - 1; i < s.size(); i += tam)
			ok &= is_anc(tam, kmp[i]);

		if (ok && is_anc(n%tam, kmp[n-1])) cout << tam << ' '; 
	}

	cout << endl;
}

