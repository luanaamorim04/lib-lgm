#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(8e3 + 10)
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
int t, n, d[MAXN], dp[MAXN];
vector<int> kmp[MAXN];

vector<int> build(int idx)
{
	vector<int> kmp(MAXN);
	kmp[0] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		int j = kmp[i-1];
		while (j > 0 && s[i+idx] != s[j+idx])
			j = kmp[j-1];
		if (s[i+idx] == s[j+idx])
			j++;
		kmp[i] = j;
	}

	return kmp;
}

int32_t main()
{_
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
	{
		int x = i;
		while (x)
		{
			d[i]++;
			x /= 10;
		}
		kmp[i] = build(i-1);

		dp[i] = dp[i-1] + 2;
		for (int j = 1; j < i; j++) //interval j-i 
		{
			int tam = i-j+1;
			if (tam%(tam-kmp[j][i-j]) == 0)
			    dp[i] = min(dp[i], dp[j-1] + d[tam/(tam-kmp[j][i-j])] + tam-kmp[j][i-j]);
			dp[i] = min(dp[i], dp[j-1] + 1 + tam);
		}
	}

	cout << dp[n] << endl;
}
