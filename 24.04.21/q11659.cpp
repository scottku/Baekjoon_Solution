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

int N, M;
int arr[100001];
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int temp;
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		arr[i] = temp;
		dp[i] = dp[i - 1] + temp;
	}

	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		cout << dp[to] - dp[from - 1] << '\n';
	}
}