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

int n;
pair<int, int> arr[501];
// dp를 왜 사용할 수 있을까? -> 문제를 부분부분 잘랐을 때 소규모의 문제가 대규모의 문제의 일부분이 된다.
// 1~5번 까지의 행렬 계산에 있어, 경우의 수를 따져보면 1 x 2~5 , 1~2 x 3~5 이런 식으로 부분부분의 문제들이 큰 문제의 일부분으로 나타난다.
int dp[501][501]; // dp[a][b] => a 번째 행렬부터 b 번째 행렬까지 곱했을 때 연산의 최솟값

int DP(int _start, int _end)
{
	if (dp[_start][_end] != INT_MAX)
		return dp[_start][_end];

	int answer = INT_MAX;
	for (int i = _start; i < _end; i++)
	{
		dp[_start][_end] = min(dp[_start][_end], DP(_start, i) + DP(i + 1, _end) + arr[_start].first * arr[i].second * arr[_end].second);
	}

	return dp[_start][_end];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}

	int answer = DP(1, n);

	cout << answer;
}