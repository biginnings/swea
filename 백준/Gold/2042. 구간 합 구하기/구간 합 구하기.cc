#include<iostream>

using namespace std;

long long grid[1000001];
long long s_t[4000004];
int N, M, K;

long long init(int left, int right, int node) {
	if (left == right) return s_t[node] = grid[left];
	int mid = (left + right) / 2;
	return s_t[node] = init(left, mid, 2 * node) + init(mid + 1, right, 2 * node + 1);
}

long long segment(int left, int right, int t_l, int t_r, int node) {
	if (t_r < left || t_l > right) return 0;
	if (t_l <= left && t_r >= right) return s_t[node];
	int mid = (left + right) / 2;
	return segment(left, mid, t_l, t_r, node * 2) + segment(mid + 1, right, t_l, t_r, node * 2 + 1);
}

void change(int left, int right, int target, long long num, int node) {
	if (target < left || target > right) return;
	s_t[node] += num;
	if (left == right) return;
	int mid = (left + right) / 2;
	change(left, mid, target, num, node * 2);
	change(mid + 1, right, target, num, node * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> grid[i];
	}

	init(1, N, 1);

	long long a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			change(1, N, b, c - grid[b], 1);
			grid[b] = c;
		}
		else {
			cout << segment(1, N, b, c, 1) << "\n";
		}
	}

	return 0;
}