#include<iostream>
#include<climits>

using namespace std;

int grid[1001];
int N;

int main() {
    cin >> N;
    
    grid[1] = 1;
    grid[2] = 0;
    grid[3] = 1;
    grid[4] = 1;
    grid[5] = 1;

    for (int i = 6; i <= N; i++) {
        if (grid[i - 1] == 0 || grid[i - 3] == 0 || grid[i - 4] == 0) {
            grid[i] = 1;
        }
    }

    if (grid[N] == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }

    return 0;
}