#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 100000
#define INF 987654321
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, hp;
int res = 1e9;
vector<pair<int, int>> skills;

void f(int cur_hp, int time, vector<int> cooldown)
{
    if (cur_hp <= 0)
    {
        res = min(res, time);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> nextcool(cooldown);
        int next_time = time;
        if (cooldown[i] != 0)
        {
            next_time += cooldown[i];
            int temp = cooldown[i];
            for (int j = 0; j < n; j++)
                nextcool[j] = max(nextcool[j] - temp, 0);
        }
        next_time += 1;
        nextcool[i] = skills[i].first;
        for (int j = 0; j < n; j++)
            nextcool[j] = max(nextcool[j] - 1, 0);
        f(cur_hp - skills[i].second, next_time, nextcool);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> hp;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        skills.push_back({a, b});
    }
    vector<int> cooldown(n);

    f(hp, 0, cooldown);

    cout << res;
    return 0;
}