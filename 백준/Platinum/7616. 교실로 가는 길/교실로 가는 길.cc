#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
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
int k, n;
int source = 1, sink = 4;
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
        vector<pair<int, Edge *>> parent(n * 2 + 1, {-1, nullptr});

        while (!q.empty())
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

void path_find()
{

    for (int _ = 0; _ < k; _++)
    {
        queue<int> q;
        q.push(source);
        vector<pair<int, Edge *>> parent(n * 2 + 1, {-1, nullptr});

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto edge : edges[cur])
            {
                int next = edge->next;

                if (edge->flow && parent[next].first == -1)
                {
                    q.push(next);
                    parent[next] = {cur, edge};
                }
            }
        }

        stack<int> s;
        for (int i = sink; i != source; i = parent[i].first)
        {
            if (parent[i].first - i == -1 && parent[i].first % 2)
                s.push(i / 2);
            parent[i].second->flow -= 1;
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }

        cout << "\n";
    }
}
int main()
{

    for (int test_case = 1;; test_case++)
    {
        cin >> k >> n;

        edges = vector<vector<Edge *>>(n * 2 + 1, vector<Edge *>());

        if (k == 0 && n == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 2)
                add_edge(i * 2 - 1, i * 2, k);
            else
                add_edge(i * 2 - 1, i * 2, 1);
        }

        for (int i = 1; i <= n; i++)
        {
            int u_in = i * 2 - 1, u_out = u_in + 1;
            while (true)
            {
                char ch;
                int to;
                scanf("%d%c", &to, &ch);
                int v_in = to * 2 - 1, v_out = v_in + 1;
                add_edge(u_out, v_in, 1);
                if (ch == '\n')
                    break;
            }
        }

        int res = mcmf();

        cout << "Case " << test_case << ":\n";

        if (res != k)
            cout << "Impossible\n";
        else
            path_find();
        cout << "\n";
    }

    return 0;
}