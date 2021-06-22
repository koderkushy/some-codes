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
#define foin                fo(i,1,n+1,1)
#define fojn                fo(j,0,n,1)
#define ff                  first
#define ss                  second    
#define cnu                 continue
#define N                   100001

veci g[N], a(N,0);

int dfs(int i, int p){
    if(i!=1 and g[i].size()==1){
        return 1-a[i];
    }
    int c=0;
    for(int x: g[i]){
        if(x==p) cnu;
        c+=dfs(x,i);
    }
    // cout<<i<<' '<<c<<'\n';
    return max(0,c-a[i]);
}

void F(int kase){
    
    int n; cin>>n;
    fo(i,1,n,1){
        int u,v; cin>>u>>v;
        g[u].pb(v), g[v].pb(u);
    }
    
    foin cin>>a[i];
    if(n==1){
        cout<<a[1]<<'\n';
        a[1]=0; return;
    }
    int y=dfs(1,0);
    fo(i,2,n+1,1) if(g[i].size()==1) y--;

    cout<<-y<<'\n';

    foin g[i].clear(), a[i]=0;

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T=1;  
    cin>>T;
    fo(K,0,T,1) F(K+1);
}