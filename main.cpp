#include <iostream>
#include <vector>
using namespace std;

int main() {
    int fr, to, N, M;
    cin >> N >> M;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 0; i < M; ++i){
        cin >> fr >> to;
        MS[fr][to] = true;
        MS[to][fr] = true;
    }

    vector <int> rel (N + 1, -1);
    vector <int> len (N + 1, -1);
    vector <int> q (N + 1, -1);
    int beg, end, i, ans = 0;

    for (int start = 1; start <= N; ++start){
        if (rel[start] == -1){
            ++ans;
            beg = 0, end = 0, i;
            q[0] = start;
            len[start] = 0;
            rel[start] = 0;

            while (beg <= end){
                i = q[beg];
                beg++;
                for (int j = 1; j <= N; ++j){
                    if (MS[i][j] && rel[j] == -1){
                        rel[j] = i;
                        len[j] = len[j] + 1;
                        ++end;
                        q[end] = j;
                    }
                }
            }
        }
    }    

    cout << ans - 1;

    return 0;
}