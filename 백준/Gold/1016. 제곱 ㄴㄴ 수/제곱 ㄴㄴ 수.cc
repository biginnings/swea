#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

long long a, b;
int dat[1000001];
int result;


int main() {
    cin >> a >> b;

    for (long long i = 2; i * i <= b; i++) {
        long long temp = a / (i * i);

        if (a % (i * i)) temp++;
        
        while (temp * i * i <= b) {
            dat[temp * i * i - a] = 1;
            temp++;
        }
        
    }
    
    for (long long i = 0; i <= b - a; i++) {
        if (dat[i] == 0) result++;
    }

    cout << result;

    return 0;
}
