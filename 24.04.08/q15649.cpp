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

int n, m;
int arr[10];
bool isUsed[10];

void backtracking(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!isUsed[i]) {
            isUsed[i] = true;
            arr[k] = i;
            backtracking(k + 1);
            isUsed[i] = false;
        }
    }
}

//1<=m<=n<=8
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= n; i++) {
        isUsed[i] = false;
    }
    cin >> n >> m;
    backtracking(0);
    return 0;
}