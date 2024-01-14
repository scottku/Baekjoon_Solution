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
#include <algorithm>
#include <queue>

using namespace std;

vector<long long> v1;
vector<long long> v2;

int main(void)
{
	// �ð��ʰ� -> ���� ����Ž���ΰǰ�?
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		long long temp;
		scanf("%lld", &temp);
		v1.push_back(temp);
		v2.push_back(temp);
	}

	sort(v1.begin(), v1.end()); // ����
	v1.erase(unique(v1.begin(), v1.end()), v1.end()); // unique �Լ� : �ߺ��� �� 1�� ���� �� ���������� �ǵڷ� ������ �� �ڷΰ� �ε��� ���� ������
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin());
	}
}
// �Ʒ��� �ð� �ʰ�
/*
vector<pair<int, int>> v;
priority_queue<int> pq;
int arr[1000001];

int main(void)
{
	int n;
	scanf("%d", &n);
	int temp_n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp_n);
		pair<int, int> tp;
		tp.first = temp_n;
		tp.second = i;
		v.push_back(tp);
		pq.push(temp_n);
	}

	for (int i = 0; i < n; i++)
	{
		if (pq.size() == 1) // ������ 1�� = ������ 0 ¥�� 1��
			break;

		int _top = pq.top(); // ���� ū�� ��������
		int _same = 1;
		pq.pop(); // ���������� ����
		while (true)
		{
			if (_top == pq.top()) // ���� ���� �ߺ����� �ڿ� �� ������
			{
				pq.pop(); // ��������
				_same++;
				continue;
			}
			break;
		}
		int _size = pq.size(); // pq�� ���� ������������ ���ĵ� -> ���� ��ġ �� ������ �˸� �ڱ⺸�� ������ ����� �ٷ� Ȯ�� ����
		// size�� 100���� 0��°�� �ִ� ģ���� �ڱ⺸�� 99���� ���� ģ������ ����. ���� �����Ÿ� ��������
		for (int j = 0; j < n; j++)
		{
			if (v[j].first == _top)
			{
				arr[v[j].second] = _size;
				_same--;
			}
			if (_same == 0)
				break;
		}
	}

	for (int i = 1; i <= n-1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("%d", arr[n]);
}
*/