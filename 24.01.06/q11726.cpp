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

// 2x3 ���簢���� ä��� ��� = 2x1 ���簢���� ä��� ���(���� �����ʿ� 2x1 2���� ä�������� 2x3 ���簢��)
//								+ 2x2 ���簢���� ä��� ���(���� �����ʿ� 1x2 1���� ä�������� 2x3 ���簢��)

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