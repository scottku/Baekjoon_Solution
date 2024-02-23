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

using namespace std;

int arr[10005];
int i;

void post(int start, int end) {
	if (start >= end) return;

	for (i = start + 1; i < end; i++)
		if (arr[start] < arr[i]) break;

	post(start + 1, i);
	post(i, end);
	printf("%d\n", arr[start]);

	return;
}

int main() {
	int n = 0, x;

	while (scanf("%d", &x) != EOF)
		arr[n++] = x;

	post(0, n);

	return 0;
}