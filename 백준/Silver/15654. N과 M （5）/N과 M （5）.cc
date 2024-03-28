#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
vector<int>res;
bool *visited;

void dfs(int cnt)
{

    if(cnt==m)
    {
        for(int i = 0 ; i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i = 0 ; i<v.size();i++)
    {
        if(visited[i]==true)
        continue;
        visited[i]=true;
        res.push_back(v[i]);
        dfs(cnt+1);
        visited[i]=false;
        res.pop_back();
    }
}
int main()
{
    cin>>n>>m;
    visited = new bool[n];
    for(int i = 0 ; i<n;i++)
    {
        visited[i]=false;
    }
    while(n--)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    dfs(0);
}