#include<bits/stdc++.h>
using namespace std;
#define MAX 2000
bool visited[MAX];
vector<int>graph[MAX];
int n,m;

void dfs(int start,int cnt)
{
   if(cnt==5)
   {
       cout<<"1";
       exit(0);
   }
   for(int i = 0 ; i<graph[start].size();i++)
   {
       int next = graph[start][i];
       if(visited[next]==true)
       continue;
       visited[start]=true;
       dfs(next,cnt+1);
       visited[start]=false;
   }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0 ; i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0 ; i<n;i++)
    {
        dfs(i,1);
    }
    cout<<"0";
}