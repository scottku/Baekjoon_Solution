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
#include <climits>

// 시간 체크용
//#include <time.h>
// clock_t start, end;
// start = clock();
// 체크해보고싶은 함수
// end = clock();
// double result = end - start;
// printf("%f", result / CLOCKS_PER_SEC);

using namespace std;
#define ARR_SIZE  21
int R, C;
char arr[ARR_SIZE][ARR_SIZE];
int answer = 0;
bool visit[26]; // 알파벳 갯수는 26개, 'A' => 65
int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };

void DFS(int x, int y, int _count)
{
	int n_alphabet = (int)arr[x][y];
	visit[n_alphabet - (int)'A'] = true;

	if (_count > answer)
		answer = _count;

	for (int i = 0; i < 4; i++)
	{
		int _dx = x + dx[i];
		int _dy = y + dy[i];
		if (_dx > 0 && _dx <= R && _dy > 0 && _dy <= C)
		{
			if (!visit[(int)arr[_dx][_dy] - (int)'A']) // 한번도 방문하지 않은 알파벳
				DFS(_dx, _dy, _count + 1);
		}
	}

	visit[n_alphabet - (int)'A'] = false; // 뒤로 돌아갈때는 기존에 방문했던 알파벳을 방문하지 않은 것으로 되돌려놔야 함.
}

int main(void)
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		for (int j = 0; j < ARR_SIZE; j++)
		{
			arr[i][j] = ' ';
		}
	}
	memset(visit, false, sizeof(visit));

	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			char c;
			scanf("%c", &c);
			if ((int)c == (int)'\n' || (int)c == (int)' ')
			{
				j--;
				continue;
			}
			else
			{
				arr[i][j] = c;
			}
		}
	}

	DFS(1, 1, 1); // (1,1) 위치에서 시작, 현재 카운트는 1;

	printf("%d", answer);
}