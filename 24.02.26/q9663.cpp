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
int arr[16];
int answer = 0;

void DFS(int _row)
{
	for (int i = 1; i <= n; i++)
	{
		arr[_row] = i;
		//for (int j = _row + 1; j <= n; j++)
		//	arr[j] = 0;

		bool b_queen = false;
		for (int j = 1; j < _row; j++)
		{
			if (arr[_row] == arr[j] || _row - j == abs(arr[_row] - arr[j]))
			{
				b_queen = true;
				break;
			}
		}
		if (!b_queen)
		{
			if (_row == n)
			{
				answer++;
				return;
			}
			else
				DFS(_row + 1);
		}
	}
}

int main(void)
{	// BFS 느낌으로 진행해보려고 했지만 메모리가 너무 초과됨
	// 한 행에 1개씩만 들어갈 수 있음 <<
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	DFS(1);
	printf("%d", answer);
}