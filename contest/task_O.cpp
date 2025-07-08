#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define inf 100000

// Алгоритм Дейкстры

void deikstra(vector<vector<int>>& graf, int from, int to, int N, vector<int>& rel, vector<int>& dist){
    vector <bool> vizit (N + 1, true);

    int i = to;

    rel[i] = 0;
    dist[i] = 0;

    do {
        vizit[i] = false;
        for (int j = 1; j <= N; ++j){
            if (graf[j][i] > 0 && dist[j] > dist[i] + graf[j][i]){
                dist[j] = dist[i] + graf[j][i];
                rel[j] = i;
            }
        }
        i = -1;
        int min = inf;
        for (int j = 1; j <= N; ++j){
            if (dist[j] < min && vizit[j]){
                i = j;
                min = dist[j];
            }
        }
    } while (i != from && i != -1);
}

int main() {
    int x, y, N, t;
    cin >> N >> x >> y;

    vector <vector<int>> MS (N + 1, vector <int>(N + 1, false));

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> t;
            MS[i][j] = t;
        }
    }

    vector <int> rel (N + 1, -1);   
    vector <int> dist (N + 1, inf);

    deikstra(MS, x, y, N, rel, dist);

    int i = x;

    cout << dist[x] << endl;

    do {
        cout << i << ' ';
        i = rel[i];
    }while (i != 0);

    return 0;
}