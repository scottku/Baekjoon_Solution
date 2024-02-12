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

int N;
int M;
int _startHere, _end;
int arr[1001][1001];
int value[1001];

int main(void)
{
	memset(value, 0, sizeof(value));
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i <= N; i++)
	{
		value[i] = INT_MAX;
		for (int j = 0; j <= N; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int s, e, m;
		scanf("%d %d %d", &s, &e, &m);
		if (arr[s][e] > m) // a에서 b로 이동하는 길이 여러개 있을 수 있다.
			arr[s][e] = m;
	}

	scanf("%d %d", &_startHere, &_end);

	value[_startHere] = 0;
	queue<pair<int, int>> q;
	q.push({ 0, _startHere });
	while (!q.empty())
	{
		int _v = q.front().first;
		int _s = q.front().second;
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			int W = arr[_s][i];
			if (W == INT_MAX)
				continue;

			if (_v + W < value[i])
			{
				value[i] = _v + W;
				q.push({ _v + W, i });
			}
		}
	}

	printf("%d", value[_end]);
}