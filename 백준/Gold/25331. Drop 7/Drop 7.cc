#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321

vector<vector<int>> MAP(7, vector<int>(7));
vector<vector<int>> cMAP(7, vector<int>(7));

vector<pair<int, int>> group_check()
{
    vector<pair<int, int>> deleting_list;

    for (int i = 0; i < 7; i++)
    {
        vector<pair<int, int>> temp;
        for (int j = 0; j <= 7; j++)
        {
            if (j == 7 || MAP[i][j] == 0)
            {
                if (temp.empty())
                    continue;
                int size = temp.size();
                for (auto it : temp)
                {
                    if (it.first == size)
                        deleting_list.push_back({i, it.second});
                }
                temp.clear();
            }
            else
                temp.push_back({MAP[i][j], j});
        }
    }

    for (int i = 0; i < 7; i++)
    {
        vector<pair<int, int>> temp;
        for (int j = 0; j <= 7; j++)
        {
            if (j == 7 || MAP[j][i] == 0)
            {
                if (temp.empty())
                    continue;
                int size = temp.size();
                for (auto it : temp)
                {
                    if (it.first == size)
                        deleting_list.push_back({it.second, i});
                }

                temp.clear();
            }
            else
                temp.push_back({MAP[j][i], j});
        }
    }
    return deleting_list;
}
void deleting(vector<pair<int, int>> &deleting_list)
{
    for (int i = 0; i < deleting_list.size(); i++)
    {
        int x = deleting_list[i].first;
        int y = deleting_list[i].second;
        MAP[x][y] = 0;
    }
}
void fall()
{
    for (int i = 0; i < 7; i++)
    {
        vector<int> temp;
        for (int j = 6; j >= 0; j--)
        {
            if (MAP[j][i] != 0)
            {
                temp.push_back(MAP[j][i]);
                MAP[j][i] = 0;
            }
        }
        for (int j = 6; j > 6 - temp.size(); j--)
        {
            MAP[j][i] = temp[6 - j];
        }
    }
}
int top_idx(int col)
{
    for (int i = 0; i < 7; i++)
    {
        if (cMAP[i][col] != 0)
            return i - 1;
    }

    return 6;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> cMAP[i][j];
        }
    }
    int n;
    cin >> n;
    int res = 50;
    for (int i = 0; i < 7; i++)
    {
        int idx = top_idx(i);
        MAP = cMAP;
        MAP[idx][i] = n;
        while (1)
        {
            vector<pair<int, int>> deleting_list = group_check();
            if (deleting_list.empty())
                break;
            deleting(deleting_list);
            fall();
        }
        int cnt = 0;
        for (int j = 0; j < 7; j++)
        {
            for (int k = 0; k < 7; k++)
            {
                if (MAP[j][k])
                    cnt++;
            }
        }
        res = min(res, cnt);
    }

    cout << res;
    return 0;
}