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
int arr[10000];
int dp[10000];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		arr[i] = temp; //n-1번째까지 찼을 것
	}
	// 결국 더해서 max가 될려면 중간에 2번, 3번 건너뛰고 이런 짓은 굳이 고려하지 않는다.
	dp[0] = 0;
	dp[1] = arr[0];
	dp[2] = arr[0] + arr[1]; // 2번째 까지는 둘다 더하는게 최대
	if (n == 1)
		printf("%d", dp[1]);
	else if (n == 2)
		printf("%d", dp[2]);
	else
	{
		int c = 3;
		while (c <= n)
		{
			// 맨 마지막 포도주를 먹느냐 안먹느냐
			// 먹지 않는다 => dp[c-1]은 결국 c-1번째까지의 포도주 량의 최대값을 의미하므로 c번째에서 먹지 않으면 결국 최대값은 dp[c] = dp[c-1]
			// 먹는다 => 3잔 연속 먹을 수는 없으니 맨 마지막이 다음과 같이 나와야 한다.
			// xoo oxo xoo xxo 
			// xxo는 당연히 xoo에 비해 작을수밖에 없으니 제외
			// xoo : dp[c-3] 에서 c-1 c 를 더하기
			// oxo : c-1 번째에서 먹지 않았다면 결국 dp[c-2]와 값이 같다 : dp[c-2]에서 c를 더하기
			// oox : c번째에서 먹지 않았다면 위와 같이 dp[c-1]과 같다.
			dp[c] = max(dp[c - 3] + arr[c - 2] + arr[c - 1], dp[c - 2] + arr[c - 1]);
			dp[c] = max(dp[c], dp[c - 1]);
			c++;
		}
		printf("%d", dp[n]);
	}
}