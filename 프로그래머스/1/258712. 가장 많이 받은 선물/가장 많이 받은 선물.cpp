#include <string>
#include <vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string,int>name_idx;
    for(int i =0 ; i<friends.size();i++){
        name_idx[friends[i]]=i;
    }
    
    vector<vector<int>>v(friends.size(),vector<int>(friends.size()));
    
    for(int i=0;i<gifts.size();i++){
        string a,b;
        int idx=gifts[i].find(" ");
        a=gifts[i].substr(0,idx);
        b=gifts[i].substr(idx+1);
        cout<<name_idx[a]<<" "<<name_idx[b]<<endl;
        v[name_idx[a]][name_idx[b]]++;
    }
    
    vector<int>gifts_cnt(friends.size());
    
    for(int i = 0;i<friends.size()-1;i++){
        for(int j =i+1;j<friends.size();j++){
            int a,b;
            a=name_idx[friends[i]];
            b=name_idx[friends[j]];
            
            if((v[a][b]!=0||v[b][a]!=0)&&v[a][b]!=v[b][a]){
                if(v[a][b]>v[b][a])
                    gifts_cnt[a]++;
                else
                    gifts_cnt[b]++;
            }
            else{
                int a_sum,b_sum;
                a_sum=b_sum=0;
                for(int k = 0 ; k<friends.size();k++){
                    a_sum+=v[a][k];
                    a_sum-=v[k][a];
                    b_sum+=v[b][k];
                    b_sum-=v[k][b];
                }
                if(a_sum==b_sum)
                    continue;
                if(a_sum>b_sum)
                    gifts_cnt[a]++;
                else
                    gifts_cnt[b]++;
            }
        }
    }
    // for(int i = 0;i<friends.size();i++){
    //     for(int j = 0; j<friends.size();j++)
    //         cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i = 0 ; i<gifts_cnt.size();i++){
    answer=max(answer,gifts_cnt[i]);
    }
    return answer;
}