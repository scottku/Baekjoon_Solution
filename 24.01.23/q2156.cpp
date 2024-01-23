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
int arr[10000];
int dp[10000];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		arr[i] = temp; //n-1��°���� á�� ��
	}
	// �ᱹ ���ؼ� max�� �ɷ��� �߰��� 2��, 3�� �ǳʶٰ� �̷� ���� ���� ������� �ʴ´�.
	dp[0] = 0;
	dp[1] = arr[0];
	dp[2] = arr[0] + arr[1]; // 2��° ������ �Ѵ� ���ϴ°� �ִ�
	if (n == 1)
		printf("%d", dp[1]);
	else if (n == 2)
		printf("%d", dp[2]);
	else
	{
		int c = 3;
		while (c <= n)
		{
			// �� ������ �����ָ� �Դ��� �ȸԴ���
			// ���� �ʴ´� => dp[c-1]�� �ᱹ c-1��°������ ������ ���� �ִ밪�� �ǹ��ϹǷ� c��°���� ���� ������ �ᱹ �ִ밪�� dp[c] = dp[c-1]
			// �Դ´� => 3�� ���� ���� ���� ������ �� �������� ������ ���� ���;� �Ѵ�.
			// xoo oxo xoo xxo 
			// xxo�� �翬�� xoo�� ���� �������ۿ� ������ ����
			// xoo : dp[c-3] ���� c-1 c �� ���ϱ�
			// oxo : c-1 ��°���� ���� �ʾҴٸ� �ᱹ dp[c-2]�� ���� ���� : dp[c-2]���� c�� ���ϱ�
			// oox : c��°���� ���� �ʾҴٸ� ���� ���� dp[c-1]�� ����.
			dp[c] = max(dp[c - 3] + arr[c - 2] + arr[c - 1], dp[c - 2] + arr[c - 1]);
			dp[c] = max(dp[c], dp[c - 1]);
			c++;
		}
		printf("%d", dp[n]);
	}
}