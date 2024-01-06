#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <memory.h>

using namespace std;

// 2x3 직사각형을 채우는 방법 = 2x1 직사각형을 채우는 방법(가장 오른쪽에 2x1 2개를 채워넣으면 2x3 직사각형)
//								+ 2x2 직사각형을 채우는 방법(가장 오른쪽에 1x2 1개를 채워넣으면 2x3 직사각형)

int dp[1001];

int count(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return dp[1];
	if (n == 2)
		return dp[2];
	if (dp[n] != -1)
		return dp[n];

	dp[n] = (count(n - 1) + count(n - 2)) % 10007;
	return dp[n];
}

int main(void)
{
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;

	int result = 0;
	result = count(n);
	printf("%d", result);
}