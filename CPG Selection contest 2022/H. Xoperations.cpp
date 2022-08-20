#include "bits/stdc++.h"

using namespace std;

#define all(x)              x.begin(), x.end()

template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}


void darling(int kase){

    int n; int64_t k; cin >> n >> k;
    vector a(n, 0); cin >> a;

    // for (int x: a) cout << bitset<5>(x) << ' '; cout << '\n';

    vector must_flip(30, false), must_not(30, false);

    auto f = [&](auto&& f, int l, int r, int bit) -> void {
    	if (bit == 0 or l >= r) return;
    	int change = 0;
    	int p = __builtin_ctz(bit);

    	for (int i = l + 1; i < r; i++)
    		if ((a[i] & bit) != (a[i-1] & bit))
    			change++;

    	if (change == 0)
    		f(f, l, r, bit >> 1);
    	else if (change == 1) {
    		if (a[l] & bit) must_flip[p] = 1;
			else must_not[p] = 1;

			int m = l + 1;
			while ((a[m] & bit) == (a[l] & bit))
				m++;
            assert(m < r);

			f(f, l, m, bit >> 1), f(f, m, r, bit >> 1);
    	} else {
    		must_not[p] = must_flip[p] = 1; // impossible
    	}
    };

    f(f, 0, n, 1 << 29);

    for (int i = 0; i < 30; i++) if (must_flip[i] and must_not[i])
    	return void(cout << "-1\n");

    int64_t z = 0;

    k--;

    for (int i = 0; i < 30; i++) {
    	if (must_flip[i])
    		z |= 1 << i;
    	else if (!must_not[i])
    		z |= (k & 1) << i, k >>= 1;
    }

    z |= k << 30;

    cout << z << '\n';


}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T; cin >> T;
    for(int K = 0; K < T; K++)
        darling(K+1);

}