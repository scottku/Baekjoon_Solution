#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int _arr[1000001];
int dp[1000001];
vector<int> v;

void myBinarySearch(int x)
{
	int start = 0; int end = v.size() - 1; int mid;
	int result = 0;
	while (end > start)
	{
		mid = (start + end) / 2;    // start가 0, end가 9, 바뀔예정인 위치가 7 이라 가능
		if (v[mid] >= x)            // mid = 4 는 x 보다 작으므로 4번째 이후부터 체크 -> start = 5
			end = mid;              // start가 5, end가 9면 mid = 7, 7번째 위치는 x보다 크거나 같음
		else                        // start가 5, end가 7이면 mid = 6, 6번째 위치는 x보다 작음
			start = mid + 1;        // 작은 친구는 무시하기 위해 start = 7, end = 7로 잡아 바뀔 위치는 7
		result = end;
	}

	v[result] = x;
}

int main(void)
{
	memset(_arr, 0, sizeof(_arr));
	memset(dp, 0, sizeof(dp));

	int n;
	scanf("%d", &n);

	int x;
	for (int i = 1; i <= n; i++) // 100만개는 2중 for문으로 시간초과
	{
		scanf("%d", &x);
		_arr[i] = x;
	}

	v.push_back(_arr[1]);
	for (int i = 2; i <= n; i++)
	{
		if (v.back() < _arr[i]) // 증가 수열의 마지막보다 현재 위치 숫자가 더 크면
			v.push_back(_arr[i]); // 수열 마지막에 해당 숫자를 추가
		else
			myBinarySearch(_arr[i]); // 현재 위치 숫자가 더 작으면, 해당 숫자보다 작은 수가 나오는 바로 직전 위치를 해당 수로 변경
	}
	// 임의로 수열을 만든 v는 증가 수열 그 자체를 나타내는 것은 아님, v의 size 자체로 수열 길이만 확인 가능
	printf("%d", v.size());
}