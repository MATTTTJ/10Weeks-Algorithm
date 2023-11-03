// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

// algorithm 4949

int main()
{
	CODINGTEST
	while(true)
	{
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		stack<int> stk;
		bool check = true;
		for(int i = 0;i < s.length(); i++)
		{
			if(s[i] == ')')
			{
				if(stk.size() == 0 || stk.top() == '[')
				{
					check = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			if(s[i] == ']')
			{
				if(stk.size() == 0 || stk.top() == '(')
				{
					check = false;
					break;
				}
				else
				{
					stk.pop();
				}
			}
			if (s[i] == '(')
				stk.push(s[i]);
			if (s[i] == '[')
				stk.push(s[i]);
		}
		if (check && stk.size() == 0)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}