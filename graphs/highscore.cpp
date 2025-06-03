#include <bits/stdc++.h>
#define int long long
#define MAXN 2510

using namespace std;

// vc tem um grafo, com arestas com peso
// vc quer saber como ir de 1 pra n acumulando a maior soma dos pesos
// se vc puder somar peso infinito (ciclo positivo), printa -1
// ideia -> multiplicar as arestas por -1 e usar bellman-ford pra identificar ciclos positivos
// ver se o ciclo é alcançável do 1 e alcança o n
// pra isso, faço o bellman-ford pro grafo normal e pro grafo com a direção das arestas invertida
// pego os vértices de ciclo de cada um e checo se tem algum em comum

vector<pair<pair<int, int>, int>> arestas, inv;
int dist[MAXN];
int n, m;

set<int> ciclos(int fonte) {
    // recebe a fonte para começar a busca no grafo
    // retorna um set com todos os vértices que consigo
    // melhorar a dist na última iteração do bellman-ford
    set<int> aux;
    for (int i=1; i<=n; i++) dist[i] = (int)(1e18);
    dist[fonte] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<(int)arestas.size(); j++) {
            int a = (fonte == 1 ? arestas[j].first.first : inv[j].first.first);
            int b = (fonte == 1 ? arestas[j].first.second : inv[j].first.second);
            int c = (fonte == 1 ? arestas[j].second: inv[j].second);
            if (dist[a]!=(int)(1e18)) {
                if (dist[b]>dist[a]+c) {
                    dist[b] = dist[a]+c;
                    if (i==n-1) aux.insert(b);
                }
            }
        }
    }
    return aux;
}

int32_t main () {
    cin>>n>>m;
    while (m--) {
        int a, b, c;
        cin>>a>>b>>c;
        arestas.push_back({{a, b}, -c});
        inv.push_back({{b, a}, -c});
    }
    set<int> x = ciclos(1);
    if (x.size() == 0) {
        cout<<-dist[n]<<endl;
        return 0;
    }
    int ans = -dist[n];
    set<int> y = ciclos(n);
    set<int>::iterator it;
    for (it = x.begin(); it != x.end(); ++it) {
        if (y.find(*it) != y.end()) {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}