#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

bool cmp(pair<string,int> a, pair<string,int> b)
{
    return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, l;
    cin >> k >> l;

    unordered_map<string, int> Map;

    for (int i = 0; i < l; i++)
    {
        string s;
        cin >> s;

        Map[s] = i;
    }

    vector<pair<string,int>> v;

    for (auto i : Map)
        v.push_back(i);
    
    sort(v.begin(),v.end(),cmp);

    for (int i = 0; i < k&&i<v.size(); i++)
    {
        cout<<v[i].first<<"\n";
    }
    
    return 0;
}