#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x, y, N, M;
    cin >> N >> M;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 0; i < M; ++i){
        cin >> x >> y;
        MS[x][y] = true;
        MS[y][x] = true;
    }

    vector <int> P (N + 1, -1);
    vector <int> Rast (N + 1, -1);
    vector <int> queue (N + 1, -1);
    int q_beg, q_end, i, answer = 0;

    for (int start = 1; start <= N; ++start){
        if (P[start] == -1){
            ++answer;
            q_beg = 0, q_end = 0, i;
            queue[0] = start;
            Rast[start] = 0;
            P[start] = 0;

            while (q_beg <= q_end){
                i = queue[q_beg];
                q_beg++;
                for (int j = 1; j <= N; ++j){
                    if (MS[i][j] && P[j] == -1){
                        P[j] = i;
                        Rast[j] = Rast[j] + 1;
                        ++q_end;
                        queue[q_end] = j;
                    }
                }
            }
        }
    }    

    cout << answer - 1;

    return 0;
}