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

int n, kg;
int W[101];
int V[101];
int dp[101][100001]; // dp[n][k] n번째 제품까지 활용 가능, 무게가 k 일때 가치의 최대값
// DP 인것은 확인했으나 접근 방법을 생각하지 못했다. 무게, 가치에 따라 dp를 세우는 것이 아닌
// 얼마나 많은 물건들을 가지고 가치를 따질것인지 생각했어야 했다.
int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &kg);
	for (int i = 1; i <= n; i++)
	{
		int _kg, _v;
		scanf("%d %d", &_kg, &_v);
		W[i] = _kg;
		V[i] = _v;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= kg; j++)
		{
			if (j >= W[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	printf("%d", dp[n][kg]);
}