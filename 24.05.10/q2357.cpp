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
#include <time.h>

using namespace std;

int N, M;

int arr[100001];
vector<int> min_tree, max_tree;

void init(int node, int start, int end) // 1번 노드 = root 노드
{
	if (start == end)
	{
		min_tree[node] = max_tree[node] = arr[start];
	}
	else
	{
		init(node * 2, start, (start + end) / 2); // 1번 노드의 다음은 2번 3번, 2번 노드의 다음은 4번 5번, 2n 과 2n+1 로 구성됨
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
		max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
	}
}

pair<int, int> findMinMax(int node, int start, int end, int left, int right)
{
	if (end < left || start > right)
		return { INT_MAX, 0 }; // 범위 안에 포함이 안되는 녀석들은 계산에 영향을 주지 않도록 값을 임의로 넘겨줌
	else if (left <= start && end <= right) // 범위 안에 들어오는 녀석들이라면
		return { min_tree[node], max_tree[node] }; // 그 범위 안에서의 최대 최솟값 뱉어내기
	else // 범위의 일부가 겹치는 녀석들
	{
		pair<int, int> l, r; // 절반씩 쪼개지면서 범위 내부를 찾아 들어간다
		l = findMinMax(node * 2, start, (start + end) / 2, left, right);
		r = findMinMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right); // 재귀를 돌다보면 범위안의 녀석들이 전부 찾아지게 될 것
		return { min(l.first, r.first), max(l.second, r.second) };
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int h = (int)ceil(log2(N));
	min_tree = vector<int>(1 << (h + 1));
	max_tree = vector<int>(1 << (h + 1));
	// 비트 연산자, 1은 2진법으로 1, 옆으로 한칸 옮겨서 10 이 되면 2, 옆으로 한칸 옮겨서 100 이 되면 4
	// 결국은 2의 배수를 나타냄

	int temp;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}

	init(1, 1, N); // 1번째 노드(root)에서 시작, 범위는 1~N 까지에서의 최대 최솟값
	int left, right;
	pair<int, int> answer;
	for (int tc = 0; tc < M; tc++)
	{
		cin >> left >> right;
		answer = findMinMax(1, 1, N, left, right);
		cout << answer.first << ' ' << answer.second << '\n';
	}
}