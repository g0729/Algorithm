#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define lint long long
bool visited[10];
vector<char> v;
int cnt;
int n;
bool flag;
string s;
void dfs(int now, string a)
{
	if (now == v.size())
	{
		cnt++;

		if (cnt == n)
		{
			cout << s << " " << n << " = " << a << "\n";
			flag = true;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		dfs(now + 1, a + v[i]);
		visited[i] = false;
		if (flag)
			return;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> s >> n;

		for (int i = 0; i < s.length(); i++)
		{
			v.push_back(s[i]);
		}
		if (cin.eof())
			break;

		dfs(0, "");

		if (!flag)
		{
			cout << s << " " << n << " = "
				 << "No permutation"
				 << "\n";
		}
		memset(visited, false, sizeof(visited));
		v.clear();
		cnt = 0;
		flag = false;
	}
	return 0;
}