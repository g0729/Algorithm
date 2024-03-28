#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int visited[MAX+1];
int height,now,target,up,down;   

int bfs()
{
    queue<int>q;
    q.push(now);
    visited[now]=1;
    while(!q.empty())
    {
        int x=q.front();
        if(x==target)
        return visited[x];
        q.pop();
        if(x+up<=height&&visited[x+up]==0)
        {
            q.push(x+up);
            visited[x+up]=visited[x]+1;
        }
        if(x-down>0&&visited[x-down]==0)
        {
            q.push(x-down);
            visited[x-down]=visited[x]+1;
        }
    }
    return -1;
}
int main()
{
    cin>>height>>now>>target>>up>>down;
    int res=bfs();
    if(res==-1)
    {
        cout<<"use the stairs";
    }
    else
    cout<<res-1;
}