#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int>ms;
    
    for(auto it : operations){
        char c=it[0];
        int num=stoi(it.substr(2));
        if (c=='I')
            ms.insert(num);
        else{
            if(ms.empty())
                continue;
            if(num==-1)
                ms.erase(ms.begin());
            else{
                auto iter=ms.end();
                iter--;
                ms.erase(iter);
            }
        }
    }
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        auto iter=ms.end();
        iter--;
        answer.push_back(*iter);
        answer.push_back(*ms.begin());
    }
    return answer;
}