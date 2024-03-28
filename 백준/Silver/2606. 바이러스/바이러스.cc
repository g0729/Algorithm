#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int arr[MAX][MAX];
bool visited[MAX];
int n, k;
int bfs(int start)
{
	int cnt = 0;
	queue<int>q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		start = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (arr[start][i] == 1 && visited[i] == false)
			{
				cnt++;
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int res = bfs(1);
	cout << res;
}