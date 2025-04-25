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
int n, resp;

vector<int> build(string s)
{
	vector<int> kmp(MAXN);
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

	return kmp;
}

int32_t main()
{_
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s >> p;
		resp = 0;
		s = p + '$' + s;
		vector<int> kmp;
		kmp = build(s);
		for (int i = 1; i < s.size(); i++)
			if (kmp[i] == p.size()) resp++;
		if (resp == 0)
		{
			cout << "Not Found" << endl;
			cout << endl;
			continue;
		}
		cout << resp << endl;
		for (int i = 1; i < s.size(); i++)
			if (kmp[i] == p.size()) cout << i-2*p.size()+1 << ' ';
		cout << endl;
		cout << endl;
	}
}
