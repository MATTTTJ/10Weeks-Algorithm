// 2Weeks Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// algorithm 2910 (custom operator)

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	// 같은 수를 카운팅하고 대소 비교를 통해 정렬하기 위함
	if(a.first == b.first)
	{
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

int main()
{
	cin >> n >> c;

	for(int i =0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
		// 숫자를 인덱스로 사용하고 같은 인덱스가 있는지 체크해서 카운팅을 늘리는 방식
		if (mp_first[a[i]] == 0)
			mp_first[a[i]] = i + 1;
	}
	// 키 값에 카운팅이 들어가기 때문에 이를 기반으로 정렬하기 위함
	for(auto it : mp)
	{
		v.push_back({ it.second, it.first });
	}

	sort(v.begin(), v.end(), cmp);

	for(auto it : v)
	{
		for(int j = 0; j < it.first; j++)
		{
			cout << it.second << " ";
		}
	}

	return 0;
}


