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



int main(void)
{
	int col, wid;
	scanf("%d %d", &col, &wid);
	if (wid == 1)
	{
		printf("%d", 1);
		return 0;
	}

	if (col == 1) // ���̰� 1�̸� ��������
		printf("%d", 1);
	else if (col == 2) // ���̰� 2ĭ�̸� ���������� 2ĭ���� �̵� ����
	{
		if (wid >= 7)
			printf("%d", 4);
		else
			printf("%d", wid % 2 != 0 ? wid / 2 + 1 : wid / 2);
	}
	else // ���̰� 3ĭ �̻��̸� ��� �̵� ��� ���� 
	{
		if (wid <= 4)
		{
			printf("%d", wid); // ���������� ���� 1ĭ���� ����ؼ� 3�� �����Ϸ��� ĭ�� 4 ����
		}
		else if (wid > 4 && wid < 7)
			printf("%d", 4); // 1ĭ�� 4�� �̻� ������ �� ������ 4�� �̻��̸� ��� �̵��� ����ϹǷ� ���ѵǴ� ��ġ
		else
		{
			printf("%d", wid - 2);
		}
	}
}