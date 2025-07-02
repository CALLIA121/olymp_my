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
    } while (i != from || i != -1);
}

int main() {
    int x, y, N, M, a, b, c;
    cin >> N >> M;

    vector <vector<int>> MS (N + 1, vector <int>(N + 1, false));

    cin >> x >> y;

    for (int i = 0; i < M; ++i){
        cin >> a >> b >> c;
        MS[a][b] = c;
        MS[b][a] = c;
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