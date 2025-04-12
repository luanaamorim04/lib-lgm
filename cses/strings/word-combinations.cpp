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

vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int dfs(int u)
{
	if (dist[u]) return dist[u];
	for (int v : grafo[u])
		dist[v] = max(dist[v], dfs(v));

	return dist[v];
}

int n, k;
string s, arr[MAXN];
vector<int> grafo[MAXN];
int32_t main()
{_
	cin >> s >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> arr[i];
		string ss = arr[i] + '$' + s;
		vector<int> pos = z_function(ss);
		for (int j = 0; j < pos.size(); j++)
		{
			if (pos[j] == arr[i].size())
			{
				grafo[j - arr[i].size() - 1].push_back(j);
			}
		}
	}

	for (int i = 0)

	cout << "a" << endl;
}
