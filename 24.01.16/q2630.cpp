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

int arr[128][128];
int _white = 0;
int _blue = 0;
// 분할 정복 : 재귀 -> 재귀 내에서 다른 부수적 조건에 따라 재귀를 다시 진행
void findSize(int x, int y, int _size)
{
	int _count = 0;
	for (int i = x; i < x + _size; i++)
	{
		for (int j = y; j < y + _size; j++) // 1의 전체 갯수 파악
		{
			if (arr[i][j] == 1)
				_count++;
		}
	}

	if (_count == _size * _size) // 전부 다 1이면 파랑 +1
	{
		_blue++;
		return;
	}
	if (_count == 0) // 전부 다 0이면 하양 +1
	{
		_white++;
		return;
	}

	// 중간에 듬성듬성 1이 비어있다면, 범위를 줄여서 재귀
	findSize(x, y, _size / 2);
	findSize(x, y + _size / 2, _size / 2);
	findSize(x + _size / 2, y, _size / 2);
	findSize(x + _size / 2, y + _size / 2, _size / 2); // _size/2 == 1 이 될 때, 1칸씩 체크해서 확인하고 마무리 될 것
}


int main(void)
{
	int n;
	scanf("%d", &n);
	memset(arr, 0, sizeof(arr));

	int t;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &t);
			arr[i][j] = t;
		}
	}

	findSize(0, 0, n);

	printf("%d\n", _white);
	printf("%d", _blue);
}