#include<iostream>
#include<queue>

using namespace std;

int grid[10001];
int N, M, T;
queue<int> q;

int main() {
    int a;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> a;
            q.push(a);
        }

        cin >> M;

        grid[0] = 1;
        while (!q.empty()) {
            int temp = q.front();
            q.pop();

            for (int j = 0; j < M; j++) {
                if (temp + j > M) break;
                grid[j + temp] += grid[j];
            }
        }

        cout << grid[M] << "\n";

        for (int i = 1; i <= M; i++) {
            grid[i] = 0;
        }
    }


    return 0;
}