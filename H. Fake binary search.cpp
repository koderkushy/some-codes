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
    
    int n, k, u; cin>>n>>k;
    n--;
    string a; cin>>a;
    string x,y; x=y=a, u=k;
    for(int i=0; i<n and u; i++){
        if(x[i]=='G') x[i]='L', u--;
    }
    for(int i=n-1; i>-1 and u; i--){
        if(a[i]=='L') x[i]='G', u--;
    }
    u=k;
    for(int i=0; i<n and u; i++){
        if(y[i]=='L') y[i]='G', u--;
    }
    for(int i=n-1; i>-1 and u; i--){
        if(a[i]=='G') y[i]='L', u--;
    }
    
    lol l=1, r=(l<<60)-1, m=(l+r)/2 ; 
    foin{
        if(y[i]=='G') r=m-1;
        else l=m+1;
        m=(l+r)/2;
    }
    cout<<m;
    l=1, r=(l<<60)-1, m=(l+r)/2; 
    foin{
        if(x[i]=='G') r=m-1;
        else l=m+1;
        m=(l+r)/2;
    }
    cout<<' '<<m<<'\n';
    // cout<<x<<'\n'<<y<<'\n';

}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);


    int T=1;  
    cin>>T;
    fo(K,0,T,1) F(K+1);
}