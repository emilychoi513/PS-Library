#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    k = k-1; // 순서 고려

    int row = 0;
    for(int i=0; i<n; i++){
        for(int j=k; j<m+k; j++){
            if(grid[i][j] == 1){
                row = i - 1;
                break;
            }
        }

        if(row != 0) break;
    }

    if(row == 0) row = n-1;

    for(int j=k; j<m+k; j++){
        grid[row][j] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << grid[i][j] << " ";
        }cout << endl;
    }

    return 0;
}
