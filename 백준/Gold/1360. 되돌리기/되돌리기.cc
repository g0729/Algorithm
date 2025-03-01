#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<string, string>> v;
    vector<int> times;
    for (int i = 0; i < n; i++)
    {
        string op, chr;
        int time;
        cin >> op >> chr >> time;
        if (op == "type")
        {
            if (i == 0)
                v.push_back({"", chr});
            else
            {
                string temp = v.back().second, next = v.back().second + chr;
                v.push_back({temp, next});
            }
        }
        else if (op == "undo")
        {
            if (i == 0)
                v.push_back({"", ""});
            else
            {
                int undo_time = time - stoi(chr);

                int idx = v.size() - 1;

                for (; idx >= 0 && times[idx] >= undo_time; idx--)
                {
                }
                idx++;
                if (idx == v.size())
                    v.push_back({v.back().second, v.back().second});
                else
                {
                    string next = v[idx].first;
                    v.push_back({v.back().second, next});
                }
            }
        }
        times.push_back(time);
    }
    cout << v.back().second;
    return 0;
}