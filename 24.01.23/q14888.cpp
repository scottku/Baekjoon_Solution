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

class SUM
{
public:
	int data;
	int _plus;
	int _minus;
	int _mult;
	int _div;

	SUM(int d, int p, int m, int mult, int div)
	{
		data = d;
		_plus = p;
		_minus = m;
		_mult = mult;
		_div = div;
	}
};

int n;
queue<SUM> q;
vector<int> v;
vector<int> v_operator;
vector<int> v_answer;

int main(void)
{
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &temp);
		v_operator.push_back(temp);
	}

	SUM s(v[0], v_operator[0], v_operator[1], v_operator[2], v_operator[3]);
	q.push(s);
	int index = 1;
	while (!q.empty())
	{
		int data = q.front().data;
		int _plus = q.front()._plus;
		int _minus = q.front()._minus;
		int _mult = q.front()._mult;
		int _div = q.front()._div;
		int index = n - (_plus + _minus + _mult + _div); // 10개의 숫자, 9개의 연산자 중 연산자 갯수가 8개라면 다음 사용될 index는 10-8=2
		q.pop();

		if (_plus != 0)
		{
			if (_plus + _minus + _mult + _div - 1 == 0)
				v_answer.push_back(data + v[index]);
			else
			{
				SUM _s(data + v[index], _plus - 1, _minus, _mult, _div);
				q.push(_s);
			}
		}
		if (_minus != 0)
		{
			if (_plus + _minus + _mult + _div - 1 == 0)
				v_answer.push_back(data - v[index]);
			else
			{
				SUM _s(data - v[index], _plus, _minus - 1, _mult, _div);
				q.push(_s);
			}
		}
		if (_mult != 0)
		{
			if (_plus + _minus + _mult + _div - 1 == 0)
				v_answer.push_back(data * v[index]);
			else
			{
				SUM _s(data * v[index], _plus, _minus, _mult - 1, _div);
				q.push(_s);
			}
		}
		if (_div != 0)
		{
			if (_plus + _minus + _mult + _div - 1 == 0)
			{
				if (data < 0)
				{
					v_answer.push_back(data * (-1) / v[index] * (-1));
				}
				else
				{
					v_answer.push_back(data / v[index]);
				}
			}
			else
			{
				if (data < 0)
				{
					int temp = data * (-1) / v[index] * (-1);
					SUM _s(temp, _plus, _minus, _mult, _div - 1);
					q.push(_s);
				}
				else
				{
					SUM _s(data / v[index], _plus, _minus, _mult, _div - 1);
					q.push(_s);
				}
			}
		}
	}

	sort(v_answer.begin(), v_answer.end(), greater<int>());
	printf("%d\n", v_answer[0]);
	printf("%d", v_answer[v_answer.size() - 1]);
}