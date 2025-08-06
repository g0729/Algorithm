#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 5000000
#define INF 987654321
#define gpq priority_queue<ll, vector<ll>, greater<ll>>
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
set<ll> is_visited;
ll score[2];
gpq pq[2];
vector<bool> is_prime(MAX, true);

void eratos() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void not_prime(ll &opponent_score, gpq &opponent_pq) {
    if (opponent_pq.size() < 3)
        opponent_score += 1000;
    else
        opponent_score += opponent_pq.top();
}
void get_score(ll my_num, ll idx) {
    if (!is_prime[my_num])
        not_prime(score[idx ^ 1], pq[idx ^ 1]);
    else {
        if (is_visited.find(my_num) != is_visited.end()) {
            score[idx] -= 1000;
            return;
        }
        is_visited.insert(my_num);
        pq[idx].push(my_num);
        if (pq[idx].size() > 3) pq[idx].pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    eratos();
    ll n;
    cin >> n;

    while (n--) {
        ll a, b;
        cin >> a >> b;
        get_score(a, 0);
        get_score(b, 1);
    }

    if (score[0] > score[1]) {
        cout << "소수의 신 갓대웅";
    } else if (score[0] < score[1]) {
        cout << "소수 마스터 갓규성";
    } else {
        cout << "우열을 가릴 수 없음";
    }
    return 0;
}