#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int A, B, C, D;
set<pair<int, int>> visited;

void validate(int a, int b, queue<pair<int, int>> &q) {
    if (visited.find({a, b}) == visited.end()) {
        q.push({a, b});
        visited.insert({a, b});
    }
}
int bfs() {
    queue<pair<int, int>> q;
    visited.insert({0, 0});
    q.push({0, 0});
    int res = 0;

    while (!q.empty()) {
        int size = q.size();

        while (size--) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (a == C && b == D) return res;

            int nextA, nextB;
            nextA = A, nextB = b;
            validate(nextA, nextB, q);
            nextA = a, nextB = B;
            validate(nextA, nextB, q);

            nextA = 0, nextB = b;
            validate(nextA, nextB, q);
            nextA = a, nextB = 0;
            validate(nextA, nextB, q);

            if (a != 0) {
                nextA = max(a - (B - b), 0), nextB = min(B, b + a);
                validate(nextA, nextB, q);
            }
            if (b != 0) {
                nextA = min(A, a + b), nextB = max(b - (A - a), 0);
                validate(nextA, nextB, q);
            }
        }

        res++;
    }

    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> C >> D;

    cout << bfs();
    return 0;
}