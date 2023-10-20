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
#include <queue>

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

//const int n = 3;
//int a[n][n], visited[n][n];
//const int dy[] = { -1, 0, 1, 0 };
//const int dx[] = { 0, 1, 0, -1 };
//
//void go(int y, int x)
//{
//	visited[y][x] = 1;
//	cout << y << " : " << x << "\n";
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
//		if (a[ny][nx] == 0) continue;
//		if (visited[ny][nx]) continue;
//		go(ny, nx);
//	}
//	return;
//}
//
//int main()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//		go(0, 0);
//	}
//}


//const int n = 6;
//vector<int> adj[n];
//int visited[n];
//void dfs(int u)
//{
//	visited[u] = 1; // true 방문했다. 
//	cout << u << "\n"; // 방문한 노드 출력
//	for (int v : adj[u])
//	{
//		if (visited[v] == 0) // 방문하지 않았던 노드의 경우
//		{
//			dfs(v); // 다시 깊이 우선 탐색
//		}
//	}
//	cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
//	return;
//}
//
//int main()
//{
//	adj[1].push_back(2);
//	adj[1].push_back(3);
//	adj[2].push_back(4);
//	adj[4].push_back(2);
//	adj[2].push_back(5);
//	dfs(1);
//}
//
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0,1, 0, -1 };
//int m, n, k, y, x, ret, ny, nx, t;
//int a[104][104];
//bool visited[104][104];
//
//void dfs(int y, int x)
//{
//	visited[y][x] = 1;
//	cout << y << " : " << x << '\n';
//
//	for (int i = 0; i < 4; i++)
//	{
//		ny = y + dy[i];
//		nx = x + dx[i];
//		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
//		if (a[ny][nx] == 1 && !visited[ny][nx])
//			dfs(ny, nx);
//	}
//	return;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (a[i][j] == 1 && !visited[i][j])
//			{
//				cout << i << " : " << j << '\n';
//				cout << ret << " : " << " dfs가 시작됩니다.'\n";
//				ret++;
//				dfs(i, j);
//			}
//		}
//	}
//
//	cout << ret << '\n';
//	return 0;
//}

//vector<int> adj[100];
//int visited[100];
//int nodeList[] = { 10, 12, 14, 16, 18, 20, 22 ,24 };
//void bfs(int here)
//{
//	queue<int> q;
//	visited[here] = 1;
//	q.push(here);
//	while (q.size())
//	{
//		int here = q.front(); 
//		q.pop();
//
//		for (int there : adj[here])
//		{
//			if (visited[there]) continue;
//			visited[there] = visited[here] + 1; // 가중치 부여
//			q.push(there);
//		}
//	}
//}
//
//int main()
//{
//	adj[10].push_back(12);
//	adj[10].push_back(14);
//	adj[10].push_back(16);
//
//
//	adj[12].push_back(18);
//	adj[12].push_back(20);
//
//
//	adj[20].push_back(22);
//	adj[20].push_back(24);
//	bfs(10);
//
//	for (int i : nodeList)
//	{
//		cout << i << " : " << visited[i] << '\n';
//	}
//
//	cout << "10번으로부터 24번까지의 최단거리는 : " << visited[24] - 1 << '\n';
//	return 0;
//}


//const int max_n = 104;
//int dy[4] = { -1, 0, 1, 0 };
//int dx[4] = { 0, 1, 0, -1 };
//int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;
//
//int main()
//{
//	scanf("%d %d", &n, &m);
//	cin >> sy >> sx;
//	cin >> ey >> ex;
//
//	for(int i =0; i <n; i++)
//	{
//		for(int j = 0; j < m; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	queue<pair<int, int>> q;
//	visited[sy][sx] = 1;
//	q.push({ sy,sx });
//	while(q.size())
//	{
//		tie(y, x) = q.front();
//		q.pop();
//
//		for(int i =0; i < 4; i++)
//		{
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
//
//			if (visited[ny][nx]) continue;
//
//			visited[ny][nx] = visited[y][x] + 1;
//			q.push({ ny, nx });
//		}
//	}
//	printf("%d\n", visited[ey][ex]);
//	// 최단거리 디버깅
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < m; j++)
//		{
//			cout << visited[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}

vector<int> adj[1004];
int visited[1004];

void postOrder(int here)
{
	if(visited[here] == 0)
	{
		if (adj[here].size() == 1)
			postOrder(adj[here][0]);
		if(adj[here].size() == 2)
		{
			postOrder(adj[here][0]);
			postOrder(adj[here][1]);
		}
		visited[here] = 1;
		cout << here << ' ';
	}
}

void preOrder(int here)
{
	if(visited[here] == 0)
	{
		visited[here] = 1;
		cout << here << ' ';
		if (adj[here].size() == 1)
			preOrder(adj[here][0]);
		if(adj[here].size() ==2)
		{
			preOrder(adj[here][0]);
			preOrder(adj[here][1]);
		}
	}
}

void inOrder(int here)
{
	if(visited[here] == 0)
	{
		if(adj[here].size() ==1)
		{
			inOrder(adj[here][0]);
			visited[here] = 1;
			cout << here << ' ';
		}
		else if (adj[here].size() == 2)
		{
			inOrder(adj[here][0]);
			visited[here] = 1;
			cout << here << ' ';

			inOrder(adj[here][1]);
		}
		else
		{
			visited[here] = 1;
			cout << here << ' ';
		}
	}
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);

	int root = 1;

	cout << "\n 트리순회 : postOrder \n";
	postOrder(root);
	memset(visited, 0, sizeof(visited));

	cout << "\n 트리순회 : preOrder \n";
	preOrder(root);
	memset(visited, 0, sizeof(visited));

	cout << "\n 트리순회 : inOrder \n";
	inOrder(root);

	return 0;

















}