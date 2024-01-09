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

int _field[50][50];

int _count = 0;
bool _first = true;

void checkSide(int x, int y, int x_limit, int y_limit)
{
	if (_field[x][y] == 1) // ���߰� �ɾ��� �ִٸ�
	{
		if (_first) // ù ���� 
		{
			_count++;
			_first = false; //(���� ���������� �̾����� ���ߵ��� ������ ���� ++�� �����Ѵ�.)
		}
		_field[x][y] = 0;
		// �ֺ��� ���ߵ��� �ɾ����ִٸ� �ٽ� �ش� �Լ� �����ؼ� ��ó ����� ��� ���ߵ��� üũ
		if (x - 1 >= 0 && _field[x - 1][y] == 1)
		{
			checkSide(x - 1, y, x_limit, y_limit);
		}
		if (x + 1 < x_limit && _field[x + 1][y] == 1)
		{
			checkSide(x + 1, y, x_limit, y_limit);
		}
		if (y - 1 >= 0 && _field[x][y - 1] == 1)
		{
			checkSide(x, y - 1, x_limit, y_limit);
		}
		if (y + 1 < y_limit && _field[x][y + 1] == 1)
		{
			checkSide(x, y + 1, x_limit, y_limit);
		}
	}
}


int main(void)
{
	memset(_field, 0, sizeof(_field));
	int _testCase;
	scanf("%d", &_testCase);

	for (int i = 0; i < _testCase; i++)
	{
		_count = 0;
		int width, height, cabbage;
		scanf("%d %d %d", &width, &height, &cabbage);
		int x, y;
		for (int j = 0; j < cabbage; j++)
		{
			scanf("%d %d", &x, &y);
			_field[x][y] = 1;
		}

		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < height; k++)
			{
				checkSide(j, k, width, height);
				_first = true; // �ٽ� ������ �� ���� �����ֱ� ���� true�� �ʱ�ȭ
			}
		}
		printf("%d\n", _count);
	}
}