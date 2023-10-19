// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


/**
 * 배수란 ? 4 % 2 == 0 인 경우를 봤을 때 true이면 배수라고 판단한다.
 * 1로만 이루어진 수 중에 n 의 배수 -> 가장 작은 거의 자릿수
 * 111 % (모듈러연산) 3 == 0
 * 이 경우 111의 자릿수는 3, 이 3을 이용해서 111을 나눴을 때 배수가 된다.
 * n이 9901인 경우 12자리가 나온다. 
 */
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
//
//typedef long long ll;
//int n;
//
//int main()
//{
//	while(cin >> n)
//	{
//		int cnt = 1, ret = 1;
//		while(true)
//		{
//			// 자릿수가 수의 배수임을 체크하고 자릿수 반환하기
//			if(cnt % n ==0)
//			{
//				// printf("%d\n", ret);
//				cout << ret << "\n";
//				break;
//			}
//			else
//			{
//				// 전 숫자 * 10 + 1 해서 한자릿수씩 증가시키는 것
//				cnt = (cnt * 10) + 1;
//				cnt %= n;
//				// 자릿수 체크
//				ret++;
//			}
//		}
//	}
//
//	return 0;
//}

//const int V = 4;
//vector<int> adj[V];
//int main()
//{
//	adj[0].push_back(1);
//	adj[0].push_back(2);
//	adj[0].push_back(3);
//
//	adj[1].push_back(0);
//	adj[1].push_back(2);
//
//
//	adj[2].push_back(0);
//	adj[2].push_back(1);
//
//
//	adj[3].push_back(0);
//
//	/*for (int i = 0; i < V; i++)
//	{
//		cout << i << " :: ";
//		for (int there : adj[i])
//		{
//			cout << there << " ";
//		}
//		cout << '\n';
//	}*/
//
//	for (int i = 0; i < 4; i++)
//	{
//		cout << i << " :: ";
//		for (int j = 0; j < adj[i].size(); j++)
//		{
//			cout << adj[i][j] << " ";
//		}
//		cout << '\n';
//	}
//}

//const int V = 10;
//vector<int> adj[V];
//int visited[V];
//void go(int idx)
//{
//	cout << idx << '\n';
//	visited[idx] = 1;
//	for (int there : adj[idx])
//	{
//		if (visited[there])
//			continue;
//		go(there);
//	}
//	return;
//}
//
//int main()
//{
//	adj[1].push_back(2);
//	adj[2].push_back(1);
//
//	adj[1].push_back(3);
//	adj[3].push_back(1);
//
//	adj[3].push_back(4);
//	adj[4].push_back(3);
//
//	for (int i = 0; i < V; i++)
//	{
//		if (adj[i].size() && visited[i] == 0)
//			go(i);
//	}
//}
//
//

//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, - 1 };
//
//int main()
//{
//	int y = 0, x = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		cout << ny << " : " << nx << '\n';
//	}
//
//	return 0;
//}

const int n = 3;
int a[n][n], visited[n][n];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void go(int y, int x)
{
	visited[y][x] = 1;
	cout << y << " : " << x << "\n";
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		go(ny, nx);
	}
	return;
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		go(0, 0);
	}
}


