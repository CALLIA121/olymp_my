#include <iostream>
#include <vector>
using namespace std;

// Решение задачи проверка на двудольность DFS

void DFS(int i, vector<vector<int>>& graf, vector<int>& collor, int& answer){
    for (int j = 1; j < graf.size() && answer == 1; ++j){
        if (graf[i][j]){
            if (collor[j] == 0) {
                if (collor[i] == 1)
                    collor[j] = 2;
                else
                    collor[j] = 1;
                DFS(j, graf, collor, answer);
            } else if (collor[j] == collor[i]){
                answer = 0;
            }
        }
        
    }
}

void DFS_start(vector<vector<int>>& graf, vector<int>& collor, int& answer){
    answer = 1;
    for (int i = 1; i < graf.size(); ++i){
        if (collor[i] == 0){
            collor[i] = 1;
            DFS(i, graf, collor, answer);
        }
    }
}

int main() {
    int x, y, N, M;
    cin >> N;

    vector <vector<int>> MS (N + 1, vector <int>(N + 1, 0));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> x;
            MS[i][j] = x;
        }
    }

    vector <int> collor (N + 1, 0);
    int answer;

    DFS_start(MS, collor, answer);

    cout << (answer?"Yes":"No");
    return 0;
}