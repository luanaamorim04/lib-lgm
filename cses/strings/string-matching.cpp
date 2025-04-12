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
int n, kmp[MAXN], resp;

int32_t main()
{_
	cin >> s >> p;
	s = p + '$' + s;
	kmp[0] = 0;
	for (int i = 1; i < s.size(); i++)
	{
		int j = kmp[i-1];
		while (j > 0 && s[i] != s[j])
			j = kmp[j-1];
		if (s[i] == s[j])
			j++;
		kmp[i] = j;
		if (kmp[i] == p.size()) resp++;
	}
	cout << resp << endl;
}
