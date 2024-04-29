#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>>v) {
    int answer = 0;
    vector<int>edges[n+1];
    
    for(int i = 0 ; i<v.size();i++)
    {
        edges[v[i][0]].push_back(v[i][1]);
        edges[v[i][1]].push_back(v[i][0]);
    }
    
    vector<bool>visited(n+1);
    
    visited[1]=true;
    queue<int>q;
    q.push(1);
    int size=0;
    while(!q.empty())
    {
        size=q.size();
        for(int _=0;_<size;_++){
            int now=q.front();
            q.pop();
            
            for(int i =0 ; i<edges[now].size();i++)
            {
                int next=edges[now][i];
                if(visited[next])
                    continue;
                q.push(next);
                visited[next]=true;
            }
        }
    }
    return size;
}