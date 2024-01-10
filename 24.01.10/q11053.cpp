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

	int answer = 1; // 최소 1개는 가능 (1인 수열)
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1; // 배열의 i 번째 숫자 혼자 있어도 길이는 1인 수열 가능
		if (i == 1) continue;
		for (int j = i - 1; j > 0; j--)
		{
			if (_arr[i] > _arr[j])	// 배열 내부 숫자가 작다 = 증가하는 수열을 만들 수 있다
			{									// = 배열의 j 번째 숫자를 포함했을 때 만들 수 있는 가장 긴 배열 + 1 
				dp[i] = max(dp[i], dp[j] + 1);	// vs 배열의 i 번째 숫자를 포함했을 때 만들 수 있는 배열 길이
			}									// 내 앞에 나보다 작은놈이 없다 = i 번째 숫자를 포함해서 만들 수 있는 배열 최대 길이는 자기 자신인 1 뿐이다.
		}
		answer = max(dp[i], answer); // 기존의 가장 높았던 수와 비교하기
	}
	printf("%d", answer/*=dp[n]*/);
}