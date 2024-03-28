#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
bool visited[MAX + 1];
int n, m;
int many;
int cnt;
int res;
void bfs(int now)
{
	queue<pair<int, int>>q;
	q.push({ now,0 });

	while (!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		q.pop();
		visited[now] = true;
		if (many&&now == m&&res==time)
		{
			many++;
		}
		if (!many && now == m)
		{
			many++;
			res = time;
		}
		if (now - 1 >= 0&&!visited[now-1])
		{
			q.push({ now - 1,time + 1 });
		}
		if (now + 1 <= MAX&& !visited[now + 1])
		{
			q.push({ now + 1,time + 1 });
		}
		if (now * 2 <= MAX&& !visited[now*2])
		{
			q.push({ now * 2,time + 1 });
		}
	}
}

int main()
{
	cin >> n >> m;
	bfs(n);
	cout << res << endl << many;
}