#include <string>
#include <vector>

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int answer=1e3;
vector<vector<bool>>red_visited(4,vector<bool>(4)),blue_visited(4,vector<bool>(4));

void back_track(int level,pair<int,int>red,pair<int,int>blue,vector<vector<int>>&maze){

    if(level>=10)
        return;
    if(maze[red.first][red.second]==3&&maze[blue.first][blue.second]==4){
        answer=min(answer,level);
        return;
    }
    pair<int,int>nred,nblue;
    for(int i = 0 ; i<4;i++){
        for(int j = 0 ;j<4;j++){
            if(maze[red.first][red.second]==3){
                nred=red;
            }
            else{
                nred={red.first+dx[i],red.second+dy[i]};
                if(nred.first<0||nred.first>=n||nred.second<0||nred.second>=m)
                    continue;
                if(red_visited[nred.first][nred.second])
                    continue;
                if(maze[nred.first][nred.second]==5)
                    continue;
            }

            if(maze[blue.first][blue.second]==4){
                nblue=blue;
            }
            else{
                nblue={blue.first+dx[j],blue.second+dy[j]};
                if(nblue.first<0||nblue.first>=n||nblue.second<0||nblue.second>=m)
                    continue;
                if(blue_visited[nblue.first][nblue.second])
                    continue;
                if(maze[nblue.first][nblue.second]==5)
                    continue;
            }
            if(nred.first==nblue.first&&nred.second==nblue.second)
                continue;
            if(nred.first==blue.first&&nred.second==blue.second&&nblue.first==red.first&&nblue.second==red.second)
                continue;
            red_visited[nred.first][nred.second]=true;
            blue_visited[nblue.first][nblue.second]=true;
            back_track(level+1,nred,nblue,maze);
            red_visited[nred.first][nred.second]=false;
            blue_visited[nblue.first][nblue.second]=false;

        }
    }
}

int solution(vector<vector<int>> maze) {
    pair<int,int>red,blue;
    for(int i = 0 ; i<maze.size();i++){
        for(int j = 0 ; j<maze[i].size();j++){
            if(maze[i][j]==1)
                {red={i,j};

                }
            if(maze[i][j]==2)
                blue={i,j};
        }
    }
    n=maze.size();
    m=maze[0].size();
    red_visited[red.first][red.second]=true;
    blue_visited[blue.first][blue.second]=true;

    back_track(0,red,blue,maze);
    if(answer==1e3)
        answer=0;
    return answer;
}
