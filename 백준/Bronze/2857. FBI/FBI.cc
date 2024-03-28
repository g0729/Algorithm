#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int>res;
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin>>s;
        if(s.find("FBI")!=string::npos)
        {
            res.push_back(i+1);
        }
    }
    
    if(res.empty())
        cout<<"HE GOT AWAY!";
    else
    {
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
        
    }
    return 0;
}
