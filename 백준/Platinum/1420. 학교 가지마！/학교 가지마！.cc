#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 20005
#define INF 987654321
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

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
int n, m;
vector<vector<Edge *>> edges(MAX, vector<Edge *>());
int source = -1, sink = -1;
void add_edge(int u_in, int u_out, int v_in, int v_out)
{
    Edge *u_out_v_in = new Edge(v_in, INF);
    Edge *v_in_u_out = new Edge(u_out, 0); // 역 방향의 유령 간선

    u_out_v_in->rev = v_in_u_out;
    v_in_u_out->rev = u_out_v_in;
    edges[u_out].push_back(u_out_v_in);
    edges[v_in].push_back(v_in_u_out);

    Edge *v_out_u_in = new Edge(u_in, INF);
    Edge *u_in_v_out = new Edge(v_out, 0); // 역 방향의 유령 간선

    v_out_u_in->rev = u_in_v_out;
    u_in_v_out->rev = v_out_u_in;
    edges[v_out].push_back(v_out_u_in);
    edges[u_in].push_back(u_in_v_out);
}

int mcmf()
{
    int total_flow = 0;

    while (1)
    {
        vector<int> parent(MAX, -1);
        vector<Edge *> edge_to_child(MAX);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1)
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < edges[u].size(); ++i)
            {
                Edge *uv = edges[u][i];
                int v = uv->next;
                if (uv->residual() > 0 && parent[v] == -1)
                {
                    q.push(v);
                    parent[v] = u;
                    edge_to_child[v] = uv;
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int amount = INF;
        for (int p = sink; p != source; p = parent[p])
        {
            Edge *parent_to_p = edge_to_child[p];
            amount = min(amount, parent_to_p->residual());
        }

        for (int p = sink; p != source; p = parent[p])
        {
            Edge *parent_to_p = edge_to_child[p];
            parent_to_p->update(amount);
        }

        total_flow += amount;
    }
    return total_flow;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> source_pos = {-1, -1}, sink_pos = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'K')
                source_pos = {i, j};
            else if (v[i][j] == 'H')
                sink_pos = {i, j};
        }
    }

    if (source_pos.first == -1 || sink_pos.first == -1)
    {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {

        int nx = source_pos.first + dx[i], ny = source_pos.second + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (nx == sink_pos.first && ny == sink_pos.second)
        {
            cout << "-1";
            return 0;
        }
    }
    for (int i = 0; i < n * m * 2; i += 2)
    {
        Edge *e1 = new Edge(i + 1, 1);
        Edge *e2 = new Edge(i, 0);
        e1->rev = e2;
        e2->rev = e1;
        edges[i].push_back(e1);
        edges[i + 1].push_back(e2);
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int next_r, next_c;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            if (v[r][c] == '#')
                continue;
            visited[r][c] = true;

            int u_in = ((r * m) + c) * 2, u_out = u_in + 1;
            for (int i = 0; i < 4; ++i)
            {
                next_r = r + dx[i];
                next_c = c + dy[i];

                // 범위 확인
                if (next_r < 0 || n <= next_r || next_c < 0 || m <= next_c)
                    continue;

                if (v[next_r][next_c] == '#')
                    continue;

                if (!visited[next_r][next_c])
                {
                    int v_in = ((next_r * m) + next_c) * 2, v_out = v_in + 1;
                    add_edge(u_in, u_out, v_in, v_out);
                }
            }
        }
    }

    source = (source_pos.first * m + source_pos.second) * 2 + 1;
    sink = (sink_pos.first * m + sink_pos.second) * 2;
    cout << mcmf() << "\n";
    return 0;
}