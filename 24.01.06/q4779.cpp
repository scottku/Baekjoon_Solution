#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <memory.h>

using namespace std;

vector<string> dp;

int main(void)
{
	int n;
	dp.push_back("-"); // dp[0] = "-";
	while (scanf("%d", &n) != -1) // EOF 관리
	{
		if (n == 0)
		{
			printf("%s\n", "-");
			continue;
		}

		if (dp.size() > n) // vector 사이즈가 8 이라면 0~7 까지 있을 것, 
		{
			printf("%s\n", dp[n].c_str());
			continue;
		}

		for (int i = 1; i <= n; i++)
		{
			if (dp.size() > i) // 이미 값이 있으면 for문 돌 필요 없음
				continue;
			string temp = "";
			for (int j = 0; j < pow(3, i - 1); j++)
			{
				temp += " ";
			} // 중간 공백부분 제작
			dp.push_back(dp[i - 1] + temp + dp[i - 1]);
		}

		printf("%s\n", dp[n].c_str());
	}
}