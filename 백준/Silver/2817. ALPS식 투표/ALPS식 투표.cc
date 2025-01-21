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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;

    // 1) 5% 통과 스태프 저장용 (이름 -> 득표수)
    vector<pair<string, int>> staff;
    for (int i = 0; i < n; i++)
    {
        string name;
        int vote;
        cin >> name >> vote;
        // 5% 미만이면 무시
        if (vote < (double)x * 0.05)
            continue;
        // 통과한 스태프만 staff에 저장
        staff.push_back({name, vote});
    }

    // 후보 스태프가 아예 없으면 -> 아무것도 출력 안 하고 종료(문제설명 상 그렇게 보임)
    if (staff.empty())
    {
        return 0;
    }

    // 2) 점수 집합 만들기
    //   (vote / 1, vote / 2, ..., vote / 14) 각각 (점수, 이름)을 v에 담기
    vector<pair<double, string>> v;
    // 칩 개수를 저장할 map (모든 5% 통과 스태프를 0으로 초기화)
    unordered_map<string, int> chips; // or map<string,int>
    for (auto &st : staff)
    {
        string &nm = st.first;
        int vt = st.second;
        chips[nm] = 0; // 초기화
        for (int j = 1; j <= 14; j++)
        {
            v.push_back({(double)vt / j, nm});
        }
    }

    // 3) 점수 내림차순 정렬
    sort(v.begin(), v.end(), [](auto &a, auto &b)
         { return a.first > b.first; });

    // 4) 상위 14개에 대해서 해당 스태프에게 +1칩
    int limit = min((int)v.size(), 14);
    for (int i = 0; i < limit; i++)
    {
        chips[v[i].second]++;
    }

    // 5) 최종 출력: 5% 통과 스태프 이름 사전순
    vector<pair<string, int>> ans;
    ans.reserve(chips.size());
    for (auto &it : chips)
    {
        ans.push_back({it.first, it.second});
    }
    sort(ans.begin(), ans.end()); // 이름 기준
    for (auto &p : ans)
    {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}