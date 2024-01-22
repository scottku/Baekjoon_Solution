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
	// ������ ����, ���ϱ�, ���ϱ� 3����
	dq.push_back({ x, 0 });
	while (!dq.empty())
	{
		int _start = dq.front().first;
		int _count = dq.front().second;
		dq.pop_front();

		// Loop �ʱ⿡ visit�� true�� �������ָ�, true�� ����Ǳ� ���� ��ġ�� ģ������ dq�� �츣�� �� �� �ִ�
		// dq�� push_back �ϱ� ���� �̸� visit �� true�� �����ؼ� �ٷιٷ� ��ġ�� �༮���� dq�� �������� ����
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