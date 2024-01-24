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
char arr[26][3];
char sec[26][3];

void firstMethod(char index)
{
	printf("%c", index);
	int i = 0;
	while (true)
	{
		if ((int)arr[i][0] == (int)index)
			break;
		i++;
	}
	char l = arr[i][1];
	char r = arr[i][2];
	if ((int)l != (int)' ')
		firstMethod(l);
	if ((int)r != (int)' ')
		firstMethod(r);
}

void secondMethod(char index)
{
	int i = 0;
	while (true)
	{
		if ((int)arr[i][0] == (int)index)
			break;
		i++;
	}
	char l = arr[i][1];
	char r = arr[i][2];

	if ((int)l == (int)' ' && (int)r == (int)' ')
	{
		printf("%c", index);
		return;
	}

	if ((int)l != (int)' ')
	{
		secondMethod(l);
	}

	printf("%c", index);

	if ((int)r != (int)' ')
	{
		secondMethod(r);
	}
}

void thirdMethod(char index)
{
	int i = 0;
	while (true)
	{
		if ((int)arr[i][0] == (int)index)
			break;
		i++;
	}

	char l = arr[i][1];
	char r = arr[i][2];

	if ((int)l == (int)' ' && (int)r == (int)' ')
	{
		printf("%c", index);
		return;
	}

	if ((int)l != (int)' ')
	{
		thirdMethod(l);
	}

	if ((int)r != (int)' ')
	{
		thirdMethod(r);
	}

	printf("%c", index);
}

int main(void)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = ' ';
			sec[i][j] = ' ';
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char parent, child1, child2;
		scanf("\n%c %c %c", &parent, &child1, &child2);
		arr[i][0] = parent;
		if ((int)child1 != (int)'.')
			arr[i][1] = child1;
		if ((int)child2 != (int)'.')
			arr[i][2] = child2;
	}

	firstMethod('A');
	printf("\n");
	secondMethod('A');
	printf("\n");
	thirdMethod('A');
}