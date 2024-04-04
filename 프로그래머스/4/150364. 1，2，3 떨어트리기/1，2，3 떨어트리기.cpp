#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> edge[101];
vector<int> edge_idx(100);

int dfs(int now)
{
    if (edge[now].size() == 0)
        return now;

    int idx = edge_idx[now];

    int res = dfs(edge[now][idx]);
    edge_idx[now] = (idx + 1) % edge[now].size();

    return res;
}
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    
    
    for(int i = 0 ;i<edges.size();i++){
        edge[edges[i][0]].push_back(edges[i][1]);
    }
    for(int i = 0 ;i<101;i++)
        sort(edge[i].begin(),edge[i].end());
    
    vector<int>needs(target.size());
    for(int i = 0 ;i<target.size();i++){
        if(target[i]==0)
            continue;
        needs[i]=(target[i]-1)/3+1;
    }
    vector<int>cnt[101];
    int i;
    bool available=true;
    for(i =1 ;;i++){
        int now=dfs(1);
        cnt[now-1].push_back(i);
        
        if(cnt[now-1].size()>target[now-1]){
            available=false;
            cout<<i;
            break;
        }
        bool flag=true;
        for(int j=0;j<needs.size();j++){
            if(needs[j]==0)
                continue;
            if(cnt[j].size()<needs[j]){
                flag=false;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!available)
        return vector<int>(1,-1);
    vector<int>answer(i);
    
    for(int i = 0 ; i<target.size();i++){
        if(target[i]==0)
            continue;
        
        int num=cnt[i].size();
        
        vector<int>temp(num,1);
        int left=target[i]-num;
        for(int j=temp.size()-1;j>=0;j--){
             if(left<=0)
                break;
            if(left>=2){
                temp[j]+=2;
                left-=2;
            }
            else{
                temp[j]+=1;
                left-=1;
            }
           
        }
        
        for(int j=0;j<temp.size();j++){
            answer[cnt[i][j]-1]=temp[j];
        }
    }

    return answer;
}