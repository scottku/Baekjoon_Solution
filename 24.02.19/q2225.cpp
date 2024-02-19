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

int n, k;
int dp[201][201]; // dp[n][k] => 숫자 n을 k개의 숫자로 만들 수 있을 때의 경우의 수

int findCases(int num, int k)
{
	if (dp[num][k] != -1)
		return dp[num][k];
	else
	{
		dp[num][k] = 0;
		for (int i = 0; i <= num; i++)
		{
			dp[num][k] += findCases(i, k - 1);
			dp[num][k] %= 1000000000;
		}
		return dp[num][k];
	}
}

int main(void)
{
	for (int i = 0; i < 202; i++)
	{
		for (int j = 0; j < 202; j++)
		{
			dp[i][j] = -1;
		}
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++)
	{
		dp[i][1] = 1; // i 라는 숫자를 1개의 수로 만들 수 있는 경우의 수는 단 1개
	}
	int answer = findCases(n, k);
	printf("%d", answer);
}