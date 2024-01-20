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

int arr[500][500];
int as[257];
int n, m, b;
int answer_max = 64250001 * 2;
int answer_start = 0;

void findBlockHeight(int _start, int _max, int height, int width, int block)
{
	if (_start > _max)
		return;

	int _up = 0;
	int _down = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (_start > arr[i][j])
				_up += _start - arr[i][j]; // �׾ƾ��� ��� ����
			else
				_down += -_start + arr[i][j]; // ������ ��� ����
		}
	}
	if (_up > _down + block) // �׾ƾ��� ��� ������ ������ �ִ� + ���� ���� ��� �������� ���ٸ�
	{
		as[_start] = -1;
	}
	else
	{
		as[_start] = _down * 2 + _up; // �״� �۾��� 1��, �ĳ��� �۾��� 2��
		if (answer_max > as[_start]) // �ĳ��� �۾��ð��� ª�ٸ�
		{
			answer_max = as[_start];
			answer_start = _start;
		}
		else if (answer_max == as[_start])
		{
			if (answer_start < _start)
			{
				answer_max = as[_start];
				answer_start = _start;
			}
		}
		else
		{

		}
	}
	findBlockHeight(_start + 1, _max, height, width, block);
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(as, 0, sizeof(as));
	scanf("%d %d %d", &n, &m, &b);
	int temp;
	int _min = 257;
	int _max = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (temp < _min)
				_min = temp;
			if (temp > _max)
				_max = temp;
		}
	}

	findBlockHeight(_min, _max, n, m, b);
	printf("%d %d", answer_max, answer_start);
}