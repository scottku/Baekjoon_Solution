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
int dp[101][10];

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);

	if (n == 1)
	{
		printf("%d", 9);
		return 0;
	}

	dp[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	int count = 2;
	while (count <= n)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i - 1 >= 0 && i + 1 < 10) // 0 Ȥ�� 9�� �ƴϸ� ���ʿ��� ������ �߰��ȴ�.
			{
				dp[count][i] = dp[count - 1][i - 1] + dp[count - 1][i + 1];
				dp[count][i] %= 1000000000;
			}
			else if (i - 1 < 0) // i�� 0�̶��
			{
				dp[count][i] = dp[count - 1][i + 1]; // 1���� 0���� �������� ģ���ۿ� ������ ����.
				dp[count][i] %= 1000000000;
			}
			else // i�� 9���
			{
				dp[count][i] = dp[count - 1][i - 1]; // 8���� 9���� �ö���� ģ���ۿ� ������ ����.
				dp[count][i] %= 1000000000;
			}
		}
		count++;
	}
	int answer = 0;
	for (int i = 0; i < 10; i++)
	{
		answer += dp[n][i];
		answer %= 1000000000;
	}
	printf("%d", answer);
}