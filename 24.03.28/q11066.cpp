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

int test_case;
int n;
int arr[501];
// dp를 왜 사용할 수 있을까? -> 문제를 부분부분 잘랐을 때 소규모의 문제가 대규모의 문제의 일부분이 된다.
// 1~5번 까지의 계산에 있어, 경우의 수를 따져보면 1 x 2~5 , 1~2 x 3~5 이런 식으로 부분부분의 문제들이 큰 문제의 일부분으로 나타난다.
pair<int, int> dp[501][501];
// dp[a][b]
// first 값 : dp[a][x].first + dp[x+1][b].first, 계산된 값 그 자체만 확인
// second 값 : dp[a][x].first + dp[a][x].second + dp[x+1][b].first + dp[x+1][b].second,
// 방금 계산된 두 합 전부터 누적되어왔던 계산 값들을 전부 포함
pair<int, int> DP(int _start, int _end)
{
	if (dp[_start][_end].first != INT_MAX)
		return dp[_start][_end];

	for (int i = _start; i < _end; i++)
	{
		pair<int, int> dp1 = DP(_start, i);
		pair<int, int> dp2 = DP(i + 1, _end);
		if (dp[_start][_end].second > dp1.first + dp2.first + dp1.second + dp2.second)
		{
			dp[_start][_end].first = dp1.first + dp2.first;
			dp[_start][_end].second = dp1.first + dp2.first + dp1.second + dp2.second;
		}
	}

	return dp[_start][_end];
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_case;

	for (int tc = 0; tc < test_case; tc++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if (i == j)
					dp[i][j] = { 0, INT_MAX };
				else
					dp[i][j] = { INT_MAX, INT_MAX };
			}
		}

		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			dp[i][i] = { arr[i], 0 };
		}

		pair<int, int> answer = DP(1, n);

		cout << answer.second << '\n';
	}
}