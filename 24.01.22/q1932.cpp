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

int n;
vector<pair<int, int>> v;
queue<pair<pair<int, int>, int>> q;
vector<int> v_answer;
int arr[125250];
map<int, int> m;

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	int _count = 0;
	for (int i = 1; i <= n; i++)
	{
		_count += i;
		m.insert({ _count, 1 });
	}
	int temp;
	for (int i = 0; i < _count; i++)
	{
		scanf("%d", &temp);
		v.push_back({ temp, i });
	}
	int _result = 0;

	if (n == 1)
		printf("%d", v[0].first);
	else if (n == 2)
	{
		int t = max(v[0].first + v[1].first, v[0].first + v[2].first);
		printf("%d", t);
	}
	else
	{
		int answer = v[0].first;
		q.push({ { v[0].first + v[1].first, 1 }, 2 });
		q.push({ { v[0].first + v[2].first, 2 }, 2 });
		arr[1] = v[0].first + v[1].first;
		arr[2] = v[0].first + v[2].first;
		while (!q.empty()) // 양 끝쪽 노드를 제외하고 중간에 2개씩 겹치는 부분이 있음
		{                  // 두 값 중 높은 것 1개만 넣어줘야 시간 초과가 발생하지 않음
			int x = q.front().first.first; // 합계
			int num = q.front().first.second; // 마지막으로 더한 위치
			int floor = q.front().second; // 층 수(height)

			q.pop();

			if (num + floor >= v.size() || num + floor + 1 >= v.size()) // 삼각형 범위 벗어남
			{
				if (_result < x)
					_result = x;
			}
			else
			{
				if (arr[num + floor] == 0) // 아직 값이 들어오지 않았다면
				{
					arr[num + floor] = x + v[num + floor].first; // 일단 값을 배열에 추가함
					if (m.find(num + floor) != m.end()) // 해당 줄에서 맨 앞자리 수는 겹치는 값이 없음
						q.push({ { x + v[num + floor].first, num + floor }, floor + 1 });
				}
				else
				{
					if (arr[num + floor] < x + v[num + floor].first) // 기존 값과 비교해서 더 크다면
					{
						arr[num + floor] = x + v[num + floor].first; // 해당 위치에서의 최댓값을 변경하고
						q.push({ { x + v[num + floor].first, num + floor }, floor + 1 }); // queue에 추가
					}
					else
						q.push({ { arr[num + floor], num + floor }, floor + 1 }); // 기존 값이 더 크면 기존 값을 queue에 추가
				} // 이 방식으로 queue에 2개가 들어갈걸 1개만 들어가도록 변경, 아래는 위와 동일한 컨셉
				if (arr[num + floor + 1] == 0)
				{
					arr[num + floor + 1] = x + v[num + floor + 1].first;
					if (m.find(num + floor + 1 + 1) != m.end()) // 해당 줄에서 맨 뒷자리 수
						q.push({ { x + v[num + floor + 1].first, num + floor + 1 }, floor + 1 });
				}
				else
				{
					if (arr[num + floor + 1] < x + v[num + floor + 1].first)
					{
						arr[num + floor + 1] = x + v[num + floor + 1].first;
						q.push({ { x + v[num + floor + 1].first, num + floor + 1 }, floor + 1 });
					}
					else
						q.push({ { arr[num + floor + 1], num + floor + 1}, floor + 1 });
				}
			}
		}
		printf("%d", _result); // 계속 비교한 최댓값으로 출력
	}
}