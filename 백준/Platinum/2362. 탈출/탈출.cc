#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 20005
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Edge
{
    int next, capacity, flow;
    Edge *rev;

    Edge(int next, int capacity) : next(next), capacity(capacity) {};

    int residual() { return capacity - flow; };
    void update(int flow)
    {
        this->flow += flow;
        this->rev->flow -= flow;
    }
};
int n, p;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = 0, sink = 20004;
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

    cin >> n >> p;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cur = i * n + j;
            int cur_in = cur * 2 + 1, cur_out = cur_in + 1;

            if (v[i][j] == '+')
                continue;
            else if (v[i][j] == 'X')
            {
                add_edge(cur_in, cur_out, INF);
                add_edge(source, cur_in, INF);
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (v[nx][ny] == 'O')
                    {
                        cout << "No";
                        return 0;
                    }
                }
            }
            else if (v[i][j] == 'O')
            {
                add_edge(cur_in, cur_out, INF);
                add_edge(cur_out, sink, INF);
            }
            else if (v[i][j] == '.')
            {
                add_edge(cur_in, cur_out, 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == '+')
                continue;

            int cur = i * n + j;
            int cur_in = cur * 2 + 1, cur_out = cur_in + 1;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (v[nx][ny] == '+')
                    continue;

                int next_in = (nx * n + ny) * 2 + 1, next_out = next_in + 1;

                add_edge(cur_out, next_in, INF);
            }
        }
    }

    int res = mcmf();

    if (res <= p)
        cout << "Yes\n"
             << res;
    else
        cout << "No";
    return 0;
}