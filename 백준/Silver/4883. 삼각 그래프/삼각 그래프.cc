#include <iostream>
#include<vector>
#include <cstring>
#include <climits>

using namespace std;

long long dp[100001][3];
int grid[100001][3];
long long result;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc = 1;
	int n;
	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> grid[i][j];
				dp[i][j] = INT_MAX;
			}
		}

		dp[0][1] = grid[0][1];
		dp[0][2] = grid[0][1] + grid[0][2];

		for (int i = 1; i < n; i++) {
			if (i < n) {
				for (int j = 0; j < 3; j++) {
					for (int z = -1; z < 2; z++) {
						if (j + z < 0 || j + z > 2) continue;
						dp[i][j] = dp[i][j] <= grid[i][j] + dp[i - 1][j + z] ? dp[i][j] : grid[i][j] + dp[i - 1][j + z];
					}

					if (j > 0) {
						dp[i][j] = dp[i][j] <= grid[i][j] + dp[i][j - 1] ? dp[i][j] : grid[i][j] + dp[i][j - 1];
					}
				}
			}
			//else {
			//	for (int j = 0; j < 3; j++) {
			//		dp[i][1] = dp[i][1] <= dp[i - 1][j] + grid[i][1] ? dp[i][1] : dp[i - 1][j] + grid[i][1];
			//	}
			//}
		}

		cout << tc << ". " << dp[n - 1][1] << "\n";
		tc++;
		cin >> n;
	}
}