#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

void build_tree(vector<int>&tree,string& bin,int node,int& lim,int& idx){
    
    if(node*2>=lim){
        tree[node]=bin[idx]-'0';
        idx++;
        return;
    }
    
    build_tree(tree,bin,node*2,lim,idx);
    tree[node]=bin[idx]-'0';
    idx++;
    build_tree(tree,bin,node*2+1,lim,idx);
}

int cal(ll num){
    string bin;
    while(num){
        if (num&(ll)1)
            bin.push_back('1');
        else
            bin.push_back('0');
        num>>=1;
    }
    int len=bin.length();
    int now=2;
    int height=1;
    while(now-1<len){
        now*=2;
        height++;
    }
    for(int i= 0 ; i<now-1-len;i++)
        bin.push_back('0');
    for(int i = 0 ; i<bin.length()/2;i++)
        swap(bin[i],bin[bin.length()-i-1]);
    vector<int>tree(now);
    int idx=0;
    build_tree(tree,bin,1,now,idx);
    for(int i=1; i<now/2;i++){
        if(tree[i]==0)
            if(tree[i*2]==1||tree[i*2+1]==1)
                return 0;
    }
    
    return 1;
}


vector<int> solution(vector<ll> numbers) {
    vector<int> answer;
    
    for(auto num:numbers)
        answer.push_back(cal(num));
    return answer;
}