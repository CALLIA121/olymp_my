#include <iostream>
#include <vector>
using namespace std;

// Решение задачи проверка на двудольность

int main() {
    int x, y, N, M;
    cin >> N >> M;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 0; i < M; ++i){
        cin >> x >> y;
        MS[x][y] = true;
        MS[y][x] = true;
    }

    vector <int> collor (N + 1, 0);
    vector <int> queue (N + 1, -1);
    int q_beg, q_end, i, answer = 1;

    for (int start = 1; start <= N && answer == 1; ++start){
        if (collor[start] == 0){
            q_beg = 0, q_end = 0, i;
            queue[0] = start;
            collor[start] = 1;

            while (q_beg <= q_end && answer == 1){
                i = queue[q_beg];
                q_beg++;
                for (int j = 1; j <= N; ++j){
                    if (MS[i][j]){
                        if (collor[j] == 0) {
                            if (collor[i] == 1)
                                collor[j] = 2;
                            else
                                collor[j] = 1;
                            ++q_end;
                            queue[q_end] = j;
                        } else if (collor[j] == collor[i]){
                            answer = 0;
                            break;
                        }
                    }
                }
            }
        }
    }    

    cout << (answer?"Yes":"No");
    return 0;
}