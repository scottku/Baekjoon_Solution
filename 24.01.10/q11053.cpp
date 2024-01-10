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

	int answer = 1; // �ּ� 1���� ���� (1�� ����)
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1; // �迭�� i ��° ���� ȥ�� �־ ���̴� 1�� ���� ����
		if (i == 1) continue;
		for (int j = i - 1; j > 0; j--)
		{
			if (_arr[i] > _arr[j])	// �迭 ���� ���ڰ� �۴� = �����ϴ� ������ ���� �� �ִ�
			{									// = �迭�� j ��° ���ڸ� �������� �� ���� �� �ִ� ���� �� �迭 + 1 
				dp[i] = max(dp[i], dp[j] + 1);	// vs �迭�� i ��° ���ڸ� �������� �� ���� �� �ִ� �迭 ����
			}									// �� �տ� ������ �������� ���� = i ��° ���ڸ� �����ؼ� ���� �� �ִ� �迭 �ִ� ���̴� �ڱ� �ڽ��� 1 ���̴�.
		}
		answer = max(dp[i], answer); // ������ ���� ���Ҵ� ���� ���ϱ�
	}
	printf("%d", answer/*=dp[n]*/);
}