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

void solve() {
    cin>>N;
    vector<int> ipt(N+1);
    for(int i=1;i<=N;i++) cin>>ipt[i];
    vector<int> dp;
    for(int i=1;i<=N;i++){
        auto it = lower_bound(all(dp), ipt[i]);
        if(it==dp.end()){
            dp.push_back(ipt[i]);
        }
        else *it = ipt[i];
    }
    cout<<dp.size();
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