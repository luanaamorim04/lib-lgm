#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 18
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int tam[MAXN], sub[MAXN], h[MAXN], arr[MAXN], val[MAXN], pai[MAXN], pos[MAXN], tempo, t, n, m, a, b, c, k, tin[MAXN], tout[MAXN], up[MAXL][MAXN];
vector<int> st[MAXN], lazy[MAXN];
vector<ii> grafo[MAXN];

void push(int idx, int i, int j, int k)
{
    if (lazy[k][idx] == 1) return;
    st[k][idx] = (st[k][idx] * lazy[k][idx]) % MOD;
    if (i != j)
    {
        lazy[k][esq(idx)] = (lazy[k][esq(idx)]*lazy[k][idx]) % MOD;
        lazy[k][dir(idx)] = (lazy[k][dir(idx)]*lazy[k][idx]) % MOD;
    }

    lazy[k][idx] = 1;
}

void build_seg(int idx, int i, int j, int k)
{
	if (i == j)
	{
        lazy[k][idx] = 1;
		st[k][idx] = arr[i+pos[k]-1];
		return;
	}

	int mid = ((i+j)>>1);
	build_seg(esq(idx), i, mid, k);
	build_seg(dir(idx), mid+1, j, k);
	st[k][idx] = (st[k][esq(idx)] + st[k][dir(idx)]) % MOD;
    lazy[k][idx] = 1;
}

void update_seg(int idx, int i, int j, int l, int r, int val, int k)
{
    push(idx, i, j, k);
    if (i > r || j < l) return;
	if (i >= l && j <= r) 
	{
		lazy[k][idx] = val;
        push(idx, i, j, k);
		return;
	}

	int mid = ((i+j)>>1);
	update_seg(esq(idx), i, mid, l, r, val, k);
	update_seg(dir(idx), mid+1, j, l, r, val, k);
	st[k][idx] = (st[k][esq(idx)] + st[k][dir(idx)]) % MOD;
}

int query_seg(int idx, int i, int j, int l, int r, int k)
{
	if (i > r || j < l) return 0;
	if (i >= l && j <= r) return st[k][idx];

	int mid = ((i+j)>>1);
	int x = query_seg(esq(idx), i, mid, l, r, k);
	int y = query_seg(dir(idx), mid+1, j, l, r, k); 
	return (x + y) % MOD;
}

void dfs(int u, int p)
{
    tin[u] = ++tempo;
    up[0][u] = p;
    for (int i = 1; i < MAXL; i++)
        up[i][u] = up[i-1][up[i-1][u]];

	sub[u] = 1;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		ii &par = grafo[u][i];
        auto[v, w] = par;
		if (v == p)
        {
            val[u] = w;
            continue;
        }
		dfs(v, u);
		sub[u] += sub[v];
		if (sub[v] >= sub[grafo[u][0].first]) swap(par, grafo[u][0]);
	}

    tout[u] = ++tempo;
}

void build_hld(int u, int p)
{
	pai[u] = p, pos[u] = ++t, arr[t] = val[u], tam[h[u]]++;
	for (int i = 0; i < grafo[u].size(); i++)
	{
		int &v = grafo[u][i].first;
		if (v == p) continue;
		h[v] = (!i ? h[u] : v);
		build_hld(v, u);
	}
}

void build()
{
	dfs(1, 0);
	h[1] = 1, k = t = 0;
	build_hld(1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (h[i] == i) 
		{
			st[i].resize(tam[i]<<2);
            lazy[i].resize(tam[i]<<2);
			build_seg(1, 1, tam[i], i);
		}
	}
}

int query(int a, int b)
{
	if (pos[a] < pos[b]) swap(a, b);
	if (h[a] == h[b]) return query_seg(1, 1, tam[h[a]], pos[b]-pos[h[a]]+1, pos[a]-pos[h[a]]+1, h[a]);
	return (query_seg(1, 1, tam[h[a]], 1, pos[a]-pos[h[a]]+1, h[a]) + query(pai[h[a]], b)) % MOD;
}

void update(int a, int b, int x)
{
	if (pos[a] < pos[b]) swap(a, b);
	if (h[a] == h[b]) return update_seg(1, 1, tam[h[a]], pos[b]-pos[h[a]]+1, pos[a]-pos[h[a]]+1, x, h[a]);
	update_seg(1, 1, tam[h[a]], 1, pos[a]-pos[h[a]]+1, x, h[a]);
    update(pai[h[a]], b, x);
}

int is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){

    for (int i = MAXL-1; i >= 0; i--){
        if (up[i][v] && !is_anc(up[i][v], u))
            v = up[i][v]; 
    }

    return v;
}

int solve(int a, int b, int x)
{
    if (a == b) return 0;
    if (is_anc(a, b))
    {
        int lca_b = lca(a, b);
        update(b, lca_b, x);
        return query(b, lca_b);
    }
    if (is_anc(b, a))
    {
        int lca_a = lca(b, a);
        update(a, lca_a, x);
        return query(a, lca_a);
    }

    int lca_a = lca(b, a);
    int lca_b = lca(a, b);
    update(a, lca_a, x);
    update(b, lca_b, x);
    return (query(a, lca_a) + query(b, lca_b)) % MOD;
}

int32_t main()
{_
    cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
		grafo[b].push_back({a, c});
	}

	build();
	while (m--)
	{
        int x;
		cin >> a >> b >> x;
		cout << solve(a, b, x) << endl;
	}
}
