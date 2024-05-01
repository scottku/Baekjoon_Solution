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
int S, E;
vector<int> v;
int dp[2001][2001];

int DP(int start, int end)
{
	if (end - 1 == start)
	{
		if (v[start] == v[end])
			return dp[start][end] = 1;
		else
			return dp[start][end] = 0;
	}

	if (dp[start][end] != -1)
		return dp[start][end];

	int n = DP(start + 1, end - 1) + (int)(v[start] == v[end]);
	if (n == 2) // 둘 다 true
		return dp[start][end] = 1;
	else
		return dp[start][end] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 2001; i++)
	{
		for (int j = 0; j < 2001; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = -1;
		}
	}

	cin >> N;
	int temp;
	v.push_back(0); // 0번째 자리 채워넣기
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	cin >> M;
	for (int tc = 0; tc < M; tc++)
	{
		cin >> S >> E;
		cout << DP(S, E) << '\n';
	}
}