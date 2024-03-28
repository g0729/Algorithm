#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num){
	if(num==2)
	return true;
    for (int i=2; i*i<=num; i++){
        if (num%i==0) return false;
    }
    return true;
}
int main(){
    vector<int> v;
    int m, n, sum = 0, min=10001;
    scanf("%d\n%d", &m, &n);

    for (int i=m; i<=n;i++){
        if (i<2) continue; 
        if (isPrime(i)) v.push_back(i);
    }
    for (int i = 0; i<v.size();i++){
        sum += v.at(i);
        if (v.at(i)< min) min =v.at(i);
    }
    if (min == 10001) printf("-1\n");
    else {
        printf("%d\n%d\n", sum, min);
    }
    return 0;
}