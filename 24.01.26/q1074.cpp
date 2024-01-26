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

int N, r, c;
int _count = 0;

void findLocation(int temp, int _r, int _c)
{
	if (_r >= temp / 2 && _c >= temp / 2) // 4��и�
	{ // 512 
		_count += temp / 2 * temp / 2 * 3; // 1 2 3 ��и��� ���� ���� �̸� ���
		if (temp / 2 == 1)
			return;
		findLocation(temp / 2, _r - temp / 2, _c - temp / 2);
	}
	else if (_r >= temp / 2 && _c < temp / 2) // 3��и�
	{
		_count += temp / 2 * temp / 2 * 2;
		if (temp / 2 == 1)
			return;
		findLocation(temp / 2, _r - temp / 2, _c);
	}
	else if (_r < temp / 2 && _c >= temp / 2) // 1��и�
	{
		_count += temp / 2 * temp / 2;
		if (temp / 2 == 1)
			return;
		findLocation(temp / 2, _r, _c - temp / 2);
	}
	else // 2��и�
	{
		if (temp / 2 == 1)
			return;
		findLocation(temp / 2, _r, _c);
	}
}

int main(void)
{

	scanf("%d %d %d", &N, &r, &c);

	int temp = pow(2, N);
	findLocation(temp, r, c); // 2^10 �Է�
	printf("%d", _count);
}