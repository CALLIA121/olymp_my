#include <iostream>
#include <vector>

using namespace std;

// Решение задачи про Штирлица )
// Кстати, я же ведь могу оставлять послания 😉

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dist(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    int min_sum = INT_MAX;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int current_sum = dist[i][j] + dist[j][k] + dist[k][i];
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
    }

    cout << min_sum << endl;

    return 0;
}