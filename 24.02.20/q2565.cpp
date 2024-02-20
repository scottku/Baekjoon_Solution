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

int n;
vector<pair<int, int>> v;
int dp[101];

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int _s, _e;
		scanf("%d %d", &_s, &_e);
		v.push_back({ _s, _e });
	}
	sort(v.begin(), v.end(), less<pair<int, int>>());
	dp[1] = 1;
	int _max = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1; // 자기 혼자만이라면 1개
		for (int j = 1; j < i; j++)
		{
			if (v[i - 1].second > v[j - 1].second) // 오름차순이라면
				dp[i] = max(dp[i], dp[j] + 1);
		}
		_max = max(dp[i], _max);
	} // n 번쨰일 때 최대 오름차순 배열 길이가 나옴
	printf("%d", n - _max);
}