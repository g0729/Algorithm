#include<iostream>
#include <algorithm>
#include<utility>
#include <queue>
using namespace std;



					
int main(){

queue <int>q;
int n;
cin>>n;
if(n==1)
{
	cout<<"1";
	return 0;
}
for(int i=1;i<n+1;i++){
	q.push(i);//
}

for(int j=0;j<n-2;j++){
	q.pop();
	q.push(q.front());
	q.pop();
	
	}
	q.pop();
	cout<<q.front();
	return 0;
}
