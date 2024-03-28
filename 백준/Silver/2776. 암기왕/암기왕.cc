#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int search(int val,int s, int e){
    while(s <= e){
        int mid = (s+e)/2;
        if(v[mid] == val){
            return 1;
        }
        else if(v[mid] < val){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int t,n,m,val;
    cin>>t;
    for(int k = 0 ; k < t; k++){
    cin>>n;
        for(int i = 0 ; i< n;i++){
            cin>>val;
            v.push_back(val);
        }
        cin>>m;
        sort(v.begin(),v.end());
        for(int i = 0 ; i < m ; i++){
            cin>>val;
            if(search(val,0,n-1) == 1){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        v.clear();
    }
    return 0;
}
