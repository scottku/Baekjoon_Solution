#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int _arr[1001];
int dp[1001];

int main(void)
{
	memset(_arr, 0, sizeof(_arr));
	memset(dp, 0, sizeof(dp));

	int n;
	scanf("%d", &n);

	int x;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		_arr[i] = x;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = _arr[i]; // 자기만 포함하는 합
		for (int j = i - 1; j >= 1; j--)
		{
			if (_arr[i] > _arr[j])	// i번째보다 j번째가 작으면 (j번을 포함한 최대 합 + i번째)가 후보
			{
				int temp = dp[j] + _arr[i];
				dp[i] = max(dp[i], temp);
			}
		}
		answer = max(dp[i], answer); // 기존의 가장 높았던 수와 비교하기
	}
	printf("%d", answer);
}