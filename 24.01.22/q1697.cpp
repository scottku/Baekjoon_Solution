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
#include <sstream>
#include <unordered_map>

using namespace std;

deque<pair<int, int>> dq;
vector<int> v;
bool visit[100001];

int main(void)
{
	memset(visit, false, sizeof(visit));
	int x, y;
	scanf("%d %d", &x, &y);
	// 연산은 빼기, 더하기, 곱하기 3종류
	dq.push_back({ x, 0 });
	while (!dq.empty())
	{
		int _start = dq.front().first;
		int _count = dq.front().second;
		dq.pop_front();

		// Loop 초기에 visit을 true로 변경해주면, true로 변경되기 전에 겹치는 친구들이 dq에 우르르 들어갈 수 있다
		// dq에 push_back 하기 전에 미리 visit 을 true로 변경해서 바로바로 겹치는 녀석들이 dq에 못들어가도록 막자
		// visit[_start] = true;

		if (_start == y)
		{
			v.push_back(_count);
			break;
		}

		if (_start - 1 >= 0 && !visit[_start - 1])
		{
			dq.push_back({ _start - 1, _count + 1 });
			visit[_start - 1] = true;
		}
		if (_start + 1 <= 100000 && !visit[_start + 1])
		{
			dq.push_back({ _start + 1, _count + 1 });
			visit[_start + 1] = true;
		}
		if (_start * 2 <= 100000 && !visit[_start * 2])
		{
			dq.push_back({ _start * 2, _count + 1 });
			visit[_start * 2] = true;
		}
	}

	printf("%d", v[0]);
}