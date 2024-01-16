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
// ���� ���� : ��� -> ��� ������ �ٸ� �μ��� ���ǿ� ���� ��͸� �ٽ� ����
void findSize(int x, int y, int _size)
{
	int _count = 0;
	for (int i = x; i < x + _size; i++)
	{
		for (int j = y; j < y + _size; j++) // 1�� ��ü ���� �ľ�
		{
			if (arr[i][j] == 1)
				_count++;
		}
	}

	if (_count == _size * _size) // ���� �� 1�̸� �Ķ� +1
	{
		_blue++;
		return;
	}
	if (_count == 0) // ���� �� 0�̸� �Ͼ� +1
	{
		_white++;
		return;
	}

	// �߰��� �뼺�뼺 1�� ����ִٸ�, ������ �ٿ��� ���
	findSize(x, y, _size / 2);
	findSize(x, y + _size / 2, _size / 2);
	findSize(x + _size / 2, y, _size / 2);
	findSize(x + _size / 2, y + _size / 2, _size / 2); // _size/2 == 1 �� �� ��, 1ĭ�� üũ�ؼ� Ȯ���ϰ� ������ �� ��
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