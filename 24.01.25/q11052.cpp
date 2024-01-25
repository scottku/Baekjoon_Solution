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
vector<int> v;
int dp[1001][1001]; // dp[a][b] => 카드 a개를 최대 b개까지 포함해서 살 수 있을 때 최댓값
int _max = 0;

int findMax(int total, int index)  // total = 총 사야하는 카드 갯수, index = 한번에 구매 가능한 카드 수
{
	if (index == 0 || total == 0) // 총 사야할 카드 수가 0개거나, 한번에 구매 가능한 카드 수가 0개면 0을 return
		return 0;

	if (dp[total][index] != 0)
		return dp[total][index];

	// total 개를 한번에 index 만큼씩 구매할 수 있을 때의 최댓값은
	// total 개를 한번에 index - 1 만큼씩 구매할 수 있을 때의 최댓값
	// vs
	// index 만큼 한번 구매 후, 나머지 갯수를 최대 index만큼씩 구매할 수 있을 때의 최댓값
	dp[total][index] = v[index] + findMax(total - index, total - index >= index ? index : total - index);
	dp[total][index] = max(findMax(total, index - 1), dp[total][index]);
	return dp[total][index];
}

int main(void)
{
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	v.push_back(0);

	for (int i = 1; i <= n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp); // i 개씩 살 때의 가격을 순서대로 vector에 위치 시킨다.
	}

	int answer = findMax(n, n);
	printf("%d", answer);
}