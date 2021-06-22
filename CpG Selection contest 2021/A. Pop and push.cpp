#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long           lol;
#define veci                vector<int> 
#define pii                 pair<int,int>
#define pb                  push_back
#define ub                  upper_bound
#define lb                  lower_bound
#define all(x)              x.begin(),x.end()
#define fo(i,a,n,p)         for(int i=a;(p<0 and i>n) or (p>0 and i<n);i+=p)
#define foin                fo(i,0,n,1)
#define fojn                fo(j,0,n,1)
#define ff                  first
#define ss                  second    
#define cnu                 continue
#define N                   100001

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] <= a[i] && a[i] <= d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

void F(int kase){
    
    int n; cin>>n;
    veci a(n); foin cin>>a[i];

    int x = lis(a);

    cout<<(n-x+1)/2<<'\n';


}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T=1;  
    cin>>T;
    fo(K,0,T,1) F(K+1);
}