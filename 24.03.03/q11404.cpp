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

int city, bus;
int arr[101][101];
#define INF 987654321

int main()
{
	scanf("%d", &city);
	scanf("%d", &bus);

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= city; i++)
		arr[i][i] = 0;


	for (int i = 0; i < bus; i++)
	{
		int from, to, value;
		scanf("%d %d %d", &from, &to, &value);
		if (value < arr[from][to])
			arr[from][to] = value;
	}

	for (int k = 1; k <= city; k++)
	{
		for (int i = 1; i <= city; i++)
		{
			for (int j = 1; j <= city; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= city; i++)
	{
		for (int j = 1; j <= city; j++)
		{
			if (arr[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}