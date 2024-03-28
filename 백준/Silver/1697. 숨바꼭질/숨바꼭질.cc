#include<bits/stdc++.h>
using namespace std;

#define MAX 100002
int graph[MAX];
int n, k;

void bfs(int start)
{
	queue<int>q;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now * 2 < MAX&&now!=0)
		{
			
			if (graph[now * 2] == 0)
			{
				q.push(now * 2);
				graph[now * 2] = graph[now] + 1;
			}
			else
			{
				graph[now * 2] = min(graph[now * 2], graph[now] + 1);
			}	
		}
		if (now < MAX - 1)
		{
			
			if (graph[now + 1] == 0)
			{
				q.push(now + 1);
				graph[now + 1] = graph[now] + 1;
			}
			else
			{
				graph[now + 1] = min(graph[now + 1], graph[now] + 1);
			}
		}
		if (now > 0)
		{
			
			if (graph[now - 1] == 0)
			{
				q.push(now - 1);
				graph[now - 1] = graph[now] + 1;
			}
			else
			{
				graph[now - 1] = min(graph[now - 1], graph[now] + 1);
			}
		}
	}
}

int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << "0";
		return 0;
	}
	bfs(n);
	cout << graph[k];
}