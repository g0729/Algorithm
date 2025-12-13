#include<bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int>ma;
    
    for(auto& cloth :clothes){
        ma[cloth[1]]++;
    }
    
    int res=1;
    
    for(auto& a:ma){
        res*=a.second+1;
    }
    
    return res-1;
}