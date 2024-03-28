#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define _unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end())
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define tll tuple<ll, ll, ll>
#define xx first
#define yy second
#define ll long long
const int INF = 1e9;
const ll mod = 1000000007;

int N, M, K;
vector<int> adj[1230100];

void solve() {
    cin>>N>>M;
    vector<pii> ipt(N);
    for(int i=0;i<N;i++) cin>>ipt[i].xx;
    for(int i=0;i<N;i++) cin>>ipt[i].yy;
    int ans = 0;
    if(ipt[0].xx+ipt[0].yy>=M){
        cout<<0;
        return;
    }
    int l = ipt[0].xx+ipt[0].yy;
    for(int i=0;i<N;){
        ans++;
        int j = i;
        int tmp = l;
        for(;j<N&&ipt[j].xx<=l;j++){
            tmp = max(tmp, ipt[j].xx+ipt[j].yy);
        }
        if(tmp==l){
            cout<<-1;
            return;
        }
        l = tmp;
        if(l>=M){
            cout<<ans;
            return;
        }
        i = j;
    }
    cout<<-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(10);

#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    clock_t _st_t = clock();
#endif

    solve();

#ifndef ONLINE_JUDGE
    cerr << endl << endl << (double) (clock() - _st_t) / (double) CLOCKS_PER_SEC << "sec" << endl;
#endif

    return 0;
}