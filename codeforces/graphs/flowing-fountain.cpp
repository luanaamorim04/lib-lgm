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

int n, q, arr[MAXN], prox[MAXN], pai[MAXN], qtd[MAXN];

int find(int x)
{
	if (x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int a, int b)
{
	a = find(a), b = find(b);
	if (a > b) swap(a, b);
  	pai[a] = b;	
}

int32_t main()
{_
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	arr[n+1] = INF;
	pai[n+1] = n+1;
	for (int i = n; i >= 1; i--)
	{
		pai[i] = i;
		prox[i] = i+1;
		while (arr[prox[i]] <= arr[i]) prox[i] = prox[prox[i]];
	}

	while (q--)
	{
		int pos, val;
		char op;
		cin >> op;
		if (op == '?') 
		{
			cin >> pos;
			cout << qtd[pos] << endl;
			continue;
		}
		cin >> pos >> val;
		pos = find(pos);
		while (pos <= n && val != 0)
		{
			int usou = min(val, arr[pos]-qtd[pos]);
			val -= usou;
			qtd[pos] += usou;
			if (qtd[pos] == arr[pos]) join(pos, prox[pos]);
			pos = find(prox[pos]);
		}
	}
}
