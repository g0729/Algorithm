#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<string,string> Map;

    int n,m;

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        string a,b;
        cin>>a>>b;
        Map.insert({a,b});
    }
    
    for (int i = 0; i < m; i++)
    {
        string a;
        cin>>a;

        cout<<Map[a]<<"\n";
    }
    
    return 0;
}