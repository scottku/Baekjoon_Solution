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

using namespace std;

int dp[100001];

int main(void)
{
	int n;
	scanf("%d", &n);

	dp[0] = 0;
	dp[1] = 1; // 1
	dp[2] = 2; // 1 + 1
	dp[3] = 3; // 1 + 1 + 1
	for (int i = 4; i <= 100000; i++)
		dp[i] = 100000;

	for (int i = 4; i <= n; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[n]);
}