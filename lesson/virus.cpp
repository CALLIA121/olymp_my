#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, x1, y1, x2, y2, x;

    cin >> N >> M >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> map (N, vector<int>(N, -1));
    x1--;
    x2--;
    y1--;
    y2--;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> x;
            if (x == 1)
                map[i][j] = -1;
            else
                map[i][j] = 0;
        }
    }

    
    vector<pair<int, int>> deltaM = {
        pair( 1,  0),
        pair(-1,  0),
        pair( 0,  1),
        pair( 0, -1)
    };
    vector<pair<int, int>> qu;
    int qbeg = 0, qend = 1, xcur, ycur;
    qu.push_back(pair(x1, y1));
    map[y1][x1] = 1;

    while (map[y2][x2] == 0 && qbeg <= qend){
        xcur = qu[qbeg].first;
        ycur = qu[qbeg].second;
        qbeg++;

        for (auto delta: deltaM){
            if (
                ycur + delta.first >= 0  && 
                ycur + delta.first < N   && 
                xcur + delta.second >= 0 && 
                xcur + delta.second < M
            ){
                if (map[ycur + delta.first][xcur + delta.second] == 0){
                    map[ycur + delta.first][xcur + delta.second] = map[ycur][xcur] + 1;
                    qu.push_back(pair(xcur + delta.second, ycur + delta.first));
                    qend++;
                }
            }
        } 
    }

    cout << map[y2][x2] - 1 << endl;

    if (map[y2][x2] - 1 != -1){

        xcur = x2; ycur = y2;

        vector <pair<int, int>> way;

        do{
            for (auto delta: deltaM){
                if (
                    ycur + delta.first >= 0  && 
                    ycur + delta.first < N   && 
                    xcur + delta.second >= 0 && 
                    xcur + delta.second < M
                ){
                    if (map[ycur + delta.first][xcur + delta.second] == map[ycur][xcur] - 1){
                        way.push_back(pair(xcur, ycur));
                        xcur = xcur + delta.second; ycur = ycur + delta.first;
                    }
                }
            }
        }while (map[ycur][xcur] != 1);

        way.push_back(pair(xcur, ycur));

        for (int i = way.size() - 1; i >= 0; i--){
            cout << way[i].first + 1 << ' ' << way[i].second + 1 << "; ";
        }
    }
    return 0;
}
