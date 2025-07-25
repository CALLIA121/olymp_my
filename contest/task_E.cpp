#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про путь

int main() {
    int x, y, N, v1, v2, k;
    cin >> N >> k >> v1 >> v2;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 1; i <= N - 1; ++i){
        cin >> x >> y;
        MS[x][y] = 1;
        MS[y][x] = 1;
    }

    vector <int> P (N + 1, -1);
    vector <int> Rast (N + 1, -1);
    vector <int> queue (N + 1, -1);
    int q_beg, q_end, i;

    q_beg = 0, q_end = 0;
    queue[0] = k;
    Rast[k] = 0;
    P[k] = 0;

    while (q_beg <= q_end){
        i = queue[q_beg];
        q_beg++;
        for (int j = 1; j <= N; ++j){
            if (MS[i][j] && P[j] == -1){
                P[j] = i;
                Rast[j] = Rast[i] + 1;
                ++q_end;
                queue[q_end] = j;
            }
        }
    }

    int r1, r2;

    r1 = Rast[v1];
    r2 = Rast[v2];

    while (v1 != v2){
        if (r1 > r2){
            v1 = P[v1];
            r1 = Rast[v1];
        } else {
            v2 = P[v2];
            r2 = Rast[v2];
        }
    }

    cout << v1;

    return 0;
}