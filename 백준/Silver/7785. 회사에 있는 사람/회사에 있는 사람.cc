#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<string> se;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        if (b == "enter")
            se.insert(a);
        else
            se.erase(a);
    }
    vector<string>v;
    for (auto it : se)
        v.push_back(it);
    
    sort(v.begin(),v.end());

    for (int i = v.size()-1; i>=0; i--)
        cout<<v[i]<<"\n";
    
    return 0;
}