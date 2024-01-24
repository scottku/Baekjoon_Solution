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
int arr[100][100];
bool visit[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 }; // �� �� �� ��
int _count = 0;
void BFS(int water_height, int x, int y, bool _first)
{
	if (visit[x][y]) // �̹� �湮�� ��
	{
		if (_first) // ó�� �������� ã�� ���̶��
		{
			if (y + 1 < n)
				BFS(water_height, x, y + 1, true); // BFS�� ���� �������� ���� ��� ã�´�
			else
			{
				if (x + 1 < n)
					BFS(water_height, x + 1, 0, true);
			}
		}
		return; // return ���� ������ �Ʒ� _count++ �ʿ� ��� true ���ڸ� ���� BFS �Լ��� ������
	}
	else
		visit[x][y] = true;

	if (arr[x][y] <= water_height) // �� ���̺��� ���� ���� �������� �� �� ���� �������� �� �� ����.
	{
		if (!_first) // ����� ���� ã�� ���̾��ٸ� ���ư���
			return;

		if (y + 1 < n) // �������� ã�� ���̶�� ��ġ�� �̵����� �ٽ� ����
			BFS(water_height, x, y + 1, true);
		else
		{
			if (x + 1 < n)
				BFS(water_height, x + 1, 0, true);
		}
	}
	else // ó�� �湮�߰�, �� ���̺��ٵ� ���� �����̴�.
	{
		for (int i = 0; i < 4; i++) // �����¿쿡 �����ϸ�, �湮���� ���� ������ ã�� �̵��Ѵ�.
		{
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < n && !visit[a][b]) // �簢�� ���� + �湮 ����
			{
				BFS(water_height, a, b, false);
			}
		}

		if (_first) // �� ó�� �������� �������� ���� �̾����Ƿ� 1���� count�� �߰��Ѵ�, ����� false ������ �߰��ϸ� �ȵ�
		{
			_count++;

			if (y + 1 < n) // ���� ������ �ƴ϶�� ��� BFS ����
				BFS(water_height, x, y + 1, true);
			else
			{
				if (x + 1 < n)
					BFS(water_height, x + 1, 0, true);
			}
		}
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d", &n);
	int _max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			scanf("%d", &temp);
			arr[i][j] = temp;
			if (_max < temp)
				_max = temp;
		}
	}
	// _max => �ִ� ���̰� ���صα� // _max �� �Ʒ��θ� üũ�ϸ� ��
	int result = -1;
	for (int i = 0; i < _max; i++)
	{
		BFS(i, 0, 0, true);
		result = max(result, _count); // �� �ִ� ����
		_count = 0; // �� ���� ����
		memset(visit, false, sizeof(visit)); // �湮 ����
	}
	printf("%d", result);
}