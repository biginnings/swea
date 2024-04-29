#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int grid[20][20], visited[20][20];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
int N, T, M, max_cost, result =1, cost, house_cnt;

struct Point {
	int y, x;
};

void init() {
	result = 1;
	house_cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

queue<Point> startq;
queue<Point> endq;
void bfs(int K) {
	int main_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			startq.push({ i, j });
			endq.push({ i, j });
			visited[i][j] = 1;
			if (grid[i][j] == 1) cnt++;

			while (!startq.empty()) {
				Point now = startq.front();
				startq.pop();
				endq.push(now);

				for (int z = 0; z < 4; z++) {
					Point next = { now.y + dy[z], now.x + dx[z] };

					if (visited[next.y][next.x] == 1 || next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) {
						continue;
					}
					if (abs(next.y - i) + abs(next.x - j) >= K) continue;

					startq.push(next);
					visited[next.y][next.x] = 1;
					if (grid[next.y][next.x] == 1) cnt++;
				}
			}

			while (!endq.empty()) {
				Point now = endq.front();
				endq.pop();

				visited[now.y][now.x] = 0;
			}

			if (cnt * M >= cost) {
				result = result >= cnt ? result : cnt;
				main_cnt = main_cnt >= cnt ? main_cnt : cnt;
			}
		}
	}

	//if (main_cnt == 0) {
	//	return -1;
	//}
	//else {
	//	return 1;
	//}
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		init();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 1) house_cnt++;
			}
		}

		int K = 2;
		cost = K * K + (K - 1) * (K - 1);
		max_cost = house_cnt * M;
		while (cost <= max_cost) {
			//if(bfs(K) < 0) break;
            bfs(K);
			K++;
			cost = K * K + (K - 1) * (K - 1);
		}

		cout << "#" << tc << " " << result << "\n";
	}


	return 0;
}