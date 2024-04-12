#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr, int n) {
    int temp=0?1:arr.size()%2==0;

    for(int i =temp; i<arr.size();i+=2){
        arr[i]+=n;
    }
    return arr;
}