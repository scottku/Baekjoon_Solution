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

int n, m;
vector<pair<int, int>> v;

// ������a �� ���� ����Ʈ�� ���ߵ� �� �ִ� ������� ���Ѵ�
// ������a �� ������b�� ���� �� �� �ִٸ�, ������b �� ���� �� ģ���� �ٽ� ���Ѵ�.
// ������ ������c�� ������a�͵� ���� �� �� �ִٸ�, ������ a b c�� �� ����Ʈ�� ���Ե� �� �ִ�.
// ������ �ƴ� �������� ����� �� �ִ°�? �ִ� ������ �ش� ���� ���ῡ ���Ե� �� �ִ°�
// >> �迭�� ũ�Ⱑ 10�� * 10�� �̶� ������ ũ�� ����... ���� ����� �ƴ�

int main(void)
{
	scanf("%d", &n);

	for (int tc = 0; tc < n; tc++)
	{
		v.clear();
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		if (m == 1)
		{
			printf("%d\n", 1);
			continue;
		}

		sort(v.begin(), v.end(), less<pair<int, int>>());
		int _count = 1;
		int _rank = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (_rank > v[i].second) // �׸��� �˰������� ������
			{
				_count++;
				_rank = v[i].second; // ���� ������ �����س��� �ٸ��� ������ üũ�غ��鼭 �ϳ��� ������ �÷�������.
			}
		}
		printf("%d\n", _count);
	}
}