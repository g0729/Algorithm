#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector <int> v(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector <int> cv(v);
	sort(cv.begin(), cv.end());
	cv.erase(unique(cv.begin(), cv.end()), cv.end());
	for (int i = 0; i < n; i++)
	{
		int q;
		q = lower_bound(cv.begin(), cv.end(), v[i])-cv.begin();
		cout << q << " ";
	}
}