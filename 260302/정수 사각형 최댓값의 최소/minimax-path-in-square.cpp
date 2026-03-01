#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[100][100];
int mx[100][100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    mx[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        mx[i][0] = max(grid[i][0], mx[i-1][0]);
    }
    for(int j=1; j<n; j++){
        mx[0][j] = max(grid[0][j], mx[0][j-1]);
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            int tmp = min(mx[i-1][j], mx[i][j-1]);
            mx[i][j] = max(grid[i][j], tmp);
        }
    }

/*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mx[i][j] << " ";
        }cout << endl;
    }cout << endl;
*/

    cout << mx[n-1][n-1];

    return 0;
}
