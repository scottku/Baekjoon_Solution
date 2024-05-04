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

using namespace std;

int N;
int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		dp[i] = 0;
	}
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746; // 1(dp[i-1]) or 00(dp[i-2])
	}
	cout << dp[N];
}