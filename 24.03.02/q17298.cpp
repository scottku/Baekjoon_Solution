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

#define ARR_SIZE 1000000
int n;
vector<int> v;
int arr[ARR_SIZE];

void findNext(int _start, int _comp);

int main()
{	// 예전에 풀었던 전신주가 정보를 받아들이는 것의 반대방향 버전인듯?
	for (int i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = -1;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}

	for (int i = n - 1; i >= 0; i--) // vector의 뒷부분부터 맨 앞까지
	{
		if (i == n - 1) // 오른쪽에 뭐 없음
			arr[i] = -1;
		else
		{
			findNext(i, i + 1);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == -1)
			printf("%d ", -1);
		else
			printf("%d ", v[arr[i]]);
	}
}

void findNext(int _start, int _comp)
{
	if (_comp == -1)
	{
		arr[_start] = -1;
		return;
	}

	if (v[_start] < v[_comp])
		arr[_start] = _comp;
	else
		findNext(_start, arr[_comp]);
}