#include<iostream>
#include<queue>

using namespace std;

int grid[64][64];
int dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
int q, sum2, l, n;
queue<int> que;
queue<pair<int, int>> que2;

int main() {
	int t_n;
	cin >> t_n >> q;

	n = 1 << t_n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> l;

		int rotate_n = 1 << l;
		int t = n / rotate_n;

		for (int j = 0; j < t * t; j++) {
			int st_x = (j % t) * rotate_n;
			int st_y = (j / t) * rotate_n;
			int ed_x = st_x + rotate_n - 1;
			int ed_y = st_y + rotate_n - 1;

			for (int z = st_y; z <= ed_y; z++) {
				for (int k = st_x; k <= ed_x; k++) {
					que.push(grid[z][k]);
				}
			}

			for (int z = ed_x; z >= st_x; z--) {
				for (int k = st_y; k <= ed_y; k++) {
					grid[k][z] = que.front();
					que.pop();
				}
			}
		}

		for (int z = 0; z < n; z++) {
			for (int k = 0; k < n; k++) {
				if (grid[z][k] == 0) continue;
				int cnt = 0;

				for (int bf = 0; bf < 4; bf++) {
					int ny = z + dy[bf];
					int nx = k + dx[bf];

					if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;

					if (grid[ny][nx] != 0) cnt++;
				}

				if (cnt <= 2) {
					que2.push({ z, k });
				}
			}
		}

		while (!que2.empty()) {
			pair<int, int> now = que2.front();
			que2.pop();
	
			if (grid[now.first][now.second] == 0) continue;
			grid[now.first][now.second]--;
		}
	}

	int visited[64][64];

	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {
			visited[i][j] = 0;
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) continue;
			if (visited[i][j] != 0) continue;
			int temp_max = 0;
			temp_max++;
			sum2 += grid[i][j];
			que2.push({ i, j });
			visited[i][j] = 1;

			while (!que2.empty()) {
				pair<int, int> now = que2.front();
				que2.pop();

				for (int z = 0; z < 4; z++) {
					pair<int, int> next;
					next.first = now.first + dy[z];
					next.second = now.second + dx[z];

					if (next.second < 0 || next.first < 0 || next.second >= n || next.first >= n) continue;
					if (visited[next.first][next.second] != 0) continue;
					if (grid[next.first][next.second] == 0) continue;

					temp_max ++;
					sum2 += grid[next.first][next.second];
					visited[next.first][next.second] = 1;
					que2.push({ next.first, next.second });
				}
			}

			max_cnt = max_cnt >= temp_max ? max_cnt : temp_max;
		}
	}

	cout << sum2 << "\n" << max_cnt;
}