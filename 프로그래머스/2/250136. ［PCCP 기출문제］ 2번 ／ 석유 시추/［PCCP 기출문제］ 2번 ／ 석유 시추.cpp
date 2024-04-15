#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool visited[500][500];
set<int>se;
int n,m;

int bfs(int x,int y,vector<vector<int>>&land){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=true;
    se.insert(y);
    int cnt=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        se.insert(y);
        cnt+=1;
        
        for(int i= 0 ; i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(visited[nx][ny])
                continue;
            if(land[nx][ny]==0)
                continue;
            q.push({nx,ny});
            visited[nx][ny]=true;
        }
    }
    return cnt;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n=land.size();
    m=land[0].size();
    vector<int>cnt(land[0].size());
    
    for(int i = 0 ;i<n;i++){
        for(int j= 0 ; j<m;j++){
            if(land[i][j]==1 &&!visited[i][j]){
                int temp=bfs(i,j,land);
                for(auto it:se){
                    cnt[it]+=temp;
                }
                se.clear();
            }
        }
    }
    
    for(int i = 0 ; i<m;i++)
        answer=max(answer,cnt[i]);
    return answer;
}