#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<tuple>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char map[51][51];
int water[51][51];
int d[51][51];
int startx;
int starty;
int destinationx;
int destinationy;
int waterx;
int watery;
queue<pair<int, int>> q;

void water_bfs() {
    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (map[nx][ny] == '.' && water[nx][ny] == -1) {
                water[nx][ny] = water[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void bfs() {
    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (d[nx][ny] != -1) continue;
            if (map[nx][ny] == 'X') continue;
            if (d[x][y] + 1 >= water[nx][ny] && water[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    memset(water, -1, sizeof(water));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '*') {
                q.push(make_pair(i, j));
                water[i][j] = 0;
            }
            if (map[i][j] == 'S') {
                startx = i;
                starty = j;
                d[i][j] = 0;
            }
            if (map[i][j] == 'D') {
                destinationx = i;
                destinationy = j;
            }
        }
    }
    water_bfs();
    q.push(make_pair(startx, starty));
    bfs();
    if (d[destinationx][destinationy] == -1) {
        cout << "KAKTUS" << "\n";
    }
    else {
        cout << d[destinationx][destinationy] << "\n";
    }

}