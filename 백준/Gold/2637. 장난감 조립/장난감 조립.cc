#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Point {
    int id, n;
};

struct Grid {
    unordered_map<int, int> um;
};

int N, T;
int grid[101];
vector<vector<Point>> v(101, vector<Point>());
vector<vector<Grid>> result(101, vector<Grid>(101));
unordered_map<int, int> um;
priority_queue<int, vector<int>, greater<int>> pq;

vector<Grid> dfs(int id) {
    if (um.find(id) != um.end()) {
        return result[id];
    }

    for (int i = 0; i < v[id].size(); i++) {
        vector<Grid> temp = dfs(v[id][i].id);

        for (auto it = temp[0].um.begin(); it != temp[0].um.end(); it++) {
            result[id][0].um[it->first] += (v[id][i].n * it->second);
        }
    }

    um[id] = 1;
    return result[id];
}

int main() {
    cin >> N >> T;

    int a, b, c;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }

    for (int i = 1; i < N; i++) {
        if (v[i].size() == 0) {
            result[i][0].um[i] = 1;
            um[i] = 1;
        }
    }

    result[N] = dfs(N);

    for (auto it = result[N][0].um.begin(); it != result[N][0].um.end(); it++) {
        pq.push(it->first);
    }

    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();

        cout << a << " " << result[N][0].um.find(a)->second << "\n";
    }

    return 0;
}
