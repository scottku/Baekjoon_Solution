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

int n, k;
int dp[10001]; // dp[a] = b : 가치 a를 갖는 경우의 수는 b 이다
vector<int> v_coin;

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v_coin.push_back(temp);
	}
	sort(v_coin.begin(), v_coin.end(), less<int>());
	dp[0] = 1; //  0원을 만드는 것 = 아무것도 선택하지 않기 = 1가지
	for (int i = 0; i < n; i++)
	{
		for (int j = v_coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - v_coin[i]];
		}
	}

	printf("%d", dp[k]);
}