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
int n, freq[MAXN], dp[MAXN], kmp[MAXN], vis[MAXN], resp;
 
int32_t main()
{_
	cin >> s;
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

	int resp = 0;
	int j = kmp[s.size()-1];
	while (j > 0)
	{
		if ((n-j)%n == 0)
		j = kmp[j-1];
	}

	for (int i = 1; i < s.size(); i++)
	{
		freq[kmp[i]]++;
		if (vis[kmp[i]]) continue;
		int j = kmp[i];
		while (!vis[j] && j > 0)
		{
			grafo[kmp[j-1]].push_back(j);
			vis[j] = 1;
			j = kmp[j-1];
		}
	}

	for (int i = s.size()-1; i >= 1; i--)
	{
		dp[i] = freq[i];
		for (int j : grafo[i])
			dp[i] += dp[j];
	}
 
	stack<ii> resp;
	int j = kmp[s.size()-1];
	while (j > 0)
	{
		while (j > 0 && s[s.size()-1] != s[j-1])
			j = kmp[j-1];
		resp.push({j, dp[j]+1});
		j = kmp[j-1];
	}
 
	cout << 1+resp.size() << endl;
	while (!resp.empty())
	{
		cout << resp.top().first << ' ' << resp.top().second << endl;
		resp.pop();
	}

	cout << s.size() << ' ' << 1 << endl;
}

