#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include<iostream>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {

    int size=(minerals.size()-1)/5+1;
    int temp=0;
    for(int i = 0 ; i<3;i++)
        temp+=picks[i];
    size=min(size,temp);
    vector<int>v;
    for(int i = 0 ; i<3;i++)
        for(int j = 0 ; j<picks[i];j++)
            v.push_back(i);
    v.erase(v.begin()+size,v.end());
    int cost[3][3]={{1,1,1},{5,1,1},{25,5,1}};
    map<string,int>ma={{"diamond",0},{"iron",1},{"stone",2}};
    int answer=1e9;
    do{
        int temp=0;
        for(int i = 0 ; i<minerals.size()&&i<size*5;i++){
            int tool=v[i/5];
            temp+=cost[tool][ma[minerals[i]]];
        }
        answer=min(answer,temp);
    }while(next_permutation(v.begin(),v.end()));
    return answer;
}