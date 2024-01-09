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

	if (col == 1) // 높이가 1이면 못움직임
		printf("%d", 1);
	else if (col == 2) // 높이가 2칸이면 오른쪽으로 2칸씩만 이동 가능
	{
		if (wid >= 7)
			printf("%d", 4);
		else
			printf("%d", wid % 2 != 0 ? wid / 2 + 1 : wid / 2);
	}
	else // 높이가 3칸 이상이면 모든 이동 사용 가능 
	{
		if (wid <= 4)
		{
			printf("%d", wid); // 오른쪽으로 가는 1칸씩만 사용해서 3번 움직일려면 칸이 4 이하
		}
		else if (wid > 4 && wid < 7)
			printf("%d", 4); // 1칸씩 4번 이상 움직일 수 있지만 4번 이상이면 모든 이동을 써야하므로 제한되는 위치
		else
		{
			printf("%d", wid - 2);
		}
	}
}