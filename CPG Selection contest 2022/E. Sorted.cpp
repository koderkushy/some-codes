#include "bits/stdc++.h"

using namespace std;


void darling(int kase){

	int n, m; cin >> n >> m;
	string a; cin >> a;

	vector g(26, vector(0, 0));

	for (int i = 0; i < n; i++) {
		g[a[i] - 'a'].push_back(i);
	}

	int mn = -1, ans = 0, cur = 0;

	int c = 0;

	while (c < 26) {
		if (g[c].empty())
			c++;
		else {
			if (g[c].back() < mn or cur == m)
				cur = 0, ans++, mn = -1;
			int took = g[c].back();
			while (g[c].size() and g[c].back() > mn and cur < m) {
				cur++, g[c].pop_back();
			}
			mn = took;
		}
	}
    
    if (cur > 0) ans++;
    
	cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}