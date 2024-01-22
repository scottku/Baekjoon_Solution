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
		while (!q.empty()) // �� ���� ��带 �����ϰ� �߰��� 2���� ��ġ�� �κ��� ����
		{                  // �� �� �� ���� �� 1���� �־���� �ð� �ʰ��� �߻����� ����
			int x = q.front().first.first; // �հ�
			int num = q.front().first.second; // ���������� ���� ��ġ
			int floor = q.front().second; // �� ��(height)

			q.pop();

			if (num + floor >= v.size() || num + floor + 1 >= v.size()) // �ﰢ�� ���� ���
			{
				if (_result < x)
					_result = x;
			}
			else
			{
				if (arr[num + floor] == 0) // ���� ���� ������ �ʾҴٸ�
				{
					arr[num + floor] = x + v[num + floor].first; // �ϴ� ���� �迭�� �߰���
					if (m.find(num + floor) != m.end()) // �ش� �ٿ��� �� ���ڸ� ���� ��ġ�� ���� ����
						q.push({ { x + v[num + floor].first, num + floor }, floor + 1 });
				}
				else
				{
					if (arr[num + floor] < x + v[num + floor].first) // ���� ���� ���ؼ� �� ũ�ٸ�
					{
						arr[num + floor] = x + v[num + floor].first; // �ش� ��ġ������ �ִ��� �����ϰ�
						q.push({ { x + v[num + floor].first, num + floor }, floor + 1 }); // queue�� �߰�
					}
					else
						q.push({ { arr[num + floor], num + floor }, floor + 1 }); // ���� ���� �� ũ�� ���� ���� queue�� �߰�
				} // �� ������� queue�� 2���� ���� 1���� ������ ����, �Ʒ��� ���� ������ ����
				if (arr[num + floor + 1] == 0)
				{
					arr[num + floor + 1] = x + v[num + floor + 1].first;
					if (m.find(num + floor + 1 + 1) != m.end()) // �ش� �ٿ��� �� ���ڸ� ��
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
		printf("%d", _result); // ��� ���� �ִ����� ���
	}
}