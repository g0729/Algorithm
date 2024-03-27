#include <string>
#include <queue>
#include <vector>


using namespace std;
vector<int>edge[100001];

int bfs(int src,int dst,int n){
    vector<bool>visited(n+1);
    queue<int>q;
    q.push(src);
    visited[src]=true;
    int res=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int now=q.front();
            if(now==dst)
                return res;
            q.pop();
            
            for(int i = 0;i<edge[now].size();i++){
                int next=edge[now][i];
                if(visited[next])
                    continue;
                visited[next]=true;
                q.push(next);
            }
        }
        res++;
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    for(int i = 0; i<roads.size();i++){
        edge[roads[i][0]].push_back(roads[i][1]);
        edge[roads[i][1]].push_back(roads[i][0]);
    }
    
    for(int i=0;i<sources.size();i++){
        answer.push_back(bfs(sources[i],destination,n));
    }
    return answer;
}