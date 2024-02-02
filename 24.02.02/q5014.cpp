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
#include <queue>

using namespace std;

int _floor, _now, _dest, _up, _down;
bool visit[1000001];

int main(void)
{
	memset(visit, false, sizeof(visit));
	scanf("%d %d %d %d %d", &_floor, &_now, &_dest, &_up, &_down);

	if (_now == _dest)
		printf("%d", 0);
	else if (_up == 0 && _dest > _now)
	{
		printf("%s", "use the stairs");
	}
	else if (_down == 0 && _now > _dest)
		printf("%s", "use the stairs");
	else
	{
		bool _b = false;
		int cnt = 0;
		queue<pair<int, int>> q;
		if (_now > _dest)
		{
			if ((_now - _dest) % _down == 0)
			{
				printf("%d", (_now - _dest) / _down);
				return 0;
			}
			else
			{
				cnt = (_now - _dest) / _down;
				q.push({ _now - _down * cnt, cnt });
				visit[_now - _down * cnt] = true;
			}
		}
		else
		{
			if ((_dest - _now) % _up == 0)
			{
				printf("%d", (_dest - _now) / _up);
				return 0;
			}
			else
			{
				cnt = (_dest - _now) / _up;
				q.push({ _now + _up * cnt, cnt });
				visit[_now + _up * cnt] = true;
			}
		}

		while (!q.empty())
		{
			int cur = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (cur + _up == _dest || cur - _down == _dest)
			{
				printf("%d", cnt + 1);
				_b = true;
				break;
			}
			else
			{
				if (cur + _up <= _floor && !visit[cur + _up])
				{
					visit[cur + _up] = true;
					q.push({ cur + _up, cnt + 1 });
				}
				if (cur - _down >= 1 && !visit[cur - _down])
				{
					visit[cur - _down] = true;
					q.push({ cur - _down, cnt + 1 });
				}
			}
		}
		if (!_b)
			printf("%s", "use the stairs");
	}

}