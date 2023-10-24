// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define y1 aaaa

// algorithm 1992

int n;
string s;
char a[101][101];
string quard(int y, int x, int size)
{
	//기저사례
	if (size == 1)
		return string(1, a[y][x]);

	char b = a[y][x];
	string ret = "";
	for(int i = y; i < y +size; i++)
	{
		for(int j = x; j < x + size; j++)
		{
			if(b != a[i][j])
			{
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}

int main()
{
	cin >> n;
	for(int i =0; i < n; i++)
	{
		cin >> s;
		for(int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}
	cout << quard(0, 0, n) << '\n';
	return 0;

}
