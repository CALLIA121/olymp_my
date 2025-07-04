#include <iostream>
#include <vector>

#define inf 500000

using namespace std;

// Алгоритм Флоида

void floid(vector<vector<int>>& graf){
    for (int k = 1; k < graf.size(); ++k){
        for (int i = 1; i < graf.size(); ++i){
            for (int j = 1; j < graf.size(); ++j){
                if (graf[i][j] > graf[i][k] + graf[k][j]) {
                    if (i != j)
                        graf[i][j] = graf[i][k] + graf[k][j];
                    else
                        graf[i][j] = 0;
                }
            }
        }
    }
}


int main() {
    int x, y, t, N, M;
    cin >> N >> M;

    vector <vector<int>> MS (N + 1, vector <int>(N + 1, inf));

    for (int i = 1; i <= M; ++i){
        cin >> x >> y >> t;
        MS[x][y] = t;
        MS[y][x] = t;
    }

    floid(MS);

    for (int i = 1; i < MS.size(); ++i){
        for (int j = 1; j < MS.size(); ++j){
            cout << MS[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}