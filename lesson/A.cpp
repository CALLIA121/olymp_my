#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про цветной дождь

int main() {
    int N, x;
    cin >> N;

    vector <vector<bool>> MS (N, vector <bool>(N, false));
    vector <int> collor (N, 0);

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> x;
            MS[i][j] = x;
        }
    }

    for (int i = 0; i < N; ++i){
        cin >> collor[i];
    }

    int answer = 0;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j <= i; ++j){
            if (MS[i][j] && collor[i] != collor[j]){
                ++answer;
            }
        }
    }    

    cout << answer;

    return 0;
}