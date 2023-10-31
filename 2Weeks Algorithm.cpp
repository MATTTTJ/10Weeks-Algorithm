// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 2870

int n;
vector<string> v;
string s, ret;

void go()
{
	//0지우기
	while(true)
	{
		if (ret.size() && ret.front() == '0')
			ret.erase(ret.begin());
		else
			break;
	}
	if (ret.size() == 0)
		ret = "0";
	v.push_back(ret);
	ret = "";
}
// 문자열인 숫자를 비교하기 위함
bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;

	return a.size() < b.size();
}

int main()
{
	cin >> n;

	for(int i =0; i < n; i++)
	{
		cin >> s;
		ret = "";
		for(int j =0; j < s.size(); j++)
		{
			if (s[j] < 65)
				ret += s[j];
			else if (ret.size())
				go();
		}
		if (ret.size())
			go();
	}
	sort(v.begin(), v.end(), cmp);
	for (string i : v)
		cout << i << "\n";


	return 0;
}