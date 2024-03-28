#include <bits/stdc++.h>
using namespace std;
#define MAX 99999
int visited[MAX + 1];
int n, t, g;

int f(int num)
{
	int length = 0;
	int cnum = num;
	while (cnum)
	{
		cnum /= 10;
		length++;
	}
	int temp = 1;
	for (int i = 1; i < length; i++)
	{
		temp *= 10;
	}
	num = num - temp;
	return num;
}
void bfs()
{
	queue<int> q;
	q.push({n});
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		int next[2];
		next[0] = now + 1;
		next[1] = now * 2;
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				if (next[i] > MAX)
					continue;
				if (visited[next[i]] != 0)
					continue;
				q.push(next[i]);
				visited[next[i]] = visited[now] + 1;
			}
			else
			{
				if (now == 0)
					continue;
				if (next[i] > MAX)
					continue;
				next[i] = f(next[i]);
				if (visited[next[i]] != 0)
					continue;
				q.push(next[i]);
				visited[next[i]] = visited[now] + 1;
			}
		}
	}
}
int main()
{
	cin >> n >> t >> g;
	if (n == g)
	{
		cout << 0;
		return 0;
	}
	bfs();
	int res = visited[g];
	if (res == 0 || res > t)
		cout << "ANG";
	else
		cout << res;
}