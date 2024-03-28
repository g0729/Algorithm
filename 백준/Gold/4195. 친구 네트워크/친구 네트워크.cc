#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int findRoot(vector<int> &parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = findRoot(parent, parent[x]);
    }
    return parent[x];
}

void unionSet(vector<int> &parent, vector<int> &networkSize, vector<int> &rank, int a, int b)
{
    a = findRoot(parent, a);
    b = findRoot(parent, b);
    if (a != b)
    {
        if (rank[a] < rank[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        networkSize[a] += networkSize[b];
        if (rank[a] == rank[b])
        {
            rank[a]++;
        }
    }
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
        int f;
        cin >> f;
        unordered_map<string, int> userId;
        vector<int> parent, networkSize, rank;
        int idCounter = 0;

        for (int i = 0; i < f; i++)
        {
            string a, b;
            cin >> a >> b;
            if (userId.find(a) == userId.end())
            {
                userId[a] = idCounter++;
                parent.push_back(userId[a]);
                networkSize.push_back(1);
                rank.push_back(0);
            }
            if (userId.find(b) == userId.end())
            {
                userId[b] = idCounter++;
                parent.push_back(userId[b]);
                networkSize.push_back(1);
                rank.push_back(0);
            }
            unionSet(parent, networkSize, rank, userId[a], userId[b]);
            cout << networkSize[findRoot(parent, userId[a])] << "\n";
        }
    }
    return 0;
}
