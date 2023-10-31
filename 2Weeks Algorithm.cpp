// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 3474

int n, a;

vector<int> v;

int main()
{
	cin >> n;
	for(int i =0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}

	for (auto it : v)
	{
		int ret2 = 0, ret5 = 0;
		for (int j = 2; j <= it; j *= 2)
		{
			ret2 += it / j;
		}

		for (int j = 5; j <= it; j *= 5)
		{
			ret5 += it / j;
		}
		cout << min(ret2, ret5) << "\n";
	}
	return 0;
}

