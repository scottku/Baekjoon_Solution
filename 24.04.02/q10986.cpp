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
#include <time.h>

using namespace std;

int N, M;
vector<long long> v_sum;
vector<int> v_div;
long long _div[1001];
long long answer = 0;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(_div, 0, sizeof(_div));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (i == 0)
		{
			v_sum.push_back(temp);
		}
		else
			v_sum.push_back(temp + v_sum[i - 1]);

		v_div.push_back((int)(v_sum[i] % M));
		_div[v_div[i]]++;
	}

	for (int i = 0; i < M; i++)
	{
		if (_div[i] >= 2)
			answer += _div[i] * (_div[i] - 1) / 2;
	}
	cout << answer + _div[0]; // 나머지가 0인 부분은 하나만 선택해도 가능하기 때문
}