#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;
int n;
int main()
{
	long long sum=0;
	int temp = 0 ;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		pq.push(a);
	}
	while(!pq.empty())
	{
		temp=pq.top();
		pq.pop();
		if(pq.empty())
		break;
		temp +=pq.top();
		pq.pop();
		sum+=temp;
		pq.push(temp);
	}
	cout<<sum;
}