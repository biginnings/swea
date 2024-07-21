#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>

using namespace std;

struct Node {
	int num;
	int cnt;
	int parent;
	Node* next[2];
};

Node* grid[10001];
int V, E, target1, target2, T;
vector<int> result(2);

void init() {
	for (int i = 1; i < 10001; i++) {
		grid[i] = new Node{ i, 0, i, nullptr, nullptr };
	}

	result = vector<int>(2);
}

void insert_num(int p_n, int c_n) {
	grid[c_n]->parent = p_n;
	grid[p_n]->next[grid[p_n]->cnt] = grid[c_n];
	grid[p_n]->cnt++;
}

void solve() {
	map<int, int> um;

	um[target1] = 1;
	um[target2] = 1;

	Node* now = grid[target1];
	while (1) {
		if (now->num == now->parent) {
			break;
		}

		if (um.find(now->parent) == um.end()) {
			um[now->parent] = 1;
		}
		else {
			um[now->parent]++;
		}

		now = grid[now->parent];
	}

	now = grid[target2];
	while (1) {
		if (now->num == now->parent) {
			break;
		}

		if (um.find(now->parent) == um.end()) {
			um[now->parent] = 1;
		}
		else {
			um[now->parent]++;
			result[0] = now->parent;
			break;
		}

		now = grid[now->parent];
	}
}

void solve2(int num) {
	result[1] += grid[num]->cnt;

	for (int i = 0; i < grid[num]->cnt; i++) {
		solve2(grid[num]->next[i]->num);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> V >> E >> target1 >> target2;

		init();

		int cnt = 0;
		int p_n, c_n;
		for (int i = 0; i < E; i++) {
			cin >> p_n;
			cnt++;

			cin >> c_n;
			cnt++;
			insert_num(p_n, c_n);
		}


		solve();
		solve2(result[0]);
		result[1]++;

		cout << "#" << tc << " " << result[0] << " " << result[1] << "\n";
	}

	return 0;
}
