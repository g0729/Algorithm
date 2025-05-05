#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 2505
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Edge
{
    int next, capacity, flow;
    Edge *rev;

    Edge(int next, int capacity) : next(next), capacity(capacity), flow(0) {};
    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};
int n, m;
int source = 2501, sink = 2502;
vector<vector<Edge *>> edges;

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
                if (edge->residual() && parent[next].first == -1)
                {
                    parent[next] = {cur, edge};
                    q.push(next);
                }
            }
        }

        if (parent[sink].first == -1)
            break;

        int min_flow = INF;

        for (int i = sink; i != source; i = parent[i].first)
            min_flow = min(min_flow, parent[i].second->residual());

        for (int i = sink; i != source; i = parent[i].first)
            parent[i].second->update(min_flow);

        res += min_flow;
    }

    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        edges = vector<vector<Edge *>>(MAX, vector<Edge *>());
        vector<vector<int>> v(n, vector<int>(m));
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                res += v[i][j];
            }
        for (int i = 0; i < n; i++)
        {
            for (int j = i % 2 ? 1 : 0; j < m; j += 2)
            {

                int cur = i * m + j;
                add_edge(source, cur, v[i][j]);

                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    int next = nx * m + ny;

                    add_edge(cur, next, INF);
                }
            }
            for (int j = i % 2 ? 0 : 1; j < m; j += 2)
            {
                int cur = i * m + j;
                add_edge(cur, sink, v[i][j]);
            }
        }
        cout << res - mcmf() << "\n";
    }

    return 0;
}
