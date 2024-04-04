#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(int target,vector<int>&rocks,int& n){
    int cnt=0;
    
    int left=0;
    for(int i = 0; i<rocks.size();i++){
        int diff=rocks[i]-left;
        if(diff<target){
            cnt++;
        }
        else{
            left=rocks[i];
        }
    }
    return cnt<=n;
}
int binsearch(int dis,vector<int>&rocks,int n){
    int left=0,right=dis+1;
    
    while(left+1<right){
        int mid=(left+right)/2;
        
        if(check(mid,rocks,n))
            left=mid;
        else
            right=mid;
        
    }
    return left;
}
int solution(int dis, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(),rocks.end());
    rocks.push_back(dis);
    
    return binsearch(dis,rocks,n);
}