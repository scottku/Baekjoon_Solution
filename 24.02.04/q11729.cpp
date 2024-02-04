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

void moveToThree(int start, int mid, int end, int num)
{
	if (num == 1)
		printf("%d %d\n", start, end);
	else
	{
		moveToThree(start, end, mid, num - 1);
		printf("%d %d\n", start, end);
		moveToThree(mid, start, end, num - 1);
	}
}

int main(void)
{
	scanf("%d", &n);
	// n-1개를 2번으로 옮기고 n 번째를 3으로 옮긴 후, 2번에서 3번으로 n-1을 옮기기
	int _count = pow(2, n);
	printf("%d\n", _count - 1);
	moveToThree(1, 2, 3, n);
}