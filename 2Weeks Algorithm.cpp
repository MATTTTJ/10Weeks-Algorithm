// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 2178 

const int max_n = 104;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main ()
{
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j <m; j ++)
		{
			// N x M 배열을 입력받기 위함
			scanf("%1d", &a[i][j]);
		}
	}
	// y,x 좌표가 주어지기 때문에 두개를 담을 수 있는 페어
	queue<pair<int, int>> q;
	// 방문처리 후 q 푸쉬
	visited[0][0] = 1;
	q.push({ 0,0 });

	while(q.size())
	{
		//y,x 뽑아내기 
		tie(y, x) = q.front();
		q.pop();

		for(int i =0; i < 4; i ++)
		{
			// 4방향 탐색하기 
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 마지막 예외는 건널 수 없는 조건 (바다)
			// 오버플로우 예외처리 먼저 하고 진행해야 함
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
			// 방문처리 확인
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			// 최단거리 구하기 완료
			q.push({ ny, nx });
		}
	}

	printf("%d", visited[n - 1][m - 1]);

	return 0;
}
