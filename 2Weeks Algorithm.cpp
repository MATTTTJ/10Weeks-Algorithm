// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// n : 1 ~ 10만
// k : 1 ~ 10만 - 1 (n 사이 값)
// 온도는 -100 ~ 100
// 연속된 온도의 합이 "최대" 되는 값
// 이 문제의 최솟값은? -100 * 10만  >> -1000만으로 잡을 것
// 최대값은 어디서부터 ?

// ret 에 최댓값을 계속 갱신할 것







#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int n, ret;
string s;

int main()
{
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> s;

		stack<char> stk;

		for(char a : s)
		{
			if (stk.size() && stk.top() == a)
			{
				stk.pop();
			}
			else
				stk.push(a);
		}
		if (stk.size() == 0)
			ret++;
	}

	cout << ret << "\n";
	return 0;
}