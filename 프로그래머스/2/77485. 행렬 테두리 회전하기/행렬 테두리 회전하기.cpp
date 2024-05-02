#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int rotate(vector<vector<int>>&MAP,vector<int>query){
    int x1,x2,y1,y2;
    x1=query[0]-1;
    y1=query[1]-1;
    x2=query[2]-1;
    y2=query[3]-1;
    int dir=0;
    int x=x1;
    int y=y1;
    int prev=MAP[x][y];
    int ans=prev;
    for(int i = 0 ; i<(x2-x1+1)*2+(y2-y1-1)*2;i++){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx==x1&&ny==y2)
            dir=1;
        else if(nx==x2&&ny==y2)
            dir=2;
        else if (nx==x2&&ny==y1)
            dir=3;
        ans=min(ans,MAP[nx][ny]);
        int temp=MAP[nx][ny];
        MAP[nx][ny]=prev;
        prev=temp;
        x=nx;
        y=ny;
    }
    return ans;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>>MAP(rows,vector<int>(columns));
    int idx=1;
    for(int i = 0 ; i<rows;i++){
        for(int j = 0 ; j<columns;j++)
            MAP[i][j]=idx++;
    }
    for(int i = 0 ; i <queries.size();i++){
        answer.push_back(rotate(MAP,queries[i]));
    }
    return answer;
}