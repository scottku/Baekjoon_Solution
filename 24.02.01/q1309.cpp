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

int n;
int dp[100001][3]; //dp[a][b] a번째 행에 b 방법으로 놓을 수 있는 경우의 수, 0 : 사자 없음, 1: 왼쪽에 사자, 2: 오른쪽에 사자
int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1; // 

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}

	printf("%d", (dp[n][0] + dp[n][1] + dp[n][2]) % 9901);
}