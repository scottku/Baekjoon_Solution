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

vector<long long> v_lan;

long long LENGTH_MAX = 0;
long long n_need = 0;

int main(void)
{
	long long n_lan;
	scanf("%lld %lld", &n_lan, &n_need);

	int lan_max = 0;

	for (int i = 0; i < n_lan; i++)
	{
		long long temp;
		scanf("%lld", &temp);

		v_lan.push_back(temp);
	}

	sort(v_lan.begin(), v_lan.end(), less<long long>()); // 오름차순 정렬

	long long answer = 0;
	long long _result = 0;

	// 숫자가 원체 크다 -> 2중 for문이고 자시고 단일 for문으로도 힘들 수 있다 -> 이진탐색 ㄱㄱ
	long long _start = 0;
	long long _end = v_lan[n_lan - 1];

	while (_end >= _start)
	{
		long long mid = (_start + _end) / 2;
		if (mid == 0)
			mid = 1;
		for (int i = n_lan - 1; i >= 0; i--)
		{
			answer += v_lan[i] / mid;
		}

		if (answer >= n_need)
		{
			_result = mid;
			_start = mid + 1;
		}
		else
			_end = mid - 1;

		answer = 0;
	}

	// 충족됐다면 최대 높이를 출력
	printf("%d", _result);
}