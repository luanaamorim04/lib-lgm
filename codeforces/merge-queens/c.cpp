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

int a[MAXN], b[MAXN];

int32_t main()
{_
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>a[i];
	for (int i=1; i<=n; i++) cin>>b[i];
	int resp = b[1]/a[1];
	for (int i=1; i<=n; i++) {
		resp = min(resp, b[i]/a[i]);
	}
	cout<<resp<<endl;
}
