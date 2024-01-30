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

int h, w, k;
bool arr[101][101];
bool visit[101][101];
vector<int> v;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 }; // �����¿�
int _count = 0;
int _area = 0;

void findArea(int x, int y, bool _start)
{
	if (x >= w) // ���� ���̸�
		return;

	if (_start) // �� ó�� ���� ã�� ���� ������ ���ϴ� ��Ȳ
	{
		if (visit[x][y] || arr[x][y]) // �湮�߰ų�, �簢���� �׷��� �����̶��
		{
			if (y + 1 >= h)
				findArea(x + 1, 0, true);
			else
				findArea(x, y + 1, true);
			return;
		}
		else // �湮���� �ʾҰ�, ������ ������ �����̶��
		{
			_count++; // ���� ����
			_area++;
			visit[x][y] = true;
			for (int i = 0; i < 4; i++) // �ش� ������ �������� Ž�� ����
			{
				int x_dx = x + dx[i];
				int y_dy = y + dy[i];
				if (x_dx >= 0 && x_dx < w && y_dy >= 0 && y_dy < h && !visit[x_dx][y_dy] && !arr[x_dx][y_dy]) // ���� ���̸� �湮�� ���� ���� �̵� ������ ���̴�
				{
					visit[x_dx][y_dy] = true;
					_area++;
					findArea(x_dx, y_dy, false);
				}
			}
			// �� �ϳ� Ž�� �Ϸ�
			v.push_back(_area);
			_area = 0; // �� ũ�� ���� �� �ʱ�ȭ

			// �ٽ� ���� ���۵Ǵ� ���� ã�� ����
			if (y + 1 >= h)
				findArea(x + 1, 0, true);
			else
				findArea(x, y + 1, true);
		}
	}
	else // ó�� ���� ����� �������� ã�� ��
	{
		// �湮���� �ʾҰ� �̵��� �����ϸ� ���� ���� ���� �������� �ԷµǾ����Ƿ� ���� ����ó������ �ʿ� ����.
		for (int i = 0; i < 4; i++) // �ش� ������ �������� Ž�� ����
		{
			int x_dx = x + dx[i];
			int y_dy = y + dy[i];
			if (x_dx >= 0 && x_dx < w && y_dy >= 0 && y_dy < h && !visit[x_dx][y_dy] && !arr[x_dx][y_dy]) // ���� ���̸� �湮�� ���� ���� �̵� ������ ���̴�
			{
				visit[x_dx][y_dy] = true;
				_area++;
				findArea(x_dx, y_dy, false);
			}
		}
	}
}

int main(void)
{
	memset(arr, false, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d %d", &h, &w, &k); // h = y, w = x
	for (int tc = 0; tc < k; tc++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
			{
				arr[i][j] = true;
			}
		}
	}

	findArea(0, 0, true);

	sort(v.begin(), v.end(), less<int>());

	printf("%d\n", _count);
	for (int i = 0; i < _count; i++)
	{
		printf("%d ", v[i]);
	}
}