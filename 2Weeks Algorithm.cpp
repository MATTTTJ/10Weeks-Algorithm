// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#define CODINGTEST cin.tie(NULL); cout.tie(NULL); 

using namespace std;

// algorithm 1436

int n;

int main()
{
	cin >> n;
	int i = 666;

	for(;; i++)
	{
		if (to_string(i).find("666") != string::npos)
			n--;
		if (n == 0)
			break;
	}

	cout << i << "\n";
}
