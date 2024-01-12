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

using namespace std;

vector<long long> v_tree;

long long HEIGHT_MAX = 0;
long long n_meter = 0;

int main(void)
{
	long long n_tree;
	scanf("%lld %lld", &n_tree, &n_meter);

	int tree_max = 0;

	for (int i = 0; i < n_tree; i++)
	{
		long long temp;
		scanf("%lld", &temp);

		v_tree.push_back(temp);
	}

	sort(v_tree.begin(), v_tree.end(), less<long long>()); // 오름차순 정렬

	long long answer = 0;
	long long _result = 0;

	// 숫자가 원체 크다 -> 2중 for문 힘들 수 있다 -> 이진탐색 ㄱㄱ
	long long _start = 0;
	long long _end = v_tree[n_tree - 1];

	while (_end >= _start)
	{
		long long mid = (_start + _end) / 2;
		for (int i = n_tree - 1; i >= 0; i--)
		{
			if (v_tree[i] > mid)
				answer += v_tree[i] - mid;
			else
				break;
		}

		if (answer >= n_meter)
		{
			_result = mid;
			_start = mid + 1;
		}
		else
			_end = mid - 1;

		answer = 0;
	}

	// 충족됐다면 최대 높이를 출력
	printf("%lld", _result);
}