#include<iostream>
#include<algorithm>
using namespace std;
struct loc
{
	int x, y;
};
bool cmp(const loc& p1, const loc& p2)
{
	if (p1.y < p2.y)
		return true;
	else if (p1.y == p2.y)
		return p1.x < p2.x;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	loc* arr = new loc[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].x << " "<<arr[i].y << "\n";
}