#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про компоненты связности DFS

void DFS(int i, vector<vector<bool>>& graf, vector<int>& rel, vector<int>& number, int& answer){
    for (int j = 1; j < graf.size(); ++j){
        if (graf[i][j] && rel[j] == -1){
            number[j] = answer;
            rel[j] = i;
            DFS(j, graf, rel, number, answer);
        }
    }
}

void DFS_start(vector<vector<bool>>& graf, vector<int>& rel, vector<int>& number, int& subGraf){
    subGraf = 0;
    for (int i = 1; i < graf.size(); ++i){
        if (number[i] == -1){
            ++subGraf;
            rel[i] = 0;
            number[i] = subGraf;
            DFS(i, graf, rel, number, subGraf);
        }
    }
}


int main() {
    int x, y, N, M;
    cin >> N;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> x;
            MS[i][j] = x;
        }
    }

    vector <int> rel (N + 1, -1);   
    vector <int> number (N + 1, -1);   
    int ans;

    DFS_start(MS, rel, number, ans);

    cout << ans;

    return 0;
}