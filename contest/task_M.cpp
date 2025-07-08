#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про королевство DFS

void DFS(int i, vector<vector<bool>>& graf, vector<int>& rel, vector<int>& rast){
    for (int j = 1; j < graf.size(); ++j){
        if (graf[i][j] && rel[j] == -1){
            rast[j] = rast[i] + 1;
            rel[j] = i;
            DFS(j, graf, rel, rast);
        }
    }
}


int main() {
    int x, y, N, v1, v2, k;
    cin >> N >> k >> v1 >> v2;

    vector <vector<bool>> MS (N + 1, vector <bool>(N + 1, false));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> x;
            MS[i][j] = x;
        }
    }

    vector <int> rel (N + 1, -1);   
    vector <int> rast (N + 1, -1);   

    rel[k] = 0;
    rast[k] = 0;
    DFS(k, MS, rel, rast);

    int r1, r2;

    r1 = rast[v1];
    r2 = rast[v2];

    while (v1 != v2){
        // cout << r1 << ' ' << v1 << ", " << r2 << " " << v2 << endl; 
        if (r1 > r2){
            v1 = rel[v1];
            r1 = rast[v1];
        } else {
            v2 = rel[v2];
            r2 = rast[v2];
        }
    }

    cout << v1;

    return 0;
}
