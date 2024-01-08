#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>

using namespace std;

int arrDay[16];
int arrPay[16];
int dp[16];
int main(void)
{
	memset(arrDay, 0, sizeof(arrDay));
	memset(arrPay, 0, sizeof(arrPay));
	memset(dp, 0, sizeof(dp));

	int n_day;
	scanf("%d", &n_day);
	for (int i = 1; i <= n_day; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arrDay[i] = a;
		arrPay[i] = b;
	}

	int count = 0;
	for (int i = n_day; i > 0; i--)
	{
		count++;
		if (arrDay[i] - count > 0) // ������ ��� ���ϴ� ��
		{
			if (i == n_day)
			{
				dp[i] = 0;
				continue;
			}

			dp[i] = dp[i + 1]; // �׳� �״�� ������ ��������
		}
		else // ��� ��ü�� ������ ���̶��
		{ // �׳� ����ϰ� �� ���� ��� ������ ���� ���� ���� �ݾ� vs �׳� �� ���� ��㰡���� ���� ���� �ݾ�
			dp[i] = arrPay[i] + dp[i + arrDay[i]] > dp[i + 1] ? arrPay[i] + dp[i + arrDay[i]] : dp[i + 1];
		}
	}

	printf("%d", dp[1]);
}