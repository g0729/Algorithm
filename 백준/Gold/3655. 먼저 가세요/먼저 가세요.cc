#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> ma;
        map<char, int> cnt;
        vector<pair<char, int>> v;

        for (int i = 0; i < n; i++)
        {
            ma[s[i]] = i;
            cnt[s[i]]++;
        }
        for(auto it:ma)
        {
            if(it.first==s.back())
                continue;
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        int now=n-1-cnt[s.back()];
        int res=0;

        for(int i = 0 ; i<v.size();i++)
        {
            res+=5*(v[i].second-now)*(cnt[v[i].first]);
            now-=cnt[v[i].first];
        }
        cout<<res<<"\n";
    }
    return 0;
}