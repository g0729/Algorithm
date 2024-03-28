#include<bits/stdc++.h>
using namespace std;

struct boys {

	string name;
	int a;
	int b;
	int c;
};
boys* boy;
bool cmp(const boys& p1, const boys& p2)
{
	if (p1.a == p2.a)
	{
		if (p1.b == p2.b)
		{
			if (p1.c == p2.c)
			{
				return p1.name < p2.name;
			}
			return p1.c > p2.c;
		}
		return p1.b < p2.b;
	}
	return p1.a > p2.a;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	boy = new boys[n];
	for (int i = 0; i < n; i++)
	{
		cin >> boy[i].name;
		cin >> boy[i].a;
		cin >> boy[i].b;
		cin >> boy[i].c;
	}
	sort(boy, boy + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << boy[i].name << "\n";
	}

}