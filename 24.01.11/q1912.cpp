#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

stack<int> s;
vector<int> v;
vector<int> dp;
int _minus = 0;

int main(void)
{
	int n;
	scanf("%d", &n);

	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v.push_back(temp); // 10 - 4 3 1 5 6 - 35 12 21 - 1
		if (temp < 0)
			_minus++;
	}

	// 순서대로 합을 구한다 -> 그 합이 음수가 되어버리는 순간 그 아랫부분은 버린다
	// 10 -4 3 1 5 6 -35 12 21 -1 기준, 앞의부분을 다 더하다가 -35가 더해지면서 다음과 같은 수열로 변한다
	// (음수 값) 12 21 -1
	// (음수 값)은 무시하고 12 21 ... 쭉 더해가면 된다.

	int _max = 0;
	int answer = 0;
	if (n == 1) // 배열이 1개면 그 수를 출력
	{
		printf("%d", v[0]);
		return 0;
	}

	if (_minus == v.size()) // 모든 수가 음수면, 가장 큰 수 한개만 출력
	{
		int _min = -1001; // 입력 받는 수 중 가장 작은 수는 -1000
		for (int i = 0; i < v.size(); i++)
		{
			_min = max(_min, v[i]);
		}
		printf("%d", _min);
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		_max += v[i];
		if (_max < 0)
		{
			_max = 0; // 음수로 넘어가버리면 아래쪽 친구들은 전부 버려버림
			continue;
		}
		answer = max(answer, _max); // 기존 최대값 vs 현재 더해지면서 생간 값
	}

	printf("%d", answer);
}