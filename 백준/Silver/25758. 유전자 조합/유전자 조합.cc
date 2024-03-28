#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

map<string, int> ma;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ma[s]++;
    }

    vector<string> v;
    for (auto it : ma)
    {
        v.push_back(it.first);
        if (it.second >= 2)
            v.push_back(it.first);
    }

    set<char> res;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 1; j < v.size(); j++)
        {
            string temp ="";
            temp.push_back(v[i][0]);
            temp.push_back(v[j][1]);
            if(temp[0]<=temp[1])
                res.insert(temp[1]);
            else
                res.insert(temp[0]);
            temp="";
            temp.push_back(v[j][0]);
            temp.push_back(v[i][1]);
            if(temp[0]<=temp[1])
                res.insert(temp[1]);
            else
                res.insert(temp[0]);
        }
    }

    cout<<res.size()<<"\n";

    for(auto it: res)
    {
        cout<<it<<" ";
    }
    return 0;
}