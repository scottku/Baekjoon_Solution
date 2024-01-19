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

using namespace std;

int arr[21][21][21];

int DP_Loop(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
	{
		return DP_Loop(20, 20, 20);
	}

	if (arr[a][b][c] != 0)
		return arr[a][b][c];

	if (a < b && b < c)
	{
		arr[a][b][c] = DP_Loop(a, b, c - 1) + DP_Loop(a, b - 1, c - 1) - DP_Loop(a, b - 1, c);
		return arr[a][b][c];
	}
	arr[a][b][c] = DP_Loop(a - 1, b, c) + DP_Loop(a - 1, b - 1, c) + DP_Loop(a - 1, b, c - 1) - DP_Loop(a - 1, b - 1, c - 1);
	return arr[a][b][c];
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	while (true)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)
			break;
		int answer = DP_Loop(a, b, c);

		printf("w(%d, %d, %d) = %d\n", a, b, c, answer);
	}
}