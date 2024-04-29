#include <queue>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int N, M, C, T;
int grid[10][10], grid_square[10][10], visited[10][10];
int temp, result_a, result;

void init() {
	result = 0;
	result_a = 0;
}

void dfs(int y, int x, int next, int level, int depth, int sum, int square_sum) {
	if (sum > C) return;
	if (level >= depth) {
		temp = temp >= square_sum ? temp : square_sum;
		return;
	}

	for (int i = next; i < M; i++) {
		dfs(y, x, i + 1, level + 1, depth, sum + grid[y][x + i], square_sum + grid_square[y][x + i]);
	}
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> C;
		init();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
				grid_square[i][j] = grid[i][j] * grid[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				for (int b = 1; b <= M; b++) {
					temp = 0;

					dfs(i, j, 0, 0, b, 0, 0);
					result_a = result_a >= temp ? result_a : temp;
				}

				for (int z = i; z < N; z++) {
					if (z == i) {
						for (int k = j + M; k <= N - M; k++) {
							for (int b = 1; b <= M; b++) {
								temp = 0;
								dfs(z, k,0, 0, b, 0, 0);
								result = result >= result_a + temp ? result : result_a + temp;
							}
						}
					}
					else {
						for (int k = 0; k <= N - M; k++) {
							for (int b = 1; b <= M; b++) {
								temp = 0;
								dfs(z, k,0, 0, b, 0, 0);
								result = result >= result_a + temp ? result : result_a + temp;
							}
						}
					}
				}
			}
		}

		cout << "#" << tc << " " << result << "\n";
	}


	return 0;
}