#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int distance(pair<int, int> &a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solution(int n, int m, vector<vector<int>> timetable)
{
    int answer = 0;
    vector<int> cnt(1321);
    for (int i = 0; i < timetable.size(); i++)
    {
        for (int j = timetable[i][0]; j <= timetable[i][1]; j++)
            cnt[j]++;
    }

    int total_num = *max_element(cnt.begin(), cnt.end());
    if (total_num <= 1)
        return 0;
    for (int dis = 2 * n - 2; dis >= 1; dis--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<pair<int, int>> v = {{i, j}};

                for (int x = i; x < n; x++)
                {
                    for (int y = 0; y < n; y++)
                    {
                        if (x == i && y < j)
                            continue;

                        bool flag = true;

                        for (auto it : v)
                        {
                            if (distance(it, {x, y}) < dis)
                            {
                                flag = false;
                                break;
                            }
                        }
                        if (flag)
                        {
                            v.push_back({x, y});

                            if (v.size() == total_num)
                                return dis;
                        }
                    }
                }
            }
        }
    }
}