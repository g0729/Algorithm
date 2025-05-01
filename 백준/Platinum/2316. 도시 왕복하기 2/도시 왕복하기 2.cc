#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 802
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct Edge
{
    int next, capacity, flow;
    Edge *rev;

    Edge() : Edge(-1, 0) {};
    Edge(int next, int capacity) : next(next), capacity(capacity), flow(0), rev(nullptr) {};

    int residual() { return capacity - flow; };
};

int n, m;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 1, sink = 4;
void add_edge(int from, int to, int capacity)
{
    Edge *e1 = new Edge(to, capacity);
    Edge *e2 = new Edge(from, 0);

    e1->rev = e2;
    e2->rev = e1;

    edges[from].push_back(e1);
    edges[to].push_back(e2);
}

int mcmf()
{
    int res = 0;

    while (true)
    {
        queue<int> q;
        q.push(source);
        vector<pair<int, Edge *>> parent(MAX, {-1, nullptr});

        while (!q.empty() && parent[sink].first == -1)
        {
            int cur = q.front();
            q.pop();

            for (auto edge : edges[cur])
            {
                int next = edge->next;

                if (edge->residual() > 0 && parent[next].first == -1)
                {
                    parent[next] = {cur, edge};
                    q.push(next);
                }
            }
        }

        if (parent[sink].first == -1)
            break;

        for (int i = sink; i != source; i = parent[i].first)
        {
            parent[i].second->flow += 1;
            parent[i].second->rev->flow -= 1;
        }

        res++;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    add_edge(1, 2, INF);
    add_edge(3, 4, INF);
    for (int i = 3; i <= n; i++)
    {
        int in = i * 2 - 1, out = i * 2;

        add_edge(in, out, 1);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int a_in = a * 2 - 1, a_out = a * 2, b_in = b * 2 - 1, b_out = b * 2;
        add_edge(a_out, b_in, INF);
        add_edge(b_out, a_in, INF);
    }

    cout << mcmf();
    return 0;
}