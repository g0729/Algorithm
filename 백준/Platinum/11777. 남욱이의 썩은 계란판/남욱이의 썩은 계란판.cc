#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct EdgeTemp
{
    int weight, r1, c1, r2, c2;
};

struct Candidate
{
    int weight, u, v;
};

int N, K;
vector<vector<int>> F;
vector<Candidate> candidates;
vector<int> prefixSum;
vector<bool> used;
int bestSum = 0;

void dfs(int idx, int cnt, int sum)
{
    if (cnt == K)
    {
        bestSum = max(bestSum, sum);
        return;
    }
    int rem = K - cnt;
    int sz = candidates.size();
    if (idx >= sz || sz - idx < rem)
        return;
    int ub = sum + (prefixSum[idx + rem] - prefixSum[idx]);
    if (ub <= bestSum)
        return;
    for (int i = idx; i < sz; ++i)
    {
        const auto &e = candidates[i];
        if (!used[e.u] && !used[e.v])
        {
            used[e.u] = used[e.v] = true;
            dfs(i + 1, cnt + 1, sum + e.weight);
            used[e.u] = used[e.v] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    F.assign(N, vector<int>(N));
    ll totalSum = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> F[i][j];
            totalSum += F[i][j];
        }
    }

    const int T = 400; // 상위 T개 후보 유지
    // min-heap: 가장 작은 weight가 top
    struct Cmp
    {
        bool operator()(const EdgeTemp &a, const EdgeTemp &b) const { return a.weight > b.weight; }
    };
    priority_queue<EdgeTemp, vector<EdgeTemp>, Cmp> pq;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j + 1 < N)
            {
                int w = F[i][j] + F[i][j + 1];
                pq.push({w, i, j, i, j + 1});
                if ((int)pq.size() > T)
                    pq.pop();
            }
            if (i + 1 < N)
            {
                int w = F[i][j] + F[i + 1][j];
                pq.push({w, i, j, i + 1, j});
                if ((int)pq.size() > T)
                    pq.pop();
            }
        }
    }

    // 추출 후 내림차순 정렬
    vector<EdgeTemp> top;
    while (!pq.empty())
    {
        top.push_back(pq.top());
        pq.pop();
    }
    sort(top.begin(), top.end(), [](auto &a, auto &b)
         { return a.weight > b.weight; });

    // 좌표 압축
    vector<int> comp;
    comp.reserve(top.size() * 2);
    for (auto &e : top)
    {
        comp.push_back(e.r1 * N + e.c1);
        comp.push_back(e.r2 * N + e.c2);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    // 후보 리스트 생성
    candidates.reserve(top.size());
    for (auto &e : top)
    {
        int id1 = e.r1 * N + e.c1;
        int id2 = e.r2 * N + e.c2;
        int u = lower_bound(comp.begin(), comp.end(), id1) - comp.begin();
        int v = lower_bound(comp.begin(), comp.end(), id2) - comp.begin();
        candidates.push_back({e.weight, u, v});
    }

    // prefix 합 계산
    int M = candidates.size();
    prefixSum.assign(M + 1, 0);
    for (int i = 0; i < M; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].weight;
    }

    used.assign(comp.size(), false);
    dfs(0, 0, 0);

    ll answer = totalSum - bestSum;
    cout << answer << '\n';
    return 0;
}
