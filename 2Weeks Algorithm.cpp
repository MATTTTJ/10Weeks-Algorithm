// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define CODINGTEST cin.tie(NULL); cout.tie(NULL); 
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;


#define prev HOON
// algorithm 2852

int n, o, A, B, asum, bsum;
string s, prev;

// 초를 분으로 표기하기 위한 함수
string print(int a)
{
	// 00을 더하는 이유는 포맷화하기 위함 (7 이 아닌 007로 만들기)
	string d = "00" + to_string(a / 60);
	string e = "00" + to_string(a % 60);

	// 그리고 뒤에서 2자리 수 빼내기
	return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
}
// 분에 60곱하기 + 초 더하기
int changeToInt(string a)
{
	return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

// 분,초를 초로 바꿔주는 과정
void go(int &sum, string s)
{
	sum += (changeToInt(s) - changeToInt(prev));
}

int main()
{
	CODINGTEST

	cin >> n;
	for(int i = 0; i< n; i++)
	{
		cin >> o >> s;
		// 어느팀이 이기고 있는지
		if (A > B) go(asum, s);
		else if (B > A)
			go(bsum, s);
		// 어떤 팀이 이겼는지에 따라 분기 나누기 위함
		o == 1 ? A++ : B++;
		prev = s;
	}

	// 누가 이기고 있는지에 따라 마지막으로 이기고 있던 시간 최종 더함
	if (A > B)
		go(asum, "48:00");
	else if (B > A)
		go(bsum, "48:00");

	cout << print(asum) << "\n";
	cout << print(bsum) << "\n";
}
