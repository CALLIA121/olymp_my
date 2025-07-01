#include <iostream>
#include <vector>
using namespace std;

// Решение задачи про дороги

int main() {
    int N, x, ans = 0;
    cin >> N;


    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> x;
            if (x){
                ans ++;
            }
        }
    }

    cout << ans / 2;

    return 0;
}