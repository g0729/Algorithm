#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int n, m;
int ab[3];
int visited[MAX];

void bfs()
{
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (now + ab[i] < MAX && visited[now + ab[i]] == 0)
			{
				q.push(now + ab[i]);
				visited[now + ab[i]] = visited[now] + 1;
			}
			if (now - ab[i] >= 0 && visited[now - ab[i]] == 0)
			{
				q.push(now - ab[i]);
				visited[now - ab[i]] = visited[now] + 1;
			}
			if (now * ab[i] < MAX && visited[now * ab[i]] == 0)
			{
				q.push(now * ab[i]);
				visited[now * ab[i]] = visited[now] + 1;
			}
		}
	}
}
int main()
{
	cin >> ab[0] >> ab[1] >> n >> m;
	ab[2] = 1;
	bfs();

	cout << visited[m];
}