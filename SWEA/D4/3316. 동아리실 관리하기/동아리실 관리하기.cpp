#include <iostream>
#include<vector>
#include <cstring>

using namespace std;

long long grid[10001][16];
long long result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < 16; j++) {
				grid[i][j] = 0;
			}
		}
		result = 0;

		for (int day = 0; day < s.size(); day++) {
			int admin = 1 << (s[day] - 'A');

			for (int i = 0; i < 16; i++) {
				if (day == 0) {
					if ((i & admin) != 0 && (1 & i) != 0) {
						grid[day][i] = 1;
					}
				}
				else {
					if (grid[day - 1][i] != 0) {
						for (int j = 1; j <= 15; j++) {
							if ((j & i) != 0 && (admin & j) != 0) {
								grid[day][j] += grid[day - 1][i];
								grid[day][j] %= 1000000007;
							}
						}
					}
				}
			}
		}

		for (int i = 1; i < 16; i++) {
			result += grid[s.size() - 1][i];
		}

		result %= 1000000007;

		cout << "#" << tc << " " << result << '\n';
	}
}