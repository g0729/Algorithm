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
    if(N==1){
        cout<<1;
        return;
    }
    if(N%2) {
        cout<<-1;
        return;
    }
    int l = 0, r = 0;
    cout<<N<<" ";
    int cur = 0;
    for(int i=0;i<N-1;i++){
        int l2 = ((l-1)%N+N)%N;
        int r2 = ((r+1)%N+N)%N;
        if(i%2==0){
            cout<<((l2-cur)%N+N)%N<<' ';
            cur = l2;
            l = l2;
        }
        else{
            cout<<((r2-cur)%N+N)%N<<' ';
            cur = r2;
            r = r2;
        }
    }
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