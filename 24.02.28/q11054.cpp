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

// 시간 체크용
//#include <time.h>
// clock_t start, end;
// start = clock();
// 체크해보고싶은 함수
// end = clock();
// double result = end - start;
// printf("%f", result / CLOCKS_PER_SEC);

using namespace std;

int n;
int arr[1000];
int dp_front[1000];
int dp_back[1000];

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(dp_front, 0, sizeof(dp_front));
	memset(dp_back, 0, sizeof(dp_back));

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}

	// 앞에서부터, 뒤쪽에서부터 점점 증가하는 부분수열의 최대 길이 확인
	dp_front[0] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				dp_front[i] = max(dp_front[i], dp_front[j] + 1);
		}
		if (dp_front[i] == 0) // 앞에 수들 중 제일 작은 수랑 값이 같다
			dp_front[i] = 1;
	}
	dp_back[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
				dp_back[i] = max(dp_back[i], dp_back[j] + 1);
		}
		if (dp_back[i] == 0) // 뒤에 수들 중 제일 작은 수랑 값이 같다
			dp_back[i] = 1;
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer = max(answer, dp_front[i] + dp_back[i] - 1);
	}
	printf("%d", answer);
}