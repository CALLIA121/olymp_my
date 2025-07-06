#include <iostream>
#include <vector>

#define inf 500000

using namespace std;

// Алгоритм Эйлеера

void DFS_eiler(int i, vector<vector<int>>& graf, int N, vector<int>& answer){
    for (int j = 0; j < graf.size(); ++j){
        if (graf[i][j] > 0){
            graf[i][j] *= -1;
            DFS_eiler(j, graf, N, answer);
        }
    }
    answer.push_back(i);
}


int main() {
    int x, y, t, N, M;
    cin >> N >> M;

    vector <vector<int>> MS (N, vector <int>(N, 0));
    vector <int> answer(0, 0);

    for (int i = 1; i <= M; ++i){
        cin >> x >> y;
        x--; y--;
        MS[x][y] = 1;
        MS[y][x] = 1;
    }

    DFS_eiler(0, MS, N, answer);

    for (int i = 0; i < answer.size(); ++i){
        cout << answer[i] + 1 << " ";
    }

    return 0;
}