#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про светофоры

int main() {
    int N, M, fr, to;
    cin >> N >> M;

    vector <vector<int>> graf (N, vector<int>());


    for (int i = 0; i < M; ++i){
        cin >> fr >> to;
        --fr;
        --to;
        graf[fr].push_back(to);
        graf[to].push_back(fr);
    }

    for (int i = 0; i < N; ++i){
        cout << graf[i].size() << " ";
    }

    return 0;
}