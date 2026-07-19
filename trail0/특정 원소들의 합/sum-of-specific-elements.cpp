#include <iostream>
using namespace std;

int main() {
    int sum = 0 ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            int a;
            cin>>a;

            if(i >= j) sum+=a;
        }
    }

    cout<<sum;
    return 0;
}