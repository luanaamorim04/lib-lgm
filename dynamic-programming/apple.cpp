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
#define INF (int)(1LL<<40)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, arr[MAXN], resp;

int32_t main()
{_
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	resp = INF;
	for (int mask = 0; mask < (1<<n); mask++)
	{
		int grupo1 = 0, grupo0 = 0;
		for (int i = 0; i < n; i++)
		{
			if (mask&(1<<i)) 
			{
				grupo1 += arr[i];
			}
			else
			{
				grupo0 += arr[i];
			}
		}
		
		resp = min(resp, abs(grupo0 - grupo1));
	}

	cout << resp << endl;
}
