// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#define CODINGTEST cin.tie(NULL); cout.tie(NULL); 

using namespace std;
typedef long long ll;

// algorithm 2636

int a[104][104], visited[104][104];
int dy[] = { -1, 0, 1,0 }, dx[] = { 0,1,0, -1 };
int n, m, cnt, cnt2;
vector<pair<int, int>> v;

void go(int y, int x)
{
	visited[y][x] = 1;
	if(a[y][x] ==1)
	{
		// 치즈인경우 더이상 방문하지 않고 벡터에 푸시
		v.push_back({ y,x });
		return;
	}
	for(int i =0;i <4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx])
			continue;
		go(ny, nx);
	}
	return;
}


int main()
{
	CODINGTEST
	cin >> n >> m;

	for(int i =0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}


	while(true)
	{
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		go(0, 0);
		// 치즈가 녹기 전의 사이즈
		cnt2 = v.size();
		// 치즈를 녹인다.
		for(pair<int, int> b : v)
		{
			cnt2++;
			a[b.first][b.second] = 0;
		}
		// 치즈가 다 녹았는지 체크
		bool flag = 0;
		for(int i =0; i<n; i++)
		{
			for(int j =0; j <m; j++)
			{
				if (a[i][j] != 0)
					flag = 1;
			}
		}
		cnt++;
		if (!flag)
			break;
	}
	cout << cnt << "\n" << cnt2 << '\n';

	return 0;
}
