#include <bits/stdc++.h>
#define PICOS 1
#define VALES 0
#define int long long
#define MAXN (int) (3e3 + 10)
#define MAXM (int) 1e16
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define INF (int) (1e18)

using namespace std;
struct Func
{
	int a, b;
	int val(int x) 
	{
		return a*x + b;
	}	
};

struct tree
{
	Func g;
	int esq, dir;
};


vector<tree> st[2];
int n, m, pref[MAXN], arr[MAXN], peak[MAXN][MAXN], vale[MAXN][MAXN], suff[MAXN], r[MAXN], l[MAXN];

int novo(int flag)
{
	tree r = {{(int)1e9, (int)1e9}, -1, -1};
	st[flag].push_back(r);
	return st[flag].size() - 1;
}

void update(Func curr, int flag, int idx = 0, int i = 0, int j = MAXM-1)
{
	int mid = (i+j)>>1;
	int meio = st[flag][idx].g.val(mid) > curr.val(mid);
	int ini = st[flag][idx].g.val(i) > curr.val(i);
	if (meio) swap(st[flag][idx].g, curr);
	if (j-i <= 1) return;
	if (st[flag][idx].esq == -1) st[flag][idx].esq = novo(flag);
	if (st[flag][idx].dir == -1) st[flag][idx].dir = novo(flag);
	if (ini != meio) update(curr, flag, st[flag][idx].esq, i, mid);
	else update(curr, flag, st[flag][idx].dir, mid+1, j);
}

int query(int pos, int flag, int idx = 0, int i = 0, int j = MAXM-1)
{
	if (j-i <= 0) 
		return st[flag][idx].g.val(pos);
	int mid = (i+j)>>1;
	if (st[flag][idx].esq == -1) st[flag][idx].esq = novo(flag);
	if (st[flag][idx].dir == -1) st[flag][idx].dir = novo(flag);
	if (pos <= mid) return min(st[flag][idx].g.val(pos), query(pos, flag, st[flag][idx].esq, i, mid));
	return min(st[flag][idx].g.val(pos), query(pos, flag, st[flag][idx].dir, mid+1, j));
}

 
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pref[i] = pref[i-1] + arr[i];
		l[i] = l[i-1] + arr[i]*i;
		r[i] = r[i-1] + arr[i]*(n-i);
	}
//	for (int i = n; i >= 1; i--)
//	for (int i = 1; i <= n; i++)
//		cout << r[i] << ' ';
//	cout << endl;
 
 
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++) 
			peak[i][j] = vale[i][j] = INF;
	peak[0][0] = 0;
//	update({0, 0}, VALES);
 
	for (int s = 1; s <= m; s++)
	{
		novo(PICOS);
		novo(VALES);
		update({0, 0}, PICOS);
		for (int i = 0; i <= n; i++)
		{
//			for (int j = 0; j < i; j++) //ultimo peak
//			{
//				vale[s][i] = min(vale[s][i], peak[s-1][j] + r[i] - r[j] - (n-i)*(pref[i] - pref[j]));
//			}
//
			vale[s][i] = r[i] - n*pref[i] + i*pref[i] + query(i, PICOS);
			update({-pref[i], n*pref[i] - r[i] + peak[s-1][i]}, PICOS);
 
//			cout << query(i, PICOS) << endl;
//			printf("vale[%lld][%lld] = %lld\n", s, i, vale[s][i]);
 
//			for (int j = 0; j < i; j++) //ultimo vale 
//			{
//				peak[s][i] = min(peak[s][i], vale[s][j] + l[i] - l[j] - (j+1)*(pref[i]-pref[j]));
//			}
 
			update({-i, vale[s][i] + i*pref[i] - l[i]}, VALES);
			peak[s][i] = l[i] + query(pref[i], VALES);
 
//			printf("pico[%lld][%lld] = %lld\n\n", s, i, peak[s][i]);
		}
 
		st[0].clear();
		st[1].clear();
	}	
 
	cout << min(vale[m][n], peak[m][n]) << endl;
}
