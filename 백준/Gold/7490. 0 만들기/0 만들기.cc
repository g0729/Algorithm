#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long

vector<char> res;
vector<vector<char>> ans;
int n;
void dfs(int now, int sign, int sum, int temp)
{
    if (now == n)
    {
        sum += sign * temp;

        if (sum == 0)
            ans.push_back(res);

        return;
    }

    res.push_back(' ');
    dfs(now + 1, sign, sum, temp * 10 + now + 1);
    res.pop_back();

    res.push_back('+');
    dfs(now + 1, 1, sum + sign * temp, now + 1);
    res.pop_back();

    res.push_back('-');
    dfs(now + 1, -1, sum + sign * temp, now + 1);
    res.pop_back(); 
}
void print(vector<char>& v)
{

    int cnt=1;

    for (int i = 0; i < v.size(); i++)
    {
        cout<<cnt<<v[i];
        cnt++;
    }
    
    cout<<cnt<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

        cin>>n;

        dfs(1,1,0,1);

        sort(ans.begin(),ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            print(ans[i]);           
        }
        
        ans.clear();
        res.clear();

        cout<<"\n";
    }
    return 0;
}