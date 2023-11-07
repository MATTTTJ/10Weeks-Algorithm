﻿// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

// algorithm 14502

int a[10][10], visited[10][10], n, m, ret;
vector<pair<int, int>> virusList, wallList;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void dfs(int y, int x)
{
	for(int i = 0; i< 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 1)
			continue;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;
}

// 벽을 세우고 세운 벽을 기반으로 바이러스가 퍼지고, 이 결과를 토대로 안전영역을 체크하는 함수
int solve()
{
	// 경우의 수 마다 초기화해주고 dfs를 돌려야 한다. 바이러스가 퍼져나가는 것을 표현
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
	for (pair<int, int> b : virusList)
	{
		visited[b.first][b.second] = 1;
		dfs(b.first, b.second);
	}

	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && !visited[i][j])
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	CODINGTEST
		cin >> n >> m;

	for(int i =0; i< n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2)
				virusList.push_back({ i,j });
			// 벽을 세울 수 있는 지점을 골라내서 좌표를 담는 작업
			if (a[i][j] == 0)
				wallList.push_back({ i,j });
		}
	}

	for(int i =0; i < wallList.size();i++)
	{
		for(int j =0; j<i; j++)
		{
			for(int k = 0; k < j; k++)
			{
				a[wallList[i].first][wallList[i].second] = 1;
				a[wallList[j].first][wallList[j].second] = 1;
				a[wallList[k].first][wallList[k].second] = 1;
				ret = max(ret, solve());
				a[wallList[i].first][wallList[i].second] = 0;
				a[wallList[j].first][wallList[j].second] = 0;
				a[wallList[k].first][wallList[k].second] = 0;
			}

		}
	}
	cout << ret << "\n";
	return 0;
}