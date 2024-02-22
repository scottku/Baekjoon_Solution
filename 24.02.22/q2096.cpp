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
int arr[100000][3];

vector<int> dp_max = { -1, -1, -1 };
vector<int> dp_min = { INT_MAX, INT_MAX, INT_MAX };

int main(void)
{
	for (int i = 0; i < 100000; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = -1;
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
		}
	}
	dp_max[0] = dp_min[0] = arr[0][0];
	dp_max[1] = dp_min[1] = arr[0][1];
	dp_max[2] = dp_min[2] = arr[0][2];

	for (int i = 1; i < n; i++)
	{
		int max1 = max(dp_max[0], dp_max[1]) + arr[i][0];
		int max2 = max(max(dp_max[0], dp_max[1]), dp_max[2]) + arr[i][1];
		int max3 = max(dp_max[1], dp_max[2]) + arr[i][2];
		int min1 = min(dp_min[0], dp_min[1]) + arr[i][0];
		int min2 = min(min(dp_min[0], dp_min[1]), dp_min[2]) + arr[i][1];
		int min3 = min(dp_min[1], dp_min[2]) + arr[i][2];
		dp_max[0] = max1;
		dp_max[1] = max2;
		dp_max[2] = max3;
		dp_min[0] = min1;
		dp_min[1] = min2;
		dp_min[2] = min3;
	}
	printf("%d %d", max(max(dp_max[0], dp_max[1]), dp_max[2]), min(min(dp_min[0], dp_min[1]), dp_min[2]));
}