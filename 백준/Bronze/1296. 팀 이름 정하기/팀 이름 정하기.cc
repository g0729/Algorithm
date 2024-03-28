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
    string s; cin>>s;
    int cnt1[4]= {0,};
    for(auto c:s){
        if(c=='L') cnt1[0]++;
        else if(c=='O') cnt1[1]++;
        else if(c=='V') cnt1[2]++;
        else if(c=='E') cnt1[3]++;
    }
    vector<pair<string, int>> v;
    cin>>N;
    for(int i=0;i<N;i++){
        string t; cin>>t;
        int cnt2[4] = {0,};
        for(auto c:t){
            if(c=='L') cnt2[0]++;
            else if(c=='O') cnt2[1]++;
            else if(c=='V') cnt2[2]++;
            else if(c=='E') cnt2[3]++;
        }
        ll sum = 1;
        for(int j=0;j<4;j++){
            for(int l=j+1;l<4;l++){
                sum = (sum*((cnt1[j]+cnt2[j])+(cnt1[l]+cnt2[l])))%100;
            }
        }
        v.emplace_back(t, sum);
    }
    sort(all(v), [&](pair<string, int> x, pair<string, int> y){
        if(x.yy==y.yy) return x.xx<y.xx;
        return x.yy>y.yy;
    });
    cout<<v.front().xx;
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