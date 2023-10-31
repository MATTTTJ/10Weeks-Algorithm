// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 10709

int n, m, a[104][104];
string s;

int main()
{
	cin >> n >> m;
	for(int i =0; i <n; i++)
	{
		cin >> s;
		for(int j = 0; j < m; j++)
		{
			if (s[j] == '.')
				a[i][j] = -1;
			else
				a[i][j] = 0;
		}
	}

	for(int i =0; i < n; i++)
	{
		for(int j =0; j < m; j++)
		{
			if(a[i][j] == 0)
			{
				int cnt = 1;

				while(a[i][j+1] == -1)
				{
					a[i][j + 1] = cnt++;
					j++;
				}
			}
		}
	}

	for(int i =0; i < n; i++)
	{
		for(int j =0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
