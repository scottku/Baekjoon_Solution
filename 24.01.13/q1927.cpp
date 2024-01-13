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
	int _size = dq.size() - 1; // 0부터 1000번까지 있었다면, 사이즈는 1001개
	if (dq[_size / 2] > i) // 부모가 새로 들어온 애보다 크면
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
			// 이론상 틀린 방식은 아니나 시간초과 issue
			/*
			if (dq.size() <= 1) // 0 1개만 있으면
			{
				printf("%d\n", 0);
			}
			else
			{
				dq.pop_front(); // 맨 앞의 0 빼고
				printf("%lld\n", dq.front()); // 제일 작은 수
				dq.pop_front(); // 출력한거 빼고
				if (dq.size() > 0)
				{
					dq.push_front(dq.back()); // 가장 뒤의 수 앞으로 가져옴
					dq.pop_back();
				}
				dq.push_front(0); // 맨 앞의 0 추가
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