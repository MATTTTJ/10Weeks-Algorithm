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
#include <vector>

using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main()
{
	cin >> s;

	for(char a : s)
	{
		// 카운팅 배열 문자 카운팅하기
		cnt[a]++;
	}

	for(int i = 'Z'; i >= 'A'; i--)
	{
		if(cnt[i])
		{
			if(cnt[i] & 1) // 해당 문자열이 1개인 경우
			{
				// 한개인 경우 중앙에 넣을 것
				mid = char(i);
				// flag가 2개 이상인 경우는 실패
				flag++;
				cnt[i]--;
			}
			if (flag == 2)
				break;
			for(int j = 0; j < cnt[i]; j += 2)
			{
				ret = char(i) + ret;
				ret += char(i);
			}
		}
	}

	// mid에 값이 있을 경우
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo\n";
	else
		cout << ret << "\n";

	return 0;
}