#include <bits/stdc++.h>
using namespace std;

bool visited[201];
pair<int,char> arr[201];
int n;


void bfs()
{
    queue<int>q;
    q.push(1);
    arr[1].first=-1;
    arr[1].second='1';
    visited[1]=true;

    while(!q.empty())
    {
        int now=q.front();
        q.pop();

        int next[2];
        next[0]=(now*10)%n;
        next[1]=((now*10)+1)%n;

        for(int i = 0 ; i<2;i++)
        {
            if(visited[next[i]])
            continue;;
            
            q.push(next[i]);
            visited[next[i]]=true;
            arr[next[i]].first=now;
            arr[next[i]].second='0'+i;
            if(next[i]==0)
            return ;
        }
    }
}
void print(int parent)
{
    if(parent==-1)
    return;
    print(arr[parent].first);
    cout<<arr[parent].second;
}
int main()
{
    while(1)
    {
        cin>>n;

        if(n==0)
        return 0;

        bfs();
        print(0);
        memset(visited,false,sizeof(visited));
        cout<<"\n";

    }
}