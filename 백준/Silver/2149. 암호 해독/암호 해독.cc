#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define ll long long
#define MOD 1000000007
#define MAX 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    vector<pair<char, int>> pi;

    for (int i = 0; i < a.length(); i++)
    {
        pi.push_back({a[i], i});
    }

    sort(pi.begin(), pi.end());

    char temp[11][101];
    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length()/a.length(); j++)
        {
            temp[j][i]=b[j+i*(b.length()/a.length())];
        }
        
    }
    
    char temp2[11][101];
    for (int i = 0; i < pi.size(); i++)
    {
        int now=pi[i].second;
        for (int j = 0; j < b.length()/a.length(); j++)
        {
            temp2[j][now]=temp[j][i];
        }
        
    }
    
    for (int i = 0; i < b.length()/a.length(); i++)
    {
        for (int j = 0; j < a.length(); j++)
        {
            cout<<temp2[i][j];
        }
    }
    
    
    return 0;
}