/* Dado um texto e várias strings de teste determinar quantos "pedaços" contínuos da string
de referência formam o teste, ou se é impossível
*/

#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> suffix ;

vector<int> suffix_array(string &s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

bool find(string &s, string t){
    int i=0, f=suffix.size()-1;
    while(i<=f){
        int m=(i+f)/2;

        if(s.substr(suffix[m], t.size()) < t)
            i=m+1;

        else if(s.substr(suffix[m], t.size()) > t)
            f=m-1;

        else return true;
    }

    return false;
}

int32_t main(){_
    string s;
    cin>>s;

    suffix = suffix_array(s);

    int q;
    cin>>q;

    while(q--){
        string t;
        cin>>t;

        int ans=1;

        for(int l=0, r=0; r<t.size();){
            if(find(s,t.substr(l, (r-l+1)))){
                r++;
            }
            else if((r-l)==0){
                ans=-1;
                break;
            }
            else{
                ans++;
                l=r;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
