#include <bits/stdc++.h>
using namespace std;

int n, m;
int MAP[100][100];

void COPY(int (*CMAP)[100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			MAP[i][j] = CMAP[i][j];
		}
	}
}
void fuctionOne()
{
	int CMAP[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			CMAP[i][j] = MAP[n - i - 1][j];
		}
	}
	COPY(CMAP);
}

void fuctionTwo()
{
	int CMAP[100][100];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			CMAP[i][j] = MAP[i][m - j - 1];
		}
	}
	COPY(CMAP);
}

void fucitonThree()
{
	int CMAP[100][100];

	swap(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			CMAP[i][j] = MAP[m - j - 1][i];
		}
	}
	COPY(CMAP);
}
void fucitonFour()
{
	int CMAP[100][100];

	swap(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			CMAP[i][j] = MAP[j][n - i - 1];
		}
	}

	COPY(CMAP);
}

void fuctionFive()
{
	int CMAP[100][100];

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			CMAP[i][j] = MAP[i + n / 2][j];
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			CMAP[i][j] = MAP[i][j - m / 2];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			CMAP[i][j] = MAP[i - n / 2][j];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			CMAP[i][j] = MAP[i][j + m / 2];
		}
	}
	COPY(CMAP);
}

void fucitonSix()
{
	int CMAP[100][100];

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			CMAP[i][j] = MAP[i][j + m / 2];
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			CMAP[i][j] = MAP[i + n / 2][j];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = m / 2; j < m; j++)
		{
			CMAP[i][j] = MAP[i][j - m / 2];
		}
	}
	for (int i = n / 2; i < n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			CMAP[i][j] = MAP[i - n / 2][j];
		}
	}
	COPY(CMAP);
}
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int r;

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> MAP[i][j];
		}
	}

	while (r--)
	{
		int command;
		cin >> command;

		if (command == 1)
			fuctionOne();
		else if (command == 2)
			fuctionTwo();
		else if (command == 3)
			fucitonThree();
		else if (command == 4)
			fucitonFour();
		else if (command == 5)
			fuctionFive();
		else if (command == 6)
			fucitonSix();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}
}