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

void F(int kase){
    
    string a, b; cin>>a>>b;
    int ca=0, cb=0, n=a.size();
    foin ca+=a[i]=='1', cb+=b[i]=='1', a[i]=b[i]='0';

    if(ca<cb) swap(ca, cb);

    fo(i,0,ca,1) a[i]='1'; fo(i,ca,n,1) a[i]='0';
    int s=min(n,ca+cb), j=n-1;
    fo(i,s-1,s-cb-1,-1){
        b[i]='1';
        if(a[i]=='1') swap(a[i],a[j]), j--;
    }

    foin{
        if(a[i]!=b[i]) cout<<1;
        else cout<<0;
    }
    cout<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T=1;  
    cin>>T;
    fo(K,0,T,1) F(K+1);
}