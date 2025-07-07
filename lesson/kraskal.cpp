#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b) {return a[2] < b[2];}

int main() {
    int N, M, k, x, y;
    cin >> N;

    vector <vector<int>> MR;
    vector <int> temp (3, 0);

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> x;
            if (x > 0 && i < j){
                M++;
                temp[0] = i;
                temp[1] = j;
                temp[2] = x;
                MR.push_back(temp);
            }
        }
    }

    sort(MR.begin(), MR.end(), comp);
    
    vector <vector<int>> childs (N + 1, vector<int>(0));
    vector <int> color (N + 1, -1);

    for (int i = 1; i <= N; ++i){
        color[i] = i;
    }

    int dist_wheight = 0, dist_edge = 0, i = 0;

    while (dist_edge < N - 1){
        if (color[MR[i][0]] != color[MR[i][1]]){
            dist_edge++;
            dist_wheight += MR[i][2];
            childs[MR[i][0]].push_back(MR[i][1]);
            childs[MR[i][1]].push_back(MR[i][0]);
            int col1 = color[MR[i][0]];
            int col2 = color[MR[i][1]];

            for (int j = 1; j <= N; ++j){
                if (color[j] == col2)
                    color[j] = col1;
            }
        }
        ++i;
    }
    
    cout << dist_wheight << endl;

    sort(childs[1].begin(), childs[1].end());
    for (auto child: childs[1]){
        cout << child << " ";
    }
    return 0;
}
