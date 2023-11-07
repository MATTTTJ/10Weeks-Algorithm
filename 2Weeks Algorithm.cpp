// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define CODINGTEST cin.tie(NULL); cout.tie(NULL); 

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;

// algorithm 1068

int n, r, temp, root;
vector<int> adj[54];
// 트리는 루트 노드부터 탐색할 것
// here에서 there로 갈 때 지워진 곳이라면 가지 않는다는 로직 기반

int dfs(int here)
{
	// 리프 노드의 수를 의미
	int ret = 0;
	int child = 0;
	for(int there : adj[here])
	{
		// 지워진 노드인지? 
		if (there == r)
			continue;
		ret += dfs(there);
		child++;
	}
	// 자식 노드가 없는 경우 리프 노드에서 1을 반환한 것을 윗 노드에서 더해진다.
	if (child == 0)
		return 1;

	return ret;
}

int main()
{
	cin >> n;
	for(int i= 0; i <n; i++)
	{
		cin >> temp;
		if (temp == -1)
			root = i;
		else
			adj[temp].push_back(i);
	}
	cin >> r;

	// here이 지워진 경우 예외처리
	if(r == root)
	{
		cout << 0 << "\n";
		return 0;
	}
	cout << dfs(root) << "\n";
	return 0;
}
