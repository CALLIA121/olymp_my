#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N = 8, x1, y1, x2, y2;

    cin >> N >> x1 >> y1 >> x2 >> y2;
    x1--;
    x2--;
    y1--;
    y2--;

    vector<vector<int>> map (N, vector<int>(N, -1));
    vector<pair<int, int>> deltaM = {
        pair( 1,  2),
        pair(-1,  2),
        pair( 1, -2),
        pair(-1, -2),
        pair( 2,  1),
        pair(-2,  1),
        pair( 2, -1),
        pair(-2, -1)
    };
    vector<pair<int, int>> qu;
    int qbeg = 0, qend = 1, xcur, ycur;
    qu.push_back(pair(x1, y1));
    map[y1][x1] = 0;

    while (map[y2][x2] == -1 && qbeg <= qend){
        xcur = qu[qbeg].first;
        ycur = qu[qbeg].second;
        qbeg++;

        for (auto delta: deltaM){
            if (
                ycur + delta.first >= 0  && 
                ycur + delta.first < N   && 
                xcur + delta.second >= 0 && 
                xcur + delta.second < N
            ){
                if (map[ycur + delta.first][xcur + delta.second] == -1){
                    map[ycur + delta.first][xcur + delta.second] = map[ycur][xcur] + 1;
                    qu.push_back(pair(ycur + delta.first, xcur + delta.second));
                    qend++;
                }
            }
        } 

    }

    cout << map[y2][x2] << endl;

    return 0;
}
// 4 4 2 7