#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Point {
    int y, x;
};

struct Grid {
    bool cango = false;

    queue<Point> q;
};

Grid grid[101][101];
int visited[101][101], dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
int N, M, result;
vector<Point> v[101][101];

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        v[a][b].push_back({ c, d });
    }

    grid[1][1].cango = true;
    vector<Point> vv;
    vv.push_back({1, 1});
    result++;
    bool ischeck = false;
    visited[1][1] = 1;

    for(int i = 0; i < vv.size(); i++) {
        Point now = vv[i];

        for (int j = 0; j < v[now.y][now.x].size(); j++) {
            Point next = v[now.y][now.x][j];
            if (!grid[next.y][next.x].cango) {
                grid[next.y][next.x].cango = true;
                ischeck = false;
                result++;
                i = -1;
            }
        }

        for (int i = 0; i < 4; i++) {
            Point next = { now.y + dy[i], now.x + dx[i] };
            if (now.y < 1 || now.x < 1 || now.y > N || now.x > N) continue;
            if (visited[next.y][next.x] == 0 && grid[next.y][next.x].cango) {
                vv.push_back(next);
                visited[next.y][next.x] = 1;
            }
        }

        if (i == vv.size() - 1 && ischeck) break;
        if (i == vv.size() - 1) ischeck = true;
    }

    cout << result;

    return 0;
}