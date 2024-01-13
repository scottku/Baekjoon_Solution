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

deque<long long> dq;
priority_queue<int, vector<int>, greater<int>> pq;

void alignment(long long i)
{
	if (dq.size() >= 2 * i + 2)
	{
		if (dq[i] > dq[2 * i] || dq[i] > dq[2 * i + 1])
		{
			if (dq[2 * i] < dq[2 * i + 1])
			{
				long long temp = dq[2 * i];
				dq[2 * i] = dq[i];
				dq[i] = temp; // swap
				alignment(2 * i);
			}
			else
			{
				long long temp = dq[2 * i + 1];
				dq[2 * i + 1] = dq[i];
				dq[i] = temp; // swap
				alignment(2 * i + 1);
			}
		}
	}
	else if (dq.size() == 2 * i + 1)
	{
		if (dq[i] > dq[2 * i])
		{
			long long temp = dq[2 * i];
			dq[2 * i] = dq[i];
			dq[i] = temp; // swap
			alignment(2 * i);
		}
	}
	else
		return;
}

void back_align(long long i)
{
	int _size = dq.size() - 1; // 0���� 1000������ �־��ٸ�, ������� 1001��
	if (dq[_size / 2] > i) // �θ� ���� ���� �ֺ��� ũ��
	{
		long long temp = dq[_size];
		dq[_size] = dq[_size / 2];
		dq[_size / 2] = temp;
		back_align(_size / 2);
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	//dq.push_back(0);

	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 0)
		{
			// �̷л� Ʋ�� ����� �ƴϳ� �ð��ʰ� issue
			/*
			if (dq.size() <= 1) // 0 1���� ������
			{
				printf("%d\n", 0);
			}
			else
			{
				dq.pop_front(); // �� ���� 0 ����
				printf("%lld\n", dq.front()); // ���� ���� ��
				dq.pop_front(); // ����Ѱ� ����
				if (dq.size() > 0)
				{
					dq.push_front(dq.back()); // ���� ���� �� ������ ������
					dq.pop_back();
				}
				dq.push_front(0); // �� ���� 0 �߰�
				alignment(1);
			}
			*/
			if (!pq.empty())
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
				printf("%d\n", 0);

		}
		else
		{
			//dq.push_back(x);
			//back_align(x);
			pq.push(x);
		}
	}
}