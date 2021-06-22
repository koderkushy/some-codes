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

auto cmp=[](pii a, pii b) {
        return (a.ff+a.ss-1)/a.ss > (b.ff+b.ss-1)/b.ss ;
};


void F(int kase){
    
    int n, k; cin>>n>>k;
    int a[n]; foin cin>>a[i];

    multiset<pii, decltype(cmp)> s(cmp); s.insert({a[0],1});
    fo(i,1,n,1) s.insert({a[i]-a[i-1],1});

    while(k--){
        auto [d,e] = *(s.begin());
        s.erase(s.begin());
        s.insert({d,e+1});
        auto [l,r] = *(s.begin());

        cout<<max(1,(l+r-1)/r)<<' ';

    }

    cout<<'\n';


}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T=1;  
    cin>>T;
    fo(K,0,T,1) F(K+1);
}