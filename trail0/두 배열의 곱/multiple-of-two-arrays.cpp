#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>>v(3,vector<int>(3));
    for(int i = 0 ; i<3 ; i++){
        for(int j = 0 ; j<3;j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0 ; i<3 ;i++){
        for(int j = 0 ; j < 3 ; j++){
            int a;
            cin>>a;
            cout<<v[i][j]*a<<" ";
        }
        cout<<"\n";
    }
    return 0;
}