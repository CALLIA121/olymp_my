#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 500000

int main() {
    int N, M, min, besti, bestj, dist = 0, x, y, t;
    cin >> N >> M;

    vector <vector<int>> MS (N + 1, vector<int>(N + 1, inf));

    for (int i = 1; i <= M; ++i){
        cin >> x >> y >> t;
        MS[x][y] = t;
        MS[y][x] = t;
    }
    
    vector <int> color (N + 1, 0);
    vector <int> rel (N + 1, 0);


    rel[1] = 0;
    color[1] = 1;

    for (int t = 1; t <= N - 1; ++t){
        min = inf;
        for (int i = 1; i <= N; ++i){
            if (color[i] == 1){
                for (int j = 1; j <= N; ++j){
                    if (color[j] == 0 && MS[i][j] < min){
                        min = MS[i][j];
                        besti = i;
                        bestj = j;
                    }
                }
            }
        }
        color[bestj] = 1;
        rel[bestj] = besti;
        dist += MS[besti][bestj];
    }

    cout << dist << endl;

    vector <int> childs;
    for (int i = 1; i <= N; ++i){
        if (rel[i] == 1){
            childs.push_back(i);
        }
    }

    sort(childs.begin(), childs.end());

    for (auto ch: childs){
        cout << ch << ' ';
    }

    return 0;
}
