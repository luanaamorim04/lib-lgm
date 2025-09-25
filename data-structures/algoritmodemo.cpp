typedef struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        return make_pair(l / raiz, r) < make_pair(other.l / raiz, other.r);
    }
}Query;

vector<Query> query;

vector<int> mo () {
    // zero-indexado
    vector<int> ans(q+1);
    sort(query.begin(), query.end());
    
    int l_at = 0, r_at = -1;
    int k = 0;
    
    for (Query q : query) {
        while (l_at > q.l) {
            l_at--;
            // aqui fica o código de inserir o elemento l_at na query atual
        }
        while (r_at < q.r) {
            r_at++;
            // aqui fica o código de inserir o elemento r_at na query atual
        }
        while (l_at < q.l) {
            // aqui fica o código de remover o elemento l_at da query atual
            l_at++;
        }
        while (r_at > q.r) {
            // aqui fica o código de remover o elemento r_at da query atual
            r_at--;
        }
        ans[q.idx] = k;
    }
    return ans;
}