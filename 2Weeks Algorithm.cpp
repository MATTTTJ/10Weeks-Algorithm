// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 1012

int dy[4]{ -1, 0, 1, 0 }, dx[4]{ 0,1,0,-1 };
int m, n, k, y, x, ny, nx, t, ret;
int a[51][51];
bool visited[51][51];

void dfs(int y, int x)
{
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if(a[ny][nx] == 1 && !visited[ny][nx])
		{
			dfs(ny, nx);
		}
	}
	return;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;

	queue<int> count;

	while (t--)
	{

		fill(&a[0][0], &a[0][0] + 51 * 51, 0);
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		ret = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					dfs(i, j);
					ret++;
				}
			}
		}
		count.push(ret);
	}

	while(count.size())
	{
		cout << count.front() << "\n";
		count.pop();
	}
	

	return 0;
}