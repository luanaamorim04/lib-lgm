#include <bits/stdc++.h>
//#define int long long
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

/*
problem: how many "abc" substrings are there in the string, with point updates
solution: segtree
 */

struct tree
{
	int abc, bc, ab, a, b, c;
};

tree st[MAXN<<2];
int n, m, pos, q;
char c, arr[MAXN];

tree merge(tree &r, tree esq, tree dir)
{
	r.a = esq.a + dir.a;
	r.b = esq.b + dir.b;
	r.c = esq.c + dir.c;
	r.ab = esq.ab + dir.ab + min(esq.a - esq.ab, dir.b - dir.ab);
	r.bc = esq.bc + dir.bc + min(esq.b - esq.bc, dir.c - dir.bc);
	int novo1 = min(esq.a - esq.ab, dir.bc - dir.abc);
	int novo2 = min(esq.ab - esq.abc , dir.c - dir.bc);
	int novo3 = min(esq.ab - (esq.abc + novo2), dir.bc - (dir.abc + novo1));
	r.abc = esq.abc + dir.abc + novo1 + novo2 + novo3;
	return r;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {0, 0, 0, arr[i] == 'a', arr[i] == 'b', arr[i] == 'c'};
		return;
	}
	int mid = (i+j)/2;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	merge(st[idx], st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, tree val) //point update
{
	if (i == j)
	{
		st[idx] = val;
		return;
	}
	int mid = (i+j)/2;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	merge(st[idx], st[esq(idx)], st[dir(idx)]);
}


int32_t main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	while (q--)
	{
		cin >> pos >> c;
		update(1, 1, n, pos, {0ll, 0ll, 0ll, c == 'a', c == 'b', c == 'c'});
		cout << st[1].abc << endl;
	}

}
