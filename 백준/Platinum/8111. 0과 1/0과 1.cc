#include<bits/stdc++.h>
using namespace std;
#define MAX 20000
int n;
bool visited[MAX+1];
pair<int,char>arr[MAX+1];

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
            if(visited[next[i]]==false)
            {
                q.push(next[i]);
                arr[next[i]].first=now;
                arr[next[i]].second=i+'0';
                visited[next[i]]=true;
                if(next[i]==0)
                return ;
            }
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
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"1\n";
            continue;
        }

        bfs();
        print(0);
        memset(visited,false,sizeof(visited));
        cout<<"\n";
    }
}