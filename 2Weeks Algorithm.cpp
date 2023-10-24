// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 2828

int n, m, j, l, r, temp, ret;
int main()
{
	cin >> n >> m >> j;
	l = 1;
	for(int i = 0; i < j; i++)
	{
		r = l + m -1;
		cin >> temp;

		if (temp >= l && temp <= r) continue;
		else
		{
			if(temp < l)
			{
				ret += (l - temp);
				l = temp;
			}
			else
			{
				l += (temp - r);
				ret += (temp - r);
			}
		}
	}

	cout << ret << "\n";
	return 0;
}


