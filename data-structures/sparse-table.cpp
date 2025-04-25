int tab[MAXN][MAXL];

void build()
{
    for (int i = 1; i <= n; i++)
        tab[i][0] = arr[i];
    for (int i = 1; i < MAXL; i++)
        for (int j = 1; j <= n; j++)
            tab[j][i] = __gcd(tab[j][i-1], tab[j+(1<<(i-1))][i-1]);
}
 
int query(int l, int r)
{
    int msb = 31 - __builtin_clz(r-l+1);
    int esq = tab[l][msb];
    int dir = tab[r - (1<<msb) + 1][msb];
    return __gcd(esq, dir);
}
