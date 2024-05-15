#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

struct Point {
    int y, x;
};

struct Grid {
    int y, x, value;

    bool operator<(Grid other) const {
        return value < other.value;
    }
};

int N, M;
int grid[500][500];
long long visited[500][500];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
priority_queue<Grid> pq;

int main() {
    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            pq.push({ i, j, grid[i][j] });
        }
    }

    visited[0][0] = 1;

    while (!pq.empty()) {
        Grid now = pq.top();
        pq.pop();

        if (visited[now.y][now.x] == 0) continue;

        for (int i = 0; i < 4; i++) {
            Grid next = now;
            next.y += dy[i];
            next.x += dx[i];

            if (next.y < 0 || next.x < 0 || next.y >= M || next.x >= N) continue;
            if(grid[next.y][next.x] < grid[now.y][now.x]) visited[next.y][next.x] += visited[now.y][now.x];
        }
    }

    cout << visited[M - 1][N - 1];

    return 0;
}