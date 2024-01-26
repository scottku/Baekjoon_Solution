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
int _count = 0; // 현재 heap에 들어가 있는 갯수

void push(int data, int position) // 부모 = 더 작은 수
{
	if (position == 1)
	{
		arr[position] = data;
		return;
	}

	if (abs(arr[position / 2]) > abs(data))
	{
		arr[position] = arr[position / 2]; // 부모를 아래로 끌고내려옴
		push(data, position / 2); // 부모 위치에 다시 집어넣어봄
	}
	else if (abs(arr[position / 2]) == abs(data)) // 절댓값이 같다면, 음수인 친구를 부모로 만듬
	{
		if (arr[position / 2] > data) // data가 음수라면 data를 위로
		{
			arr[position] = arr[position / 2]; // 부모를 아래로 끌고내려옴
			push(data, position / 2); // 부모 위치에 다시 집어넣어봄
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
		if (abs(arr[index * 2]) < abs(arr[index * 2 + 1])) // 오른쪽 자식의 절댓값이 왼쪽 자식보다 작다면 오른쪽이 올라가야 함
		{
			if (abs(arr[index]) > abs(arr[index * 2])) // 오른쪽 자식이 더 작은데, 그 자식이 부모보다도 작다면 올려야 함
			{
				if (arr[index * 2] == 0) // 숫자 0이면 자식 없는거라 무시
					break;
				int temp = arr[index];
				arr[index] = arr[index * 2];
				arr[index * 2] = temp;
				index *= 2;
			}
			else if (abs(arr[index]) == abs(arr[index * 2])) // 작은 놈 절댓값이랑 부모 절댓값이 같다면
			{
				if (arr[index] <= arr[index * 2]) // 부모값이 작거나 같으면 유지
					break;
				else
				{
					if (arr[index * 2] == 0) // 숫자 0이면 자식 없는거라 무시
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
		else if (abs(arr[index * 2]) > abs(arr[index * 2 + 1])) // 왼쪽 자식의 절댓값이 오른쪽 자식보다 작다면 왼쪽이 올라가야 함
		{
			if (abs(arr[index]) > abs(arr[index * 2 + 1])) // 왼쪽 자식이 더 작은데, 그 자식이 부모보다도 작다면 위로 올린다.
			{
				if (arr[index * 2 + 1] == 0) // 숫자 0인 자식은 없는거
					break;
				int temp = arr[index];
				arr[index] = arr[index * 2 + 1];
				arr[index * 2 + 1] = temp;
				index = index * 2 + 1;
			}
			else if (abs(arr[index]) == abs(arr[index * 2 + 1])) // 작은 놈 절댓값이랑 부모 절댓값이 같다면
			{
				if (arr[index] <= arr[index * 2 + 1]) // 부모값이 작거나 같으면 유지
					break;
				else
				{
					if (arr[index * 2 + 1] == 0) // 숫자 0이면 자식 없는거라 무시
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
		else // 두 자식의 절댓값이 같다
		{
			if (arr[index * 2] == 0) break; // 물론 두 자식이 0으로 같은거면 무시

			if (arr[index * 2] <= arr[index * 2 + 1]) // 왼쪽이 크기가 더 작거나(음수) 둘이 숫자가 같다면 왼쪽을 올린다.
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
			else // 오른쪽이 크기가 작다면 오른쪽을 올린다
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