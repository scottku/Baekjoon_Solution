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
int dp[1001][1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	int len1, len2;
	string answer = "";

	cin >> s1;
	cin >> s2;
	len1 = s1.length();
	len2 = s2.length();
	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
			dp[i][j] = 0;
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int a = len1;
	int b = len2;
	while (a >= 1 && b >= 1)
	{
		if (dp[a][b] > dp[a - 1][b - 1] && dp[a - 1][b - 1] == dp[a - 1][b] && dp[a - 1][b - 1] == dp[a][b - 1])
		{
			answer += s2[b - 1];
			a--;
			b--;
		}
		else if (dp[a][b] == dp[a - 1][b] && dp[a - 1][b] > dp[a][b - 1])
			a--;
		else if (dp[a][b] == dp[a][b - 1] && dp[a][b - 1] > dp[a - 1][b])
			b--;
		else
			b--;
	}

	reverse(answer.begin(), answer.end());
	if (dp[len1][len2] != 0)
		cout << dp[len1][len2] << '\n' << answer;
	else
		cout << "0";
}