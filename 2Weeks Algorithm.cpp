// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


/**
 * 배수란 ? 4 % 2 == 0 인 경우를 봤을 때 true이면 배수라고 판단한다.
 * 1로만 이루어진 수 중에 n 의 배수 -> 가장 작은 거의 자릿수
 * 111 % (모듈러연산) 3 == 0
 * 이 경우 111의 자릿수는 3, 이 3을 이용해서 111을 나눴을 때 배수가 된다.
 * n이 9901인 경우 12자리가 나온다. 
 */
#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
int n;

int main()
{
	while(cin >> n)
	{
		int cnt = 1, ret = 1;
		while(true)
		{
			// 자릿수가 수의 배수임을 체크하고 자릿수 반환하기
			if(cnt % n ==0)
			{
				// printf("%d\n", ret);
				cout << ret << "\n";
				break;
			}
			else
			{
				// 전 숫자 * 10 + 1 해서 한자릿수씩 증가시키는 것
				cnt = (cnt * 10) + 1;
				cnt %= n;
				// 자릿수 체크
				ret++;
			}
		}
	}

	return 0;
}