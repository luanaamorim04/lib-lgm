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
#define PI 3.1415926535897932384626 
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct tpoint
{
    double x, y;

    tpoint operator +(tpoint q) const
    {
        return {x + q.x, y + q.y};
    }
    tpoint operator -(tpoint q) const
    {
        return {x - q.x, y - q.y};
    }

    bool operator<(const tpoint& q) const {
        if(x != q.x) return x<q.x;
        return y<q.y;
    }
    double operator ~() const
    {
        return hypot(x, y);
    }
    double operator *(tpoint q) const
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(tpoint q) const
    {
        return (x*q.y - y*q.x);
    }
};

tpoint ponto[MAXN];
int n;
double tot, a, ang, p, dist, tempo[MAXN], angulo[MAXN];

int32_t main()
{_
	cin >> n >> tot;
	cin >> a >> p >> dist;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		if (x*x + y*y > dist*dist)
		{
			cout << 0 << endl;
			continue;
		}
		if (x == 0) ang = 90; 
		else ang = atan(y/x)*180/PI;
		if (ang < 0) ang = 180 - ang;

		int voltas = floor(tot / p);
		double janela = a*p/360;
		double last = (tot - floor(tot/p)*p)*360/p; //angulo final
		double tempo = voltas*janela;
		double sobra = 0;
		if (ang < a/2)
		{
			double metade1 = ang + a/2;
			double metade2 = a/2 - ang;	
			sobra = min(last, metade2) + min(metade1, last);
		}
		else
		{
			sobra = min(last, ang + a/2) - ang + a/2;
		}

		sobra = max(sobra, 0.0);
		sobra = sobra*p/360;
		cout << fixed << setprecision(10) << tempo+sobra << endl;
	}
	return 0;
}
















