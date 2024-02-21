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
#include <climits>

using namespace std;

int n;
vector<int> v_minus;
vector<int> v_plus;
vector<int> v;

int main(void)
{
	scanf("%d", &n);
	int n_minus = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), less<int>());
	int _start = 0;
	int _end = v.size() - 1;
	pair<int, int> p_answer = { 1000000001, 1000000001 };
	while (_start < _end)
	{
		if (abs(p_answer.first + p_answer.second) > abs(v[_start] + v[_end]))
		{
			p_answer.first = v[_start];
			p_answer.second = v[_end];
		}

		if (v[_start] + v[_end] > 0)
		{
			_end--;
		}
		else if (v[_start] + v[_end] < 0)
		{
			_start++;
		}
		else // 합이 0
		{
			break;
		}
	}
	printf("%d %d", p_answer.first, p_answer.second);

}