#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

#define sz(x) ((int)(x).size())
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define deb(x) cout<<#x<<"="<<x<<nl
#define debs(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<nl
#define debarr(a) cout<<"Arr: ";for(int i=0;i<sz(a);i++){ cout<<a[i]<<" "; } cout<<nl
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

const int mod = 1000000007;
const int MAX = INT_MAX;
const int MIN = INT_MIN;
const char nl = '\n';
const long long INF = 1e18;

vector<vector<int>> a ;
vector<bool> vis ; // 

void dfs(int x){
    if(vis[x])return ;  //  vertex already visited
    vis[x] = true ;
    cout<<x<<" " ; 
    for(auto xx:a[x])dfs(xx) ;
}

/*
I/P :   4 4  //  n-> no. of vertices && m-> no. of edges 
        1 2
        2 3
        3 4
        4 1
        
O/P :   0 1 2 3
        1 2 3 0
        2 3 0 1
        3 0 1 2
*/

void solve(){
    int n ,  m ;  cin>>n >>m  ;
    a.resize(n) ;
    vis.resize(n,false) ;
    for(int i=0;i<m;i++){
        int x , y ; cin>>x>>y  ;
        a[x-1].push_back(y-1) ;
    }
    for(int i=0;i<n;i++) {
        fill(all(vis), false);
        dfs(i);
        cout<<nl ;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.precision(10);cout << fixed;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr) ;
#endif
    int T = 1; //cin >> T;
    while (T--) solve();

}
