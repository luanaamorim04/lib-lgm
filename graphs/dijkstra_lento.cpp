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
#define INF (1LL<<60)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, m, a1, b1, a2, b2, k, proc[MAXN], dist[MAXN];
string ordem;
char tab[200][200];
vector<ii> grafo[MAXN];

void build(int i, int j, string ord)
{
    int u = i*m + j, qtd = 0;
    int a = i, b = j;
    for (char op : ord)
    {
        int na = a, nb = b;
        if (op == 'U') na -= 1;
        else if (op == 'D') na += 1;
        else if (op == 'L') nb -= 1;
        else nb += 1;

        if (na < 0 || na >= n || nb < 0 || nb >= m) continue;
        if (tab[na][nb] == '1') continue;
        a = na, b = nb;
        qtd++;
    }

    int v = a*m + b;
    grafo[u].push_back({v, qtd});

    //cout << u << ' ' << v << ' ' << qtd << endl;
}

int dijkstra(int ini, int fim)
{
    //cout << "dijks " << ini << ' ' << fim << endl;
    int tam = (n-1)*m + m-1;
    for (int i = 0; i <= tam+1; i++) 
    {
        dist[i] = INF;
        proc[i] = 0;
    }

    dist[ini] = 0;
    for (int i = 0; i <= tam; i++)
    {
        int u = tam+1;
        for (int j = 0; j <= tam; j++)
        {
            if (!proc[j] && dist[j] <= dist[u])
                u = j;
        }

        //cout << "curr: " << u << ' ' << dist[u] << endl;

        proc[u] = 1;
        for (auto[v, w] : grafo[u])
        {
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    return dist[fim];
}



int32_t main()
{_
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];

    cin >> a1 >> b1 >> a2 >> b2;
    cin >> k;
    while (k--)
    {
        cin >> ordem;
        for (int a = 0; a < n; a++)
            for (int b = 0; b < m; b++)
                if (tab[a][b] == '0') build(a, b, ordem);
    }

    int ans = dijkstra(a1*m + b1, a2*m + b2);

    cout << (ans >= INF ? -1 : ans) << endl; 
}
