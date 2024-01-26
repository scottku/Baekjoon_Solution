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
int arr[100001];
int _count = 0; // ���� heap�� �� �ִ� ����

void push(int data, int position) // �θ� = �� ���� ��
{
	if (position == 1)
	{
		arr[position] = data;
		return;
	}

	if (abs(arr[position / 2]) > abs(data))
	{
		arr[position] = arr[position / 2]; // �θ� �Ʒ��� ��������
		push(data, position / 2); // �θ� ��ġ�� �ٽ� ����־
	}
	else if (abs(arr[position / 2]) == abs(data)) // ������ ���ٸ�, ������ ģ���� �θ�� ����
	{
		if (arr[position / 2] > data) // data�� ������� data�� ����
		{
			arr[position] = arr[position / 2]; // �θ� �Ʒ��� ��������
			push(data, position / 2); // �θ� ��ġ�� �ٽ� ����־
		}
		else
		{
			arr[position] = data;
			return;
		}
	}
	else
		arr[position] = data;
}

void pop()
{
	if (arr[1] == 0)
		return;

	arr[1] = arr[_count];
	arr[_count] = 0;
	_count--;

	if (_count == 0)
		return;

	int index = 1;
	while (true)
	{
		if (index * 2 > 100000)
			break;
		if (abs(arr[index * 2]) < abs(arr[index * 2 + 1])) // ������ �ڽ��� ������ ���� �ڽĺ��� �۴ٸ� �������� �ö󰡾� ��
		{
			if (abs(arr[index]) > abs(arr[index * 2])) // ������ �ڽ��� �� ������, �� �ڽ��� �θ𺸴ٵ� �۴ٸ� �÷��� ��
			{
				if (arr[index * 2] == 0) // ���� 0�̸� �ڽ� ���°Ŷ� ����
					break;
				int temp = arr[index];
				arr[index] = arr[index * 2];
				arr[index * 2] = temp;
				index *= 2;
			}
			else if (abs(arr[index]) == abs(arr[index * 2])) // ���� �� �����̶� �θ� ������ ���ٸ�
			{
				if (arr[index] <= arr[index * 2]) // �θ��� �۰ų� ������ ����
					break;
				else
				{
					if (arr[index * 2] == 0) // ���� 0�̸� �ڽ� ���°Ŷ� ����
						break;
					int temp = arr[index];
					arr[index] = arr[index * 2];
					arr[index * 2] = temp;
					index *= 2;
				}
			}
			else
				break;
		}
		else if (abs(arr[index * 2]) > abs(arr[index * 2 + 1])) // ���� �ڽ��� ������ ������ �ڽĺ��� �۴ٸ� ������ �ö󰡾� ��
		{
			if (abs(arr[index]) > abs(arr[index * 2 + 1])) // ���� �ڽ��� �� ������, �� �ڽ��� �θ𺸴ٵ� �۴ٸ� ���� �ø���.
			{
				if (arr[index * 2 + 1] == 0) // ���� 0�� �ڽ��� ���°�
					break;
				int temp = arr[index];
				arr[index] = arr[index * 2 + 1];
				arr[index * 2 + 1] = temp;
				index = index * 2 + 1;
			}
			else if (abs(arr[index]) == abs(arr[index * 2 + 1])) // ���� �� �����̶� �θ� ������ ���ٸ�
			{
				if (arr[index] <= arr[index * 2 + 1]) // �θ��� �۰ų� ������ ����
					break;
				else
				{
					if (arr[index * 2 + 1] == 0) // ���� 0�̸� �ڽ� ���°Ŷ� ����
						break;
					int temp = arr[index];
					arr[index] = arr[index * 2 + 1];
					arr[index * 2 + 1] = temp;
					index = index * 2 + 1;
				}
			}
			else
				break;
		}
		else // �� �ڽ��� ������ ����
		{
			if (arr[index * 2] == 0) break; // ���� �� �ڽ��� 0���� �����Ÿ� ����

			if (arr[index * 2] <= arr[index * 2 + 1]) // ������ ũ�Ⱑ �� �۰ų�(����) ���� ���ڰ� ���ٸ� ������ �ø���.
			{
				if (abs(arr[index]) > abs(arr[index * 2]))
				{
					int temp = arr[index];
					arr[index] = arr[index * 2];
					arr[index * 2] = temp;
					index *= 2;
				}
				else if (abs(arr[index]) == abs(arr[index * 2]))
				{
					if (arr[index] <= arr[index * 2])
						break;
					else
					{
						int temp = arr[index];
						arr[index] = arr[index * 2];
						arr[index * 2] = temp;
						index *= 2;
					}
				}
				else
					break;
			}
			else // �������� ũ�Ⱑ �۴ٸ� �������� �ø���
			{
				if (abs(arr[index]) > abs(arr[index * 2 + 1]))
				{
					int temp = arr[index];
					arr[index] = arr[index * 2 + 1];
					arr[index * 2 + 1] = temp;
					index = index * 2 + 1;
				}
				else if (abs(arr[index]) == abs(arr[index * 2 + 1]))
				{
					if (arr[index] <= arr[index * 2 + 1])
						break;
					else
					{
						int temp = arr[index];
						arr[index] = arr[index * 2 + 1];
						arr[index * 2 + 1] = temp;
						index = index * 2 + 1;
					}
				}
				else
					break;
			}
		}
	}
}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);

		if (temp != 0)
		{
			push(temp, _count + 1);
			_count++;
		}
		else
		{
			printf("%d\n", arr[1]);
			pop();
		}
	}
}