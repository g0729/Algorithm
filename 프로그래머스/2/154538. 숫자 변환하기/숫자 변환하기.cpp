#include <string>
#include <vector>
#include <queue>
#define MAX 1000000
using namespace std;
bool visited[MAX+1];

bool check(int target,int y){
    if(target>y || visited[target])
        return false;
    return true;
}
int bfs(int x,int y,int n){
    queue<int>q;
    q.push(x);
    int level=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int now=q.front();
            q.pop();
            if(now==y)
                return level;
            if(check(now+n,y)){
                q.push(now+n);
                visited[now+n]=true;
            }
            if(check(now*2,y)){
                q.push(now*2);
                visited[now*2]=true;
            }
            if(check(now*3,y)){
                q.push(now*3);
                visited[now*3]=true;
            }
            
        }
        level++;
    }
    return -1;
}

int solution(int x, int y, int n) {
    return bfs(x,y,n);
}