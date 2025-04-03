#include <bits/stdc++.h>
using namespace std;

#define ANS(msg) return void(cout << (msg) << "\n")

#define FOR(x, L, R) for (ll x = (L); x <= (R); x++)
#define RFOR(x, L, R) for (ll x = (R); x >= (L); x--)
#define REP(T) for (ll _ = (T); _--;)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int) (v).size()

#define pb push_back
#define mp make_pair
#define mt make_tuple

#define fi first
#define se second

#ifdef LOCAL
#define DBG(x) x
#else
#define DBG(x) do{}while(0)
#endif

#define double long double

using ll = int64_t;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<pll>;
using pdd = pair<double, double>;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double pi = 3.1415926535897932384626;

// sabendo que b inicia no 0
double calc_intersect(pdd a, pdd b)
{
    if(a.fi > b.se) return 0;
    return min(b.se, a.se) - a.fi;
}

void solve() {
    ll n, X; cin >> n >> X;
    double a, T; cin >> a >> T;
    a = a * 2 * pi / 360;
    ll d; cin >> d;

    for(ll i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        if(x * x + y * y > d * d) {
            cout << 0 << '\n';
            continue;
        }
        double ans = 0, ini = 0, fim = 0;
        ans = floor(X / T) * (a * T / (2 * pi));
        
        double t = 0;
        if(x != 0) t = (atan((double)y / x));
        else t = pi / 2;

        if(t < 0) t += pi;

        fim = ((X / T) - floor(X / T)) * 2 * pi;
        pdd sobra = {0, fim};
		cout << t << endl;

        pdd i1, i2;
        if(t - a / 2  < 0)
        {
            i1 = {0, (t + a / 2)};
            i2 = {2 * pi + (t - a / 2), 2 * pi};
        }
        else
        {
            i1 = {(t - a / 2), (t + a / 2)};
            i2 = {2 * pi, 2 * pi};
        }


        double M = calc_intersect(i1, sobra) + calc_intersect(i2, sobra);

        ans += M * T / (2 * pi);

        cout << setprecision(11) << fixed;
        cout << ans << '\n';
    }

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
    /* Uncomment for multiples test cases */
	// cin >> t;
	REP(t) solve();
	return 0;
}
