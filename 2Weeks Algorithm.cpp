// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define CODINGTEST cin.tie(NULL); cout.tie(NULL); 

using namespace std;

// algorithm 9012

int n;
string s;

bool check(string s)
{
	stack<char> stk;
	for(char c : s)
	{
		if (c == '(')
			stk.push(c);
		else
		{
			if (!stk.empty())
				stk.pop();
			else
				return false;
		}
	}
	return stk.empty();
}

int main()
{
	cin >> n;
	for(int i =0; i <n; i++)
	{
		cin >> s;
		if (check(s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}