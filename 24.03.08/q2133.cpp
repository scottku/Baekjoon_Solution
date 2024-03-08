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
#include <climits>
#include <time.h>

using namespace std;

int n;
long long dp[31];

int main(void)
{
	for (int i = 0; i < 31; i++)
	{
		dp[i] = 0;
	}
	scanf("%d", &n);
	dp[2] = 3;
	dp[4] = dp[2] * dp[2] + 2;  // 특이 케이스 2가지 발생 -> 양쪽에 세로 상자 1개씩이 세워져 있는 
								// 케이스 
	for (int i = 6; i <= n; i += 2)
	{
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 2; j -= 2)
		{
			dp[i] += dp[j] * 2; // 특이 케이스인 모양을 끼워넣는게 아니면 기존과 모양이 죄다 중복됨
		}
		dp[i] += 2; // 나누는거 없이 온전히 i 칸으로 타일을 채웠을 때 생기는 특이 케이스 2개
	}
	printf("%lld", dp[n]);
}