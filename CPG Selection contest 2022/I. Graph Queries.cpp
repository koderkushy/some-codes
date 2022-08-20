#include "bits/stdc++.h"

using namespace std;

typedef pair<int,int>       pii;
#define pb                  push_back
#define all(x)              x.begin(), x.end()

template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}

struct DSU {
    DSU (int n): z(n, -1) {}

    int head (const int x) {
        if (z[x] < 0) return x;
        return z[x] = head(z[x]);
    }

    int size (const int x) {
        return -z[head(x)];
    }

    bool same (const int x, const int y) {
        return head(x) == head(y);
    }

    bool unite (const int x, const int y) {
        const int& px = head(x), py = head(y);
        if(px == py) return false;
        if(z[px] > z[py])
            z[py] += z[px], z[px] = py;
        else
            z[px] += z[py], z[py] = px;
        return true;
    }

  private:
    std::vector<int> z;
    
};


void darling(int kase){

    int n, m, q; cin >> n >> m >> q;

    vector bit_dsu (30, DSU(n));
    DSU full(n);

    vector g(n, vector(0, pii()));

    for (int i = 0; i < m; i++) {
    	int u, v, w;
        cin >> u >> v >> w, u--, v--;
    	full.unite(u, v);

    	g[u].pb({v, w}), g[v].pb({u, w});
    	for (int p = 0; p < 30; p++, w >>= 1)
    		if (w & 1) bit_dsu[p].unite(u, v);
    }

    vector value (n, 0), visited (n, 0), c(0, 0);

    auto dfs = [&](auto&& dfs, int u) -> unsigned int {
    	visited[u] = 1, c.pb(u);
    	unsigned int value = -1;
    	for (auto [v, w]: g[u]){
            value &= w;
    		if (!visited[v])
    			value &= dfs(dfs, v);
        }
    	return value;
    };

    for (int i = 0; i < n; i++) {
    	if (!visited[i]) {
    		auto val = dfs(dfs, i);
    		for (auto v: c) value[v] = val;
    		c.clear();
    	}
    }

    while (q--) {
    	int u, v;
    	unsigned int x;
    	cin >> u >> v >> x;
    	u--, v--;

    	bool found = false;

    	for (int mask = 1 << 29, p = 29; mask > x; mask >>= 1, p--)
    		if (bit_dsu[p].same(u, v)) found = true;

    	if (full.same(u, v)) {
    		auto val = value[u];
    		if ((val ^ x) > (val & x))
    			found = true;
    	}

    	cout << (found? "YES\n": "NO\n");
    }

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}