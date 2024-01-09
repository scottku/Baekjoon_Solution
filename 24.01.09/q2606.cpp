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

int computer[101][101];
int damaged[101];
deque<int> virus;

int main(void)
{
	memset(computer, 0, sizeof(computer));
	memset(&damaged, 0, sizeof(damaged));
	damaged[1] = 1;
	virus.push_back(1);

	int num;
	scanf("%d", &num);
	int pair;
	scanf("%d", &pair);
	int x, y;
	for (int i = 0; i < pair; i++)
	{
		scanf("%d %d", &x, &y);
		computer[x][y] = 1;
		computer[y][x] = 1;
	}

	int count = 0;
	while (true)
	{
		if (virus.size() == 0)
			break;
		int temp = virus.front();
		virus.pop_front();
		for (int i = 1; i <= num; i++)
		{
			if (temp == i)
				continue;
			if (computer[temp][i] == 1) // 연결되어 있다면 감염
			{
				// 이미 감염된 상태면 무시
				if (damaged[i] == 1)
					continue;
				// 아니면 갯수 추가 및 연쇄적으로 감염 체크할 배열에 추가
				damaged[i] = 1;
				count++;
				virus.push_back(i);
			}
		}
	}
	printf("%d", count);
}