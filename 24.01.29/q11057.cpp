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
int _num[10] = { 0,1,2,3,4,5,6,7,8,9 };
queue<pair<int, int>> q;
int dp[1001][10]; // 1~1000 , 1~9

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);

	if (n == 1)
		printf("%d", 10);
	else
	{
		for (int i = 0; i <= 9; i++) // dp[a][b] = 길이는 a, 맨 뒷자리는 숫자 b
		{
			dp[1][i] = 1;
		}
		// 맨 뒤가 1로 끝났다 -> 그 전에 수도 1로 끝났어야 한다.
		// 맨 뒤가 2로 끝났다 -> 그 전에 수가 1 or 2로 끝났어야 한다.
		// 맨 뒤가 i로 끝났다 -> 그 전에 수가 i 이하였어야 한다.
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (j - 1 < 0)
					dp[i][j] = dp[i - 1][j]; // 끝이 0인 갯수는 1개 고정
				else
					dp[i][j] = (dp[i][j - 1] % 10007 + dp[i - 1][j] % 10007) % 10007;
			}
		}

		int answer = 0;
		for (int i = 0; i <= 9; i++)
		{
			answer += dp[n][i];
			answer %= 10007;
		}

		printf("%d", answer);
	}
}