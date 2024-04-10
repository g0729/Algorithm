#include <string>
#include <vector>

using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n));

    int x,y;
    x=y=0;
    int dir=0;
    for(int num=1 ; num<=n*n;num++){
        answer[x][y]=num;
        int i,nx,ny;
        for(i = 0 ; i<4;i++){
            nx=x+dx[(dir+i)%4];
            ny=y+dy[(dir+i)%4];
            if(nx<0||nx>=n||ny<0|ny>=n)
                continue;
            if(answer[nx][ny]!=0)
                continue;
            break;
        }
        dir=(dir+i)%4;
        x=nx;
        y=ny;
    }
    return answer;
}