#include <string>
#include <vector>
#include <queue>

using namespace std;
void bfs(int start,vector<vector<int>>&computer,vector<bool>&visited)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;
    
    while(!q.empty()){
        int now=q.front();
        q.pop();
        
        for(int i=0;i<computer[now].size();i++){
            if(computer[now][i]==0)
                continue;
            int next=i;
            if(visited[next])
                continue;
            q.push(next);
            visited[next]=true;
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool>visited(n);
        
    for(int i=0;i<n;i++){
        if(!visited[i]){
            answer++;
            bfs(i,computers,visited);
        }
    }
    return answer;
}