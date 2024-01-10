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
		dp[i] = _arr[i]; // �ڱ⸸ �����ϴ� ��
		for (int j = i - 1; j >= 1; j--)
		{
			if (_arr[i] > _arr[j])	// i��°���� j��°�� ������ (j���� ������ �ִ� �� + i��°)�� �ĺ�
			{
				int temp = dp[j] + _arr[i];
				dp[i] = max(dp[i], temp);
			}
		}
		answer = max(dp[i], answer); // ������ ���� ���Ҵ� ���� ���ϱ�
	}
	printf("%d", answer);
}