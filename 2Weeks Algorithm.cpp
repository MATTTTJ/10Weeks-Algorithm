// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 4659

string s;
int lcnt, vcnt;

bool isVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
	while(true)
	{
		cin >> s;
		if (s == "end") break;

		lcnt = vcnt = 0;

		bool flag = false;
		bool is_include_v = 0;
		int prev = -1;

		for(int i =0; i < s.size(); i++)
		{
			int idx = s[i];

			// 모음인지 체크
			if (isVowel(idx))
				lcnt++, vcnt = 0, is_include_v = 1;
			else
				vcnt++, lcnt = 0;

			if (vcnt == 3 || lcnt == 3)
				flag = 1;

			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o'))
			{
				flag = 1;
			}
			prev = idx;
		}

		if (is_include_v == 0)
			flag = 1;

		if (flag)
			cout << "<" << s << ">" << " is not acceptable.\n";
		else
			cout << "<" << s << ">" << " is acceptable.\n";
	}

	return 0;
}