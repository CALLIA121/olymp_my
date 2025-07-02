#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про путь

int main() {
    int x, N, start, end;
    cin >> N >> start >> end;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> x;
            MS[i][j] = x;
        }
    }

    vector <int> P (N + 1, -1);
    vector <int> Rast (N + 1, -1);
    vector <int> queue (N + 1, -1);
    int q_beg, q_end, i;

    q_beg = 0, q_end = 0;
    queue[0] = start;
    Rast[start] = 0;
    P[start] = 0;

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

    cout << Rast[end];

    return 0;
}