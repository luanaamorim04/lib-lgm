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

int n, pa, pb, ia, ib;

int32_t main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		x &= 1;
		pa += (x != 0);
		ia += (x == 0);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		x &= 1;
		pb += (x != 0);
		ib += (x == 0);
	}
	cout << (ia == pb && pa == ib ? "SIM" : "NAO") << endl;

}
