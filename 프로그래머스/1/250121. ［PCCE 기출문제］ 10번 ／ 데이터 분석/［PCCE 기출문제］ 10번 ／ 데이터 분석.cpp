#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

void sort(vector<vector<int>>&data,int start,int end ,int idx){
    if(start>=end)
        return;
    int pivot=start;
    int i=start+1;
    int j=end;
    
    while(i<=j){
        while(i<=end&&data[i][idx]<=data[pivot][idx])
            i++;
        while(data[j][idx]>=data[pivot][idx]&&j>start)
            j--;
        if(i>j){
            vector<int>temp=data[j];
            data[j]=data[pivot];
            data[pivot]=temp;
        }
        else{
            vector<int>temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
        sort(data,start,j-1,idx);
        sort(data,j+1,end,idx);
    }
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string,int> ma ;
    ma["code"]=0;
    ma["date"]=1;
    ma["maximum"]=2;
    ma["remain"]=3;
    
    int _ext=ma[ext];
    int _sort_by=ma[sort_by];
    for(int i = 0 ; i <data.size();i++){
        if(data[i][_ext]<val_ext)
            answer.push_back(data[i]);
    }
    
    sort(answer,0,answer.size()-1,_sort_by);
    return answer;
}